#include "TestingDoDPerformance.hpp"
#include <random>

void XQ::Perfo::PerfoTestz::fillDataNoDoD()
{
	for (size_t iNodesCount = 0; iNodesCount < cRandomNodesCount; ++iNodesCount)
	{
		mNodesNoDoD.positions.emplace_back(PosInfo{ {rand(), rand(), rand()}, {rand(), rand(), rand()} });
	}
}

void XQ::Perfo::PerfoTestz::processNodesNoDoD()
{
	for (size_t iTimes = 0; iTimes < cProcessTrialsCount; ++iTimes)
	{
		std::vector<PosInfo>& lPosInfoVector = mNodesNoDoD.positions;
		for (size_t iNodesCount = 0; iNodesCount < cRandomNodesCount; ++iNodesCount)
		{
			for (size_t iPositionIndex = 0; iPositionIndex < 3; ++iPositionIndex)
			{
				lPosInfoVector.at(iNodesCount).position.at(iPositionIndex) += lPosInfoVector.at(iNodesCount).velocity.at(iPositionIndex) * rand();
			}
		}
	}
}

void XQ::Perfo::PerfoTestz::fillDataDoD()
{
	for (size_t iNodesCount = 0; iNodesCount < cRandomNodesCount; ++iNodesCount)
	{
		mNodesDoD.positions.emplace_back(std::vector<int>{rand(), rand(), rand()});
		mNodesDoD.velocities.emplace_back(std::vector<int>{rand(), rand(), rand()});
	}
}

void XQ::Perfo::PerfoTestz::processNodesDoD()
{
	for (size_t iTimes = 0; iTimes < cProcessTrialsCount; ++iTimes)
	{
		for (size_t iNodesCount = 0; iNodesCount < cRandomNodesCount; ++iNodesCount)
		{
			for (size_t iPositionIndex = 0; iPositionIndex < 3; ++iPositionIndex)
			{
				mNodesDoD.positions.at(iNodesCount).at(iPositionIndex) += mNodesDoD.velocities.at(iNodesCount).at(iPositionIndex) * rand();
			}
		}
	}
}
