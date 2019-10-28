#include "Perfo.hpp"
#include "TestingDoDPerformance.hpp"
#include <iostream>

int main(char argc, char ** argv)
{
	std::cout << "Performance test started...\n";
	XQ::Perfo::PerfoTestz::fillDataNoDoD();
	XQ::Perfo::PerfoTestz::fillDataDoD();
	XQ::Perfo::Perfo lPerfo;
	std::cout << "Executing No DoD approach...\n";
	lPerfo.executeTask([]() {XQ::Perfo::PerfoTestz::processNodesNoDoD(); });
	std::cout << "Executing No DoD approach over! The function was executed for " << lPerfo.getExecutionDurationMilliseconds() << "ms.\n";
	std::cout << "Executing DoD approach...\n";
	lPerfo.executeTask([]() {XQ::Perfo::PerfoTestz::processNodesNoDoD(); });
	std::cout << "Executing DoD approach over! The function was executed for " << lPerfo.getExecutionDurationMilliseconds() << "ms.\n";
	return 0;
}

