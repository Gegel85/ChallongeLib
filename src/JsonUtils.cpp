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
		if (obj.is_array()) {
			try {
				auto &elem = obj[id];
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
			std::string tmp = obj[id];
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
}