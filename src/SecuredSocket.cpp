//
// Created by Gegel85 on 06/04/2019.
//

#include <cstring>
#include <sstream>
#include <unistd.h>
#include <openssl/err.h>
#include "SecuredSocket.hpp"
#include "Exceptions.hpp"

namespace ChallongeAPI
{
	static char *ossl_strerror(unsigned long error, char *buf, size_t size)
	{
		if(size)
			*buf = '\0';

#ifdef OPENSSL_IS_BORINGSSL
		ERR_error_string_n((uint32_t)error, buf, size);
#else
		ERR_error_string_n(error, buf, size);
#endif

		if (size > 1 && !*buf) {
			strncpy(buf, (error ? "Unknown error" : "No error"), size);
			buf[size - 1] = '\0';
		}
		return buf;
	}

	static const char *SSL_ERROR_to_str(int err)
	{
		switch(err) {
		case SSL_ERROR_NONE:
			return "SSL_ERROR_NONE";
		case SSL_ERROR_SSL:
			return "SSL_ERROR_SSL";
		case SSL_ERROR_WANT_READ:
			return "SSL_ERROR_WANT_READ";
		case SSL_ERROR_WANT_WRITE:
			return "SSL_ERROR_WANT_WRITE";
		case SSL_ERROR_WANT_X509_LOOKUP:
			return "SSL_ERROR_WANT_X509_LOOKUP";
		case SSL_ERROR_SYSCALL:
			return "SSL_ERROR_SYSCALL";
		case SSL_ERROR_ZERO_RETURN:
			return "SSL_ERROR_ZERO_RETURN";
		case SSL_ERROR_WANT_CONNECT:
			return "SSL_ERROR_WANT_CONNECT";
		case SSL_ERROR_WANT_ACCEPT:
			return "SSL_ERROR_WANT_ACCEPT";
#ifdef SSL_ERROR_WANT_ASYNC
		case SSL_ERROR_WANT_ASYNC:
			return "SSL_ERROR_WANT_ASYNC";
#endif
#ifdef SSL_ERROR_WANT_ASYNC_JOB
		case SSL_ERROR_WANT_ASYNC_JOB:
			return "SSL_ERROR_WANT_ASYNC_JOB";
#endif
#ifdef SSL_ERROR_WANT_EARLY
		case SSL_ERROR_WANT_EARLY:
			return "SSL_ERROR_WANT_EARLY";
#endif
		default:
			return "SSL_ERROR unknown";
		}
	}

	std::string SecuredSocket::getSSLError(int lastRet)
	{
		int err = SSL_get_error(this->_connection, lastRet);
		auto sslerror = ERR_get_error();
		char error_buffer[256];

		if ((lastRet < 0) || sslerror) {
			/* If the return code was negative or there actually is an error in the
			   queue */
			int sockerr = SOCKERR;

			if (sslerror)
				ossl_strerror(sslerror, error_buffer, sizeof(error_buffer));
			else if (sockerr && err == SSL_ERROR_SYSCALL)
				strcpy(error_buffer, Socket::getLastSocketError().c_str());
			else {
				strncpy(error_buffer, SSL_ERROR_to_str(err), sizeof(error_buffer));
				error_buffer[sizeof(error_buffer) - 1] = '\0';
			}
			return "SSL error: err." + std::to_string(sslerror) + ", sock." + std::to_string(sockerr) + ", ssl." + std::to_string(err) + ": " + error_buffer;
		}
		return "No error";
	}

	SecuredSocket::SecuredSocket() : Socket()
	{
		//Initialize OpenSSL
		SSL_load_error_strings();
		SSL_library_init();
		this->_ssl_ctx = SSL_CTX_new(SSLv23_client_method());
		this->_connection = nullptr;
	}

	SecuredSocket::~SecuredSocket()
	{
		if (this->isOpen())
			this->disconnect();
		SSL_CTX_free(this->_ssl_ctx);
	}

