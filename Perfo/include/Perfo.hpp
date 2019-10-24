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

		private:
			PerfoTimer mPerformanceTimer;
		};

		template<typename Method>
		inline void Perfo::executeTask(Method aMethodToExecute)
		{
		}
	}
}
#endif // !XQ_PERFO_PERFO_HPP

