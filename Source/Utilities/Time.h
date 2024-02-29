#pragma once

namespace Nebula
{
	struct TimeSpan
	{
		int Seconds = 0;
		int Minutes = 0;
		int Hours = 0;
		int Days = 0;
		int Months = 0;
		int Years = 0;

		//Retrieves the current system time.
		static TimeSpan GetCurrentTime();

		//Compares this TimeSpan with another.
		// if return == 0: The timespans are the same.
		// if return == 1: This timespan is ahead of the other.
		// if return == -1: This timespan is behind the other.
		int CompareTo(const TimeSpan& Other);
	};
}