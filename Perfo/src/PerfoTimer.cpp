#include "PerfoTimer.hpp"

using namespace XQ::Perfo;

void PerfoTimer::startTimer()
{
	mTimerStartPoint = std::chrono::high_resolution_clock::now();
}

void PerfoTimer::stopTimer()
{
	mTimerEndPoint = std::chrono::high_resolution_clock::now();
}

long long PerfoTimer::getTimerResultSeconds()
{
	if (isTimerFinished())
	{
		std::chrono::duration<std::chrono::seconds> lTimeSpan = 
			std::chrono::duration_cast<std::chrono::seconds>(mTimerEndPoint - mTimerStartPoint);

		return lTimeSpan.count().count();
	}
	else
	{
		return 0;
	}
}

long long PerfoTimer::getTimerResultMilliseconds()
{
	return getTimerResultSeconds() * cSecondsToMillisecondsRate;
}

long long PerfoTimer::getTimerResultMicroseconds()
{
	return getTimerResultSeconds() * cSecondsToMicrosecondsRate;
}

bool XQ::Perfo::PerfoTimer::isTimerFinished()
{
	return (mTimerStartPoint.time_since_epoch().count > 0 && mTimerEndPoint.time_since_epoch().count);
}
