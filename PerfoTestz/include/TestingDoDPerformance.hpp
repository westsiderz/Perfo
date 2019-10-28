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
				std::vector<int> position;
				std::vector<int> velocity;
				
			};

			struct NodeNoDoD
			{
				std::vector<PosInfo> positions;
				std::vector<float> color;
				std::vector<int> indexes;
			};

			struct NodeDoD
			{
				std::vector< std::vector<int> > positions;
				std::vector< std::vector<int> > velocities;
				std::vector<float> color;
				std::vector<int> indexes;
			};

			static constexpr const size_t cProcessTrialsCount = 1000;
			static constexpr const size_t cRandomNodesCount = 1000;
			static NodeNoDoD mNodesNoDoD;
			static NodeDoD mNodesDoD;

			void fillDataNoDoD();
			void processNodesNoDoD();
			void fillDataDoD();
			void processNodesDoD();
		}
	}
}

#endif // !XQ_PERFO_PERFO_TESTZ_TESTING_DOD_PERFORMANCE
