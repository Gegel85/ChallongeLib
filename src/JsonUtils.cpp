//
// Created by PinkySmile on 18/01/2021.
//

#include "JsonUtils.hpp"

namespace ChallongeAPI
{
	template<>
	void getFromJson(float &val, const std::string &id, const json &obj)
	{
		try {
			if (obj[id].is_number())
				val = obj[id];
			else
				val = std::stof(obj[id].get<std::string>());
		} catch (std::exception &e) {
			std::cerr << "Error getting element " << id << " from " << obj.dump(4) << ": " << e.what() << std::endl;
			throw;
		}
	}

	template<>
	void getFromJson(std::vector<size_t> &val, const std::string &id, const json &obj)
	{
		auto &elem = obj[id];

		if (elem.is_array()) {
			try {
				std::vector<size_t> buff;

				buff.reserve(elem.size());
				for (auto &e : elem)
					buff.emplace_back() = e;
				val.swap(buff);
			} catch (std::exception &e) {
				std::cerr << "Error getting element " << id << " from " << obj.dump(4) << ": " << e.what() << std::endl;
				throw;
			}
			return;
		}

		val.clear();
		try {
			std::string tmp = elem;
			size_t pos;

			if (tmp.empty())
				return;
			do {
				pos = tmp.find(',');
				val.push_back(std::stoull(tmp.substr(0, pos)));
				if (pos != std::string::npos)
					tmp = tmp.substr(pos + 1);
			} while (pos != std::string::npos);
		} catch (std::exception &e) {
			std::cerr << "Error getting element " << id << " from " << obj.dump(4) << ": " << e.what() << std::endl;
			throw;
		}
	}


	template<>
	void getFromJson(std::optional<std::pair<int, int>> &val, const std::string &id, const json &obj)
	{
		if (!obj.contains(id) || obj[id].is_null() || obj[id].empty()) {
			val.reset();
			return;
		}

		auto &elem = obj[id];
		std::pair<int, int> v;

		if (elem.is_array()) {
			try {
				if (elem.size() != 2)
					throw std::invalid_argument("Size was not 2 (" + std::to_string(elem.size()) + ")");
				v.first = elem[0];
				v.second = elem[1];
				val = v;
			} catch (std::exception &e) {
				std::cerr << "Error getting element " << id << " from " << obj.dump(4) << ": " << e.what() << std::endl;
				throw;
			}
			return;
		}

		size_t pos = 0;
		std::string tmp = elem;

		if (tmp.empty()) {
			val.reset();
			return;
		}
		v.first = std::stoi(tmp, &pos);
		v.second = std::stoi(tmp.substr(pos + 1));
		val = v;
	}
}