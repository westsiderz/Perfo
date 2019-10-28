#include "PerfoTimer.hpp"
#include "CommonDefinitions.hpp"

using namespace XQ::Perfo;

void PerfoTimer::startTimer()
{
	mTimerStartPoint = std::chrono::high_resolution_clock::now();
}

void PerfoTimer::stopTimer()
{
	mTimerEndPoint = std::chrono::high_resolution_clock::now();
}

double PerfoTimer::getTimerResultSeconds()
{
	if (isTimerFinished())
	{
		std::chrono::duration<double> lTimeSpan = 
			std::chrono::duration_cast<std::chrono::duration<double>>(mTimerEndPoint - mTimerStartPoint);

		return lTimeSpan.count();
	}
	else
	{
		return 0.0;
	}
}

double PerfoTimer::getTimerResultMilliseconds()
{
	return getTimerResultSeconds() * cSecondsToMillisecondsRate;
}

double PerfoTimer::getTimerResultMicroseconds()
{
	return getTimerResultSeconds() * cSecondsToMicrosecondsRate;
}

bool XQ::Perfo::PerfoTimer::isTimerFinished()
{
	return (mTimerStartPoint.time_since_epoch().count() > 0 && mTimerEndPoint.time_since_epoch().count() > 0);
}
