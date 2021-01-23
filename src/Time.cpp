//
// Created by PinkySmile on 18/01/2021.
//

#include <iomanip>
#include "Time.hpp"

namespace ChallongeAPI
{
	Time::Time(tm time) :
		_time(std::mktime(&time))
	{
	}

	Time::Time(const std::string &ISOtimestamp)
	{
		this->fromISO(ISOtimestamp);
	}

	time_t Time::getTimestamp() const
	{
		return this->_time;
	}

	Time::operator time_t() const
	{
		return this->getTimestamp();
	}

	void Time::fromISO(const std::string &ISOtimestamp)
	{
		int tzh = 0, tzm = 0;
		int y,M,d,h,m;
		float s;
		tm time;

		if (6 < sscanf(ISOtimestamp.c_str(), "%d-%d-%dT%d:%d:%f%d:%dZ", &y, &M, &d, &h, &m, &s, &tzh, &tzm))
			if (tzh < 0)
				tzm = -tzm;    // Fix the sign on minutes.

		time.tm_year = y - 1900; // Year since 1900
		time.tm_mon = M - 1;     // 0-11
		time.tm_mday = d;        // 1-31
		time.tm_hour = h;        // 0-23
		time.tm_min = m;         // 0-59
		time.tm_sec = (int)s;    // 0-61 (0-60 in C++11)
		this->_time = std::mktime(&time);
		this->_time += tzm * 60 + tzh * 3600;
	}

	Time &Time::operator=(const json &val)
	{
		this->fromISO(val);
		return *this;
	}
}