#pragma once

#include <cstdint>

class Resource final
{
public:
	explicit Resource(uint32_t id) noexcept;

	void Lock() noexcept;
	void Unlock() noexcept;
	bool IsLocked() const noexcept;
	void SetId(uint32_t id) noexcept;
	uint32_t GetId() const noexcept;

private:
	uint32_t m_id{ 0u };
	bool m_lock{ false };
};