	void	SecuredSocket::connect(unsigned int ip, unsigned short portno)
	{
		Socket::connect(ip, portno);

		//Create an SSL connection and attach it to the socket
		this->_connection = SSL_new(this->_ssl_ctx);
		SSL_set_fd(this->_connection, this->_sockfd);

		// perform the SSL/TLS handshake with the server - when on the
		// server side, this would use SSL_accept()
		int error = SSL_connect(this->_connection);

		if (error != 1) {
			Socket::disconnect();
			throw ConnectException("SSL handshake failed: " + getSSLError(error));
		}

#ifdef _WIN32
		unsigned long mode = 1;

		if (ioctlsocket(this->_sockfd, FIONBIO, &mode))
			throw SystemCallFailedException("ioctlsocket", getLastSocketError());
#else
		int flags = fcntl(this->_sockfd, F_GETFL, 0);

		if (flags == -1)
			throw SystemCallFailedException("fcntl", strerror(errno));
		flags |= O_NONBLOCK;
		if (fcntl(this->_sockfd, F_SETFL, flags))
			throw SystemCallFailedException("fcntl", strerror(errno));
#endif
	}

	void	SecuredSocket::disconnect()
	{
		if (!this->isOpen())
			throw NotConnectedException("This socket is not connected to a server");

		//Cleanup
		SSL_shutdown(this->_connection);
		Socket::disconnect();
	}

	void	SecuredSocket::send(const std::string &msg)
	{
		unsigned	pos = 0;

		while (pos < msg.length()) {
			int bytes = SSL_write(this->_connection, &msg.c_str()[pos], msg.length() - pos);

			if (bytes < 0)
				throw EOFException(strerror(errno));
			pos += bytes;
		}
	}

	std::string	SecuredSocket::read(int size)
	{
		std::string result;
		char  buffer[1024];
		timeval timeout{1, 0};
		FD_SET rd;
		unsigned time = 11;

		while (size != 0) {
			FD_ZERO(&rd);
			FD_SET(this->_sockfd, &rd);
			timeout.tv_sec = 1;
			timeout.tv_usec = 0;
			switch (select(FD_SETSIZE, &rd, nullptr, nullptr, &timeout)){
			case 0:
				if (result.empty() && (--time))
					continue;
				return result;
			case -1:
				throw EOFException(getLastSocketError());
			default:
				break;
			}

			int bytes = SSL_read(this->_connection, buffer, (static_cast<unsigned>(size) >= sizeof(buffer) - 1) ? (sizeof(buffer) - 1) : (size));

			if (bytes < 0) {
				if (WSAGetLastError() == 10035)
					return result;
				throw EOFException(getLastSocketError());
			}
			result.reserve(result.size() + bytes + 1);
			result.insert(result.end(), buffer, buffer + bytes);
			size -= bytes;
		}
		return result;
	}

	std::string	SecuredSocket::readUntilEOF()
	{
		std::string result;
		unsigned timeout = -1;
		unsigned i = 0;
	start:
		char buffer[4096];
		memset(buffer, 0, sizeof(buffer));
		int bytes = SSL_read(this->_connection, buffer, sizeof(buffer));

		if (bytes <= 0) {
			/* failed SSL_read */
			int err = SSL_get_error(this->_connection, bytes);

			switch(err) {
			case SSL_ERROR_NONE: /* this is not an error */
			case SSL_ERROR_ZERO_RETURN: /* no more data */
				return result;
			case SSL_ERROR_WANT_READ:
			case SSL_ERROR_WANT_WRITE:
				if (WSAGetLastError() == WSAEWOULDBLOCK) {
					i++;
					if (i == timeout) {
						if (result.empty())
							throw EOFException("Request timed out");
						return result;
					}
					usleep(10000);
					goto start;
				}
				throw EOFException(getSSLError(bytes));
			default:
				throw EOFException(getSSLError(bytes));
			}
		}
		i = timeout - 50;
		result += std::string{buffer, buffer + bytes};
		goto start;
	}
}
