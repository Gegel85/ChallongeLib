//
// Created by Gegel85 on 06/04/2019.
//

#ifndef CHALLONGESOKU_SECUREDSOCKET_HPP
#define CHALLONGESOKU_SECUREDSOCKET_HPP


#include <openssl/ssl.h>
#include "Socket.hpp"

namespace ChallongeAPI
{
	class SecuredSocket : public Socket {
	protected:
		SSL_CTX *_ssl_ctx;
		SSL	*_connection;

		std::string getSSLError(int lastRet);

	public:
		using Socket::connect;

		SecuredSocket();
		~SecuredSocket();
		void		connect(unsigned int ip, unsigned short portno) override;
		void		disconnect() override;
		void		send(const std::string &) override;
		std::string	read(int size) override;
		std::string	readUntilEOF() override;
	};
}


#endif //CHALLONGESOKU_SECUREDSOCKET_HPP
