#ifndef XQ_PERFO_PERFO_TESTZ_TEST_EXECUTOR
#define XQ_PERFO_PERFO_TESTZ_TEST_EXECUTOR

namespace XQ
{
	namespace Perfo
	{
		namespace PerfoTestz
		{
			static constexpr const size_t cTrialsCount = 1024;
			static constexpr const size_t cTrialsCountStep = 15;
			static constexpr const size_t cNodesCount = 88;

			class TestExecutor
			{
			public:
				void executeDoDPerfoTest();
				void saveDoDPerfoTestResults(
					const std::vector<double>& aNoDoDApproachResults,
					const std::vector<double>& aDoDApproachResults);
			};
		}
	}
}

#endif // !XQ_PERFO_PERFO_TESTZ_TEST_EXECUTOR

