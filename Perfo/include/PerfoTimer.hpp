#ifndef XQ_PERFO_PERFO_TIMER_HPP
#define XQ_PERFO_PERFO_TIMER_HPP

#include <chrono>

namespace XQ
{
	namespace Perfo
	{
		class PerfoTimer
		{
		public:
			void startTimer();
			void stopTimer();
			double getTimerResultSeconds();
			double getTimerResultMilliseconds();
			double getTimerResultMicroseconds();

		private:
			bool isTimerFinished();

		private:
			static constexpr const double cSecondsToMillisecondsRate = 1000.0;
			static constexpr const double cSecondsToMicrosecondsRate = 1000000.0;
			std::chrono::high_resolution_clock::time_point mTimerStartPoint;
			std::chrono::high_resolution_clock::time_point mTimerEndPoint;
		};
	}
}
#endif // !XQ_PERFO_PERFO_TIMER_HPP