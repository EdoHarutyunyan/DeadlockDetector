#include "Resource.h"

Resource::Resource(const uint32_t id) noexcept
	: m_id(id)
{
}

void Resource::Lock() noexcept
{
	m_lock = true;
}

void Resource::Unlock() noexcept
{
	m_lock = false;
}

bool Resource::IsLocked() const noexcept
{
	return m_lock;
}

void Resource::SetId(const uint32_t id) noexcept
{
	m_id = id;
}

uint32_t Resource::GetId() const noexcept
{
	return m_id;
}