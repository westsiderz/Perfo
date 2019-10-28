#include "Perfo.hpp"
#include "CommonDefinitions.hpp"

using namespace XQ::Perfo;

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
