#include "Perfo.hpp"
#include "TestingDoDPerformance.hpp"
#include <iostream>
#include <fstream>
#include "TestExecutor.hpp"

using namespace XQ::Perfo::PerfoTestz;

int main(char argc, char ** argv)
{
	TestExecutor lTestExecutor;
	lTestExecutor.executeDoDPerfoTest();
	return 0;
}

void XQ::Perfo::PerfoTestz::TestExecutor::executeDoDPerfoTest()
{
	std::cout << "Data Oriented Design Performance test started...\n";

	std::vector<double> lNoDoDApproachResults;
	std::vector<double> lDoDApproachResults;
	
	XQ::Perfo::PerfoTestz::DoDPerformanceTest lDoDPerformanceTest;
	lDoDPerformanceTest.setNodesCount(cNodesCount);

	lDoDPerformanceTest.fillDataNoDoD();
	lDoDPerformanceTest.fillDataDoD();
	XQ::Perfo::Perfo lPerfo;

	std::cout << "Executing No DoD approach...\n";
	for (int iTrialsCount = cTrialsCountStep; iTrialsCount < cTrialsCount; iTrialsCount += cTrialsCountStep)
	{
		lDoDPerformanceTest.setProcessTrialsCount(iTrialsCount);
		lDoDPerformanceTest.fillDataNoDoD();
		lPerfo.executeTask([&]() {lDoDPerformanceTest.processNodesNoDoD(); });
		lNoDoDApproachResults.emplace_back(lPerfo.getExecutionDurationMilliseconds());
	}
	std::cout << "Executing No DoD approach over! \n";
	
	std::cout << "Executing DoD approach...\n";
	for (int iTrialsCount = cTrialsCountStep; iTrialsCount < cTrialsCount; iTrialsCount += cTrialsCountStep)
	{
		lDoDPerformanceTest.setProcessTrialsCount(iTrialsCount);
		lDoDPerformanceTest.fillDataDoD();
		lPerfo.executeTask([&]() {lDoDPerformanceTest.processNodesDoD(); });
		lDoDApproachResults.emplace_back(lPerfo.getExecutionDurationMilliseconds());
	}
	std::cout << "Executing DoD approach over! \n";

	saveDoDPerfoTestResults(lNoDoDApproachResults, lDoDApproachResults);
	std::cout << "Data saved to file! \n";
}

void XQ::Perfo::PerfoTestz::TestExecutor::saveDoDPerfoTestResults(
	const std::vector<double>& aNoDoDApproachResults, 
	const std::vector<double>& aDoDApproachResults)
{
	std::ofstream aFileWriter{ "./DoDPerformanceTestResults.csv",std::ofstream::out };
	for (int iTrialsCount = cTrialsCountStep; iTrialsCount < cTrialsCount; iTrialsCount += cTrialsCountStep)
	{
		aFileWriter << iTrialsCount << ",";

	}
	aFileWriter << "\n";

	for (auto iVal : aNoDoDApproachResults)
	{
		aFileWriter << iVal << ",";
	}
	aFileWriter << "\n";

	for (auto iVal : aDoDApproachResults)
	{
		aFileWriter << iVal << ",";
	}
	aFileWriter << "\n";

	aFileWriter.close();
}
