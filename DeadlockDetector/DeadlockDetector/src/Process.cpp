#include "Process.h"
#include "Resource.h"

Process::Process(const uint32_t id) noexcept
	: m_id(id)
{
}

bool Process::TryToHoldResource(Resource& resource) noexcept
{
	if (WaitResource(resource))
	{
		return false;
	}

	resource.Lock();
	return true;
}

bool Process::WaitResource(const Resource& resource) noexcept
{
	return resource.IsLocked();
}

void Process::SetId(const uint32_t id) noexcept
{
	m_id = id;
}

uint32_t Process::GetId() const noexcept
{
	return m_id;
}
