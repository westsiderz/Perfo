/*
*	This performance tests is testing DoD approach performance.
*	The test idea is taken from here:
*	http://www.dataorienteddesign.com/dodbook/node9.html#SECTION00940000000000000000
*/

#ifndef XQ_PERFO_PERFO_TESTZ_TESTING_DOD_PERFORMANCE
#define XQ_PERFO_PERFO_TESTZ_TESTING_DOD_PERFORMANCE

#include <vector>
namespace XQ
{
	namespace Perfo
	{
		namespace PerfoTestz
		{

			struct PosInfo
			{
				float position;
				float velocity;
				PosInfo() :
					position{ 1.2f },
					velocity{ 3.4f }{}
				
			};

			struct NodeNoDoD
			{
				std::vector<PosInfo> positions;
				std::vector<float> color;
				std::vector<int> indexes;
			};

			struct NodeDoD
			{
				std::vector< float > positions;
				std::vector< float > velocities;
				std::vector<float> color;
				std::vector<int> indexes;
			};

			class DoDPerformanceTest 
			{	
			public:
				void fillDataNoDoD();
				void processNodesNoDoD();
				void fillDataDoD();
				void processNodesDoD();
				void setProcessTrialsCount(size_t aTrialsCount);
				void setNodesCount(size_t aNodesCount);

			private:
				size_t mProcessTrialsCount = 100;
				size_t mNodesCount = 100;
				NodeNoDoD mNodesNoDoD;
				NodeDoD mNodesDoD;
			};
		}
	}
}

#endif // !XQ_PERFO_PERFO_TESTZ_TESTING_DOD_PERFORMANCE
