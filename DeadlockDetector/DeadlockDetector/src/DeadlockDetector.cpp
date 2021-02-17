#include "DeadlockDetector.h"

DeadlockDetector::DeadlockDetector(const uint32_t matrixSize) noexcept
{
	m_idsMatrix.resize(matrixSize);
}

bool DeadlockDetector::Detect()
{
	std::vector<bool> visitedNodes(m_idsMatrix.size(), false);
	std::vector<bool> recursionStack(m_idsMatrix.size(), false);

	for (size_t i = 0; i < m_idsMatrix.size(); i++)
	{
		if (IsCyclic(i, visitedNodes, recursionStack))
		{
			return true;
		}
	}

	return false;
}

bool DeadlockDetector::IsCyclic(const uint32_t currentNode, std::vector<bool>& visitedNodes, std::vector<bool>& recursionStack)
{
	if (visitedNodes[currentNode] == false)
	{
		// Mark the current node as visited and part of recursion stack
		visitedNodes[currentNode] = true;
		recursionStack[currentNode] = true;

		for (auto i = m_idsMatrix[currentNode].begin(); i != m_idsMatrix[currentNode].end(); ++i)
		{
			if (!visitedNodes[*i] && IsCyclic(*i, visitedNodes, recursionStack))
			{
				return true;
			}

			if (recursionStack[*i])
			{
				return true;
			}
		}
	}

	// Remove the vertex from recursion stack
	recursionStack[currentNode] = false;

	return false;
}

void DeadlockDetector::PrepareGraph(const uint32_t start, const uint32_t destination)
{
	m_idsMatrix[start].push_back(destination);
}
