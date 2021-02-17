#pragma once

#include <iostream>
#include <vector>

class DeadlockDetector final
{
public:
	using IdsMatrix = std::vector<std::vector<uint32_t>>;

	explicit DeadlockDetector(uint32_t matrixSize) noexcept;

	void PrepareGraph(uint32_t start, uint32_t destination);
	bool Detect();
	bool IsCyclic(uint32_t v, std::vector<bool>& visitedNodes, std::vector<bool>& recursionStack);

private:
	IdsMatrix m_idsMatrix;
};
