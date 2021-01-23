//
// Created by PinkySmile on 18/01/2021.
//

#ifndef CHALLONGELIB_TIME_HPP
#define CHALLONGELIB_TIME_HPP


#include <ctime>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

namespace ChallongeAPI
{
	class Time {
	private:
		time_t _time;

	public:
		Time() = default;
		Time(tm time);
		Time(const std::string &ISOtimestamp);
		void fromISO(const std::string &ISOtimestamp);
		time_t getTimestamp() const;
		operator time_t() const;
		Time &operator=(const json &val);
	};
}


#endif //CHALLONGELIB_TIME_HPP
