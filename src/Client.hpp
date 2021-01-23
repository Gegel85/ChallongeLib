//
// Created by PinkySmile on 17/01/2021.
//

#ifndef CHALLONGELIB_CLIENT_HPP
#define CHALLONGELIB_CLIENT_HPP


#include <string>
#include <vector>
#include <memory>
#include "Socket.hpp"
#include "SecuredSocket.hpp"

namespace ChallongeAPI
{
	class Tournament;

	class Client {
	private:
		SecuredSocket _sock;
		std::string _authStr;
		std::shared_ptr<Tournament> _building;
		std::map<unsigned long, std::shared_ptr<Tournament>> _cachedTournaments;
		static constexpr const char *_basePath = "/v1";
		static constexpr const char *_host = "api.challonge.com";
		static constexpr unsigned short _port = 443;

	public:
		Client() = default;
		Client(const Client &) = delete;
		Client(const Client &&) = delete;
		Client &operator=(const Client &) = delete;
		Client &operator=(const Client &&) = delete;
		Client(const std::string &username, const std::string &apikey);
		Tournament &getTournamentById(unsigned long id);
		Tournament &getTournamentByName(const std::string &name);
		Socket::HttpResponse makeRawRequest(const std::string &method, const std::string &path, const std::string &data);
		void setCredentials(const std::string &username, const std::string &apikey);
	};
}


#endif //CHALLONGELIB_CLIENT_HPP
