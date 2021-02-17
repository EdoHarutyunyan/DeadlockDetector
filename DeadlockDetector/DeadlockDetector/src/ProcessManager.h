#pragma once

#include <vector>
#include <iostream>

#include "Process.h"
#include "Resource.h"
#include "DeadlockDetector.h"

class ProcessManager final
{
public:
	using ResourceVector = std::vector<std::shared_ptr<Resource>>;
	using ProcessVector = std::vector<std::shared_ptr<Process>>;

	ProcessManager(const ProcessVector& processes, const ResourceVector& resources, uint32_t matrixSize);

	void Start();
	void ConnectProcessAndResource(uint32_t pIndex, uint32_t rIndex);

private:
	ProcessVector m_processes;
	ResourceVector m_resources;
	std::unique_ptr<DeadlockDetector> m_deadlockDetectorPtr;
};

