#include "Time.h"

#include <chrono>

namespace Nebula
{
	TimeSpan TimeSpan::GetCurrentTime()
	{
		const std::time_t TimePoint = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::tm Time;

		localtime_s(&Time, &TimePoint);

		TimeSpan ReturnValue;
		ReturnValue.Seconds = Time.tm_sec;
		ReturnValue.Minutes = Time.tm_min;
		ReturnValue.Hours = Time.tm_hour;
		ReturnValue.Days = Time.tm_mday;
		ReturnValue.Months = Time.tm_mon + 1;
		ReturnValue.Years = Time.tm_year + 1900;

		return ReturnValue;
	}

	int TimeSpan::CompareTo(const TimeSpan& Other)
	{
		std::tm TimeA = {};
		TimeA.tm_sec = Seconds;
		TimeA.tm_min = Minutes;
		TimeA.tm_hour = Hours;
		TimeA.tm_mday = Days;
		TimeA.tm_mon = Months;
		TimeA.tm_year = Years - 1900;

		std::tm TimeB = {};
		TimeB.tm_sec = Other.Seconds;
		TimeB.tm_min = Other.Minutes;
		TimeB.tm_hour = Other.Hours;
		TimeB.tm_mday = Other.Days;
		TimeB.tm_mon = Other.Months;
		TimeB.tm_year = Other.Years - 1900;

		const std::time_t TimePointA = std::mktime(&TimeA);
		const std::time_t TimePointB = std::mktime(&TimeB);

		const double Difference = difftime(TimePointA, TimePointB);

		if (Difference == 0.0)
		{
			return 0;
		}
		else
		{
			if (Difference < 0.0)
			{
				return -1;
			}

			return 1;
		}
	}
}
