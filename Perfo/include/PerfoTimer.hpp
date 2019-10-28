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
			std::chrono::high_resolution_clock::time_point mTimerStartPoint;
			std::chrono::high_resolution_clock::time_point mTimerEndPoint;
		};
	}
}
#endif // !XQ_PERFO_PERFO_TIMER_HPP