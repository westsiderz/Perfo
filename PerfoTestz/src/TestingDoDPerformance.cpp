#include "TestingDoDPerformance.hpp"

void XQ::Perfo::PerfoTestz::DoDPerformanceTest::fillDataNoDoD()
{
	mNodesNoDoD.positions.clear();
	mNodesNoDoD.color.clear();
	mNodesNoDoD.indexes.clear();

	for (size_t iNodesCount = 0; iNodesCount < mNodesCount; ++iNodesCount)
	{
		mNodesNoDoD.positions.emplace_back(PosInfo{});
		mNodesNoDoD.color.emplace_back(0.1f);
		mNodesNoDoD.indexes.emplace_back(1);
	}
}

void XQ::Perfo::PerfoTestz::DoDPerformanceTest::processNodesNoDoD()
{
	for (size_t iTimes = 0; iTimes < mProcessTrialsCount; ++iTimes)
	{
		std::vector<PosInfo>& lPosInfoVector = mNodesNoDoD.positions;
		for (size_t iNodesCount = 0; iNodesCount < mNodesCount; ++iNodesCount)
		{
			lPosInfoVector.at(iNodesCount).position += lPosInfoVector.at(iNodesCount).velocity * 1.1f;
		}
	}
}

void XQ::Perfo::PerfoTestz::DoDPerformanceTest::fillDataDoD()
{
	mNodesDoD.positions.clear();
	mNodesDoD.velocities.clear();
	mNodesDoD.color.clear();
	mNodesDoD.indexes.clear();

	for (size_t iNodesCount = 0; iNodesCount < mNodesCount; ++iNodesCount)
	{
		mNodesDoD.positions.emplace_back(1.2f);
		mNodesDoD.velocities.emplace_back(3.4f);
		mNodesDoD.color.emplace_back(0.1f);
		mNodesDoD.indexes.emplace_back(1);
	}
}

void XQ::Perfo::PerfoTestz::DoDPerformanceTest::processNodesDoD()
{
	for (size_t iTimes = 0; iTimes < mProcessTrialsCount; ++iTimes)
	{
		for (size_t iNodesCount = 0; iNodesCount < mNodesCount; ++iNodesCount)
		{
			mNodesDoD.positions.at(iNodesCount) += mNodesDoD.velocities.at(iNodesCount) * 1.1f;
		}
	}
}

void XQ::Perfo::PerfoTestz::DoDPerformanceTest::setProcessTrialsCount(size_t aTrialsCount)
{
	mProcessTrialsCount = aTrialsCount;
}

void XQ::Perfo::PerfoTestz::DoDPerformanceTest::setNodesCount(size_t aNodesCount)
{
	mNodesCount = aNodesCount;
}
