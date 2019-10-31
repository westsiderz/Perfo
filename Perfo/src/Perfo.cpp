#include "Perfo.hpp"
#include "CommonDefinitions.hpp"

using namespace XQ::Perfo;

void XQ::Perfo::Perfo::waitForMs(int aMilliseconds)
{
	mPerformanceTimer.sleepForMs(aMilliseconds);
}

double Perfo::getExecutionDurationSeconds()
{
	return mTaskExecutionDuration;
}

double Perfo::getExecutionDurationMilliseconds()
{
	return mTaskExecutionDuration * cSecondsToMillisecondsRate;
}

double Perfo::getExecutionDurationMicroseconds()
{
	return mTaskExecutionDuration * cSecondsToMicrosecondsRate;
}
