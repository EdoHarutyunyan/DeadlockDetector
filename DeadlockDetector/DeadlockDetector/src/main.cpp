#include <iostream>

#include "ProcessManager.h"

int main()
{
	// Unique id to identify resources and processes
	// Todo: Generate random unique identifires
	uint32_t uniqueId{ 0u };

	ProcessManager::ResourceVector resourceVector;
	resourceVector.emplace_back(std::make_shared<Resource>(uniqueId));
	resourceVector.emplace_back(std::make_shared<Resource>(++uniqueId));
	resourceVector.emplace_back(std::make_shared<Resource>(++uniqueId));
	resourceVector.emplace_back(std::make_shared<Resource>(++uniqueId));
	resourceVector.emplace_back(std::make_shared<Resource>(++uniqueId));
	resourceVector.emplace_back(std::make_shared<Resource>(++uniqueId));

	ProcessManager::ProcessVector processVector;
	processVector.emplace_back(std::make_shared<Process>(++uniqueId));
	processVector.emplace_back(std::make_shared<Process>(++uniqueId));
	processVector.emplace_back(std::make_shared<Process>(++uniqueId));
	processVector.emplace_back(std::make_shared<Process>(++uniqueId));
	processVector.emplace_back(std::make_shared<Process>(++uniqueId));
	processVector.emplace_back(std::make_shared<Process>(++uniqueId));
	processVector.emplace_back(std::make_shared<Process>(++uniqueId));

	const uint32_t idsMatrixSize{ uniqueId + 1 };
	ProcessManager processManager(processVector, resourceVector, idsMatrixSize);

	// Start to connect resources with the processes and detect deadlock
	processManager.Start();

	return 0;
}

