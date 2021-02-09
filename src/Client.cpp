//
// Created by PinkySmile on 17/01/2021.
//

#include <iostream>
#include "base64.hpp"
#include "Client.hpp"
#include "Exceptions.hpp"
#include "Tournament.hpp"

namespace ChallongeAPI
{
	Client::Client(const std::string &username, const std::string &apikey)
	{
		this->setCredentials(username, apikey);
	}

	void Client::setCredentials(const std::string &username, const std::string &apikey)
	{
		auto concat = username + ":" + apikey;
		std::string result = base64::encode({concat.c_str(), concat.c_str() + concat.size()});

		this->_authStr = "Basic " + result;
	}

	Socket::HttpResponse Client::makeRawRequest(const std::string &method, const std::string &path, const std::string &data)
	{
		Socket::HttpRequest request;

		std::cout << "Making request " << method << " to https://" << Client::_host << Client::_basePath << path << std::endl;
		request.httpVer = "HTTP/1.1";
		request.method = method;
		request.path = Client::_basePath + path;
		request.host = Client::_host;
		request.portno = Client::_port;
		request.header["Authorization"] = this->_authStr;
		request.body = data;
		return this->_sock.makeHttpRequest(request);
	}

	std::shared_ptr<Tournament> Client::getTournamentById(unsigned long id)
	{
		if (this->_building && this->_building->getId() == id)
			return this->_building;
		return this->_cachedTournaments.at(id);
	}

	std::shared_ptr<Tournament> Client::getTournamentByName(const std::string &name)
	{
		std::string id = name;

		if (id.find('/') != std::string::npos || id.find('&') != std::string::npos || id.find('?') != std::string::npos) {
			if (id.find("//") != std::string::npos)
				id = id.substr(id.find("//") + 2);
			if (id.find('/') == std::string::npos)
				throw InvalidChallongeURLException(name, "This doesn't point to any page");

			std::string host = id.substr(0, id.find('/'));
			std::string page = id.substr(id.find('/') + 1);
			std::string subdomain;

			id.clear();
			if (page.empty())
				throw InvalidChallongeURLException(name, "This doesn't point to any page");
			while (page.back() == '/')
				page.pop_back();
			if (page.empty())
				throw InvalidChallongeURLException(name, "This doesn't point to any page");
			while (page.find('/') != std::string::npos)
				page = page.substr(page.find('/') + 1);
			if (host.size() < strlen("challonge.com"))
				throw InvalidChallongeURLException(name, "Not from challonge.com");
			if (host.size() > strlen("challonge.com") && host[host.size() - strlen("challonge.com") - 1] != '.')
				throw InvalidChallongeURLException(name, "Not from challonge.com");
			if (host.substr(host.size() - strlen("challonge.com")) != "challonge.com")
				throw InvalidChallongeURLException(name, "Not from challonge.com");
			if (host.size() != strlen("challonge.com"))
				subdomain = host.substr(0, host.size() - strlen("challonge.com") - 1);
			if (!subdomain.empty())
				id = subdomain + "-";
			id += page;
		}

		try {
			auto result = this->makeRawRequest("GET", "/tournaments/" + id + ".json?include_participants=1&include_matches=1", "");
			auto parsed = json::parse(result.body);
			auto tournament = this->_building = std::make_shared<Tournament>(*this);

			this->_cachedTournaments[tournament->getId()] = tournament;
			*tournament = parsed;
			this->_building = nullptr;
			return tournament;
		} catch (nlohmann::detail::exception &e) {
			throw InvalidChallongeURLException(name, Client::_host + ("/tournaments/" + id) + ".json?include_participants=1&include_matches=1: " + e.what());
		} catch (InvalidHTTPAnswerException &e) {
			throw InvalidChallongeURLException(name, Client::_host + ("/tournaments/" + id) + ".json?include_participants=1&include_matches=1: " + e.what());
		}
	}
}