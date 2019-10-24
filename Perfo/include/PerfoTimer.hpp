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
			long long getTimerResultSeconds();
			long long getTimerResultMilliseconds();
			long long getTimerResultMicroseconds();

		private:
			bool isTimerFinished();

		private:
			static constexpr const int cSecondsToMillisecondsRate = 1000;
			static constexpr const int cSecondsToMicrosecondsRate = 1000000;
			std::chrono::high_resolution_clock::time_point mTimerStartPoint;
			std::chrono::high_resolution_clock::time_point mTimerEndPoint;
		};
	}
}
#endif // !XQ_PERFO_PERFO_TIMER_HPP