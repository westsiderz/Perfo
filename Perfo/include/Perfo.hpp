#ifndef XQ_PERFO_PERFO_HPP
#define XQ_PERFO_PERFO_HPP

#include "PerfoTimer.hpp"

namespace XQ
{
	namespace Perfo
	{
		class Perfo
		{
		public:
			template<typename Method>
			void executeTask(Method aMethodToExecute);

			void waitForMs(int aMilliseconds);
			double getExecutionDurationSeconds();
			double getExecutionDurationMilliseconds();
			double getExecutionDurationMicroseconds();

		private:
			PerfoTimer mPerformanceTimer;
			double mTaskExecutionDuration{ 0 };
		};

		template<typename Method>
		inline void Perfo::executeTask(Method aMethodToExecute)
		{
			mPerformanceTimer.startTimer();
			aMethodToExecute();
			mPerformanceTimer.stopTimer();
			mTaskExecutionDuration = mPerformanceTimer.getTimerResultSeconds();
		}
	}
}
#endif // !XQ_PERFO_PERFO_HPP

