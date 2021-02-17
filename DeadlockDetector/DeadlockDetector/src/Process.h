#pragma once
#include <cstdint>

class Resource;

class Process final
{
public:
	explicit Process(uint32_t id) noexcept;

	bool TryToHoldResource(Resource& resource) noexcept;
	bool WaitResource(const Resource& resource) noexcept;
	void SetId(uint32_t id) noexcept;
	uint32_t GetId() const noexcept;

private:
	uint32_t m_id;
};

