#include "ProcessManager.h"

ProcessManager::ProcessManager(const ProcessVector& processes, const ResourceVector& resources, const uint32_t matrixSize)
	: m_processes(processes)
	, m_resources(resources)
	, m_deadlockDetectorPtr(std::make_unique<DeadlockDetector>(matrixSize))
{
}

void ProcessManager::Start()
{
	//ConnectProcessAndResource(0, 0);
	//ConnectProcessAndResource(1, 0);
	//ConnectProcessAndResource(1, 1);
	//ConnectProcessAndResource(0, 1);

	ConnectProcessAndResource(0, 0);
	ConnectProcessAndResource(0, 1);
	ConnectProcessAndResource(1, 1);
	ConnectProcessAndResource(2, 1);
	ConnectProcessAndResource(3, 1);
	ConnectProcessAndResource(2, 2);
	ConnectProcessAndResource(3, 4);
	ConnectProcessAndResource(6, 3);
	ConnectProcessAndResource(5, 5);
	ConnectProcessAndResource(6, 5);
	ConnectProcessAndResource(5, 4);
	ConnectProcessAndResource(3, 3);
	ConnectProcessAndResource(4, 3);

	if (m_deadlockDetectorPtr->Detect())
	{
		std::cout << "Deadlock!!!" << std::endl;
	}
}

void ProcessManager::ConnectProcessAndResource(const uint32_t pIndex, const uint32_t rIndex)
{
	if (m_processes[pIndex]->TryToHoldResource(*m_resources[rIndex]))
	{
		m_deadlockDetectorPtr->PrepareGraph(m_resources[rIndex]->GetId(), m_processes[pIndex]->GetId());
	}
	else
	{
		m_deadlockDetectorPtr->PrepareGraph(m_processes[pIndex]->GetId(), m_resources[rIndex]->GetId());
	}
}
