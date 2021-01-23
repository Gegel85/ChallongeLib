#ifndef DISCXXORD_EXCEPTION_HPP
#define DISCXXORD_EXCEPTION_HPP


#include <string>
#include "Socket.hpp"

namespace ChallongeAPI
{
	//! @brief Define the BaseException. All exceptions must be inherited from here.
	class BaseException : public std::exception {
	private:
		std::string _msg; //!< Message of the exception

	public:
		//! @brief Constructor of the BaseException
		//! @param msg Exception message
		explicit BaseException(const std::string &&msg) : _msg(msg)	{};

		//! @brief what function
		//! @return char* The message of the exception
		const char *what() const noexcept override {
			return this->_msg.c_str();
		};

		~BaseException() override = default;
	};

	//! @brief Define a NetworkException.
	class NetworkException : public BaseException {
	public:
		//! @brief Create a NetworkException with a message.
		//! @param msg The error message.
		explicit NetworkException(const std::string &&msg) : BaseException(std::move(msg)) {};
	};

	//! @brief Define a SocketCreationErrorException.
	class SocketCreationErrorException : public NetworkException {
	public:
		//! @brief Create a SocketCreationErrorException with a message.
		//! @param msg The error message.
		explicit SocketCreationErrorException(const std::string &&msg) :
		NetworkException("SocketCreationErrorException: " + msg) {};
	};

	//! @brief Define a SystemCallFailedException.
	class SystemCallFailedException : public NetworkException {
	public:
		//! @brief Create a SystemCallFailedException with a message.
		//! @param msg The error message.
		explicit SystemCallFailedException(const std::string &call, const std::string &&msg) :
		NetworkException("SystemCallFailedException: " + call + " failed: " + msg) {};
	};

	//! @brief Define a HostNotFoundException.
	class HostNotFoundException : public NetworkException {
	public:
		//! @brief Create a HostNotFoundException with a message.
		//! @param msg The error message.
		explicit HostNotFoundException(const std::string &&msg) : NetworkException("HostNotFoundException: " + msg) {};
	};

	//! @brief Define a ConnectException.
	class ConnectException : public NetworkException {
	public:
		//! @brief Create a ConnectException with a message.
		//! @param msg The error message.
		explicit ConnectException(const std::string &&msg) : NetworkException("ConnectException: "  + msg) {};
	};

	//! @brief Define a NotConnectedException.
	class NotConnectedException : public NetworkException {
	public:
		//! @brief Create a NotConnectedException with a message.
		//! @param msg The error message.
		explicit NotConnectedException(const std::string &&msg) : NetworkException("NotConnectedException: " + msg) {};
	};

	//! @brief Define a AlreadyOpenedException.
	class AlreadyOpenedException : public NetworkException {
	public:
		//! @brief Create a AlreadyOpenedException with a message.
		//! @param msg The error message.
		explicit AlreadyOpenedException(const std::string &&msg) : NetworkException("AlreadyOpenedException: " + msg) {};
	};

	//! @brief Define a EOFException.
	class EOFException : public NetworkException {
	public:
		//! @brief Create a EOFException with a message.
		//! @param msg The error message.
		explicit EOFException(const std::string &&msg) : NetworkException("EOFException: " + msg) {};
	};

	//! @brief Define a BindFailedException.
	class BindFailedException : public NetworkException {
	public:
		//! @brief Create a BindFailedException with a message.
		//! @param msg The error message.
		explicit BindFailedException(const std::string &&msg) : NetworkException("BindFailedException: " + msg) {};
	};

	//! @brief Define a ListenFailedException.
	class ListenFailedException : public NetworkException {
	public:
		//! @brief Create a ListenFailedException with a message.
		//! @param msg The error message.
		explicit ListenFailedException(const std::string &&msg) : NetworkException("ListenFailedException: " + msg) {};
	};

	//! @brief Define an AcceptFailedException.
	class AcceptFailedException : public NetworkException {
	public:
		//! @brief Create a AcceptFailedException with a message.
		//! @param msg The error message.
		explicit AcceptFailedException(const std::string &&msg) : NetworkException("AcceptFailedException: " + msg) {};
	};

	//! @brief Define a WSAStartupFailedException.
	class WSAStartupFailedException : public NetworkException {
	public:
		//! @brief Create a WSAStartupFailedException with a message.
		//! @param msg The error message.
		explicit WSAStartupFailedException(const std::string &&msg) : NetworkException("WSAStartupFailedException: " + msg) {};
	};

	//! @brief Define a NotImplementedException.
	class NotImplementedException : public BaseException {
	public:
		//! @brief Create a NotImplementedException with a message.
		//! @param msg The error message.
		explicit NotImplementedException() : BaseException("Not implemented") {};
	};

	//! @brief Define a InvalidHTTPAnswerException.
	class InvalidHTTPAnswerException : public NetworkException {
	public:
		//! @brief Create a InvalidHTTPAnswerException with a message.
		//! @param msg The error message.
		explicit InvalidHTTPAnswerException(const std::string &&msg) : NetworkException("InvalidHTTPAnswerException: " + msg) {};
	};

	class CryptFailedException : public NetworkException {
	public:
		//! @param msg The error message.
		explicit CryptFailedException(const std::string &&msg) : NetworkException(msg + ": " + std::to_string(GetLastError())) {};
	};

	class ConnectionTerminatedException : public NetworkException {
	private:
		unsigned _code;

	public:
		//! @param msg The error message.
		ConnectionTerminatedException(const std::string &&msg, unsigned code) : NetworkException("ConnectionTerminatedException: " + msg), _code(code) {};
		unsigned getCode() const { return this->_code; };
	};

	//! @brief Define a HTTPErrorException.
	class HTTPErrorException : public NetworkException {
	private:
		Socket::HttpResponse _response;

	public:
		//! @brief Create a HTTPErrorException with a message.
		//! @param response The response from a Socket.
		HTTPErrorException(const Socket::HttpResponse &response) :
			NetworkException(response.request.host + " responded with code " + std::to_string(response.returnCode) + " " + response.codeName),
			_response(response)
		{}

		//! @brief Return the response of the last Socket Exception.
		//! @return Socket::HttpResponse
		Socket::HttpResponse getResponse() const { return this->_response; }
	};

	class InvalidChallongeURLException : public BaseException {
	public:
		//! @param msg The error message.
		InvalidChallongeURLException(const std::string &url, const std::string &&msg) : BaseException(url + " is not a valid challonge URL: " + msg) {};
		InvalidChallongeURLException(const std::string &&url, const std::string &&msg) : BaseException(url + " is not a valid challonge URL: " + msg) {};
	};
}

#endif //DISCXXORD_EXCEPTION_HPP
