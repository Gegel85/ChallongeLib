//
// Created by PinkySmile on 18/01/2021.
//

#ifndef CHALLONGELIB_JSONUTILS_HPP
#define CHALLONGELIB_JSONUTILS_HPP


#include <string>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

namespace ChallongeAPI
{
	template<typename type>
	void getFromJson(type &val, const std::string &id, const json &obj)
	{
		try {
			val = obj[id];
		} catch (std::exception &e) {
			std::cerr << "Error getting element " << id << " from " << obj.dump(4) << ": " << e.what() << std::endl;
			throw;
		}
	}

	template<>
	void getFromJson(float &val, const std::string &id, const json &obj);

	template<typename type>
	void getFromJson(std::optional<type> &val, const std::string &id, const json &obj)
	{
		try {
			if (obj.contains(id) && !obj[id].is_null()) {
				type tmp;

				getFromJson(tmp, id, obj);
				val = tmp;
			}
		} catch (std::exception &e) {
			std::cerr << "Error getting element " << id << " from " << obj.dump(4) << ": " << e.what() << std::endl;
			throw;
		}
	}

	template<>
	void getFromJson(std::optional<std::pair<int, int>> &val, const std::string &id, const json &obj);

	template<typename type>
	void getFromJson(std::vector<type> &val, const std::string &id, const json &obj)
	{
		try {
			auto &elem = obj[id];
			std::vector<type> buff;

			buff.reserve(elem.size());
			for (auto &e : elem)
				buff.emplace_back() = e;
			val.swap(buff);
		} catch (std::exception &e) {
			std::cerr << "Error getting element " << id << " from " << obj.dump(4) << ": " << e.what() << std::endl;
			throw;
		}
	}

	template<typename type, typename ...Args>
	void getFromJson(std::vector<std::shared_ptr<type>> &val, const std::string &id, const json &obj, Args &...args)
	{
		try {
			auto &elem = obj[id];
			std::vector<std::shared_ptr<type>> buff;

			buff.reserve(elem.size());
			for (auto &e : elem)
				buff.push_back(std::make_shared<type>(args..., e));
			val.swap(buff);
		} catch (std::exception &e) {
			std::cerr << "Error getting element " << id << " from " << obj.dump(4) << ": " << e.what() << std::endl;
			throw;
		}
	}

	template<>
	void getFromJson(std::vector<size_t> &val, const std::string &id, const json &obj);
}


#endif //CHALLONGELIB_JSONUTILS_HPP
