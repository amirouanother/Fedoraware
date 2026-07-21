#include "../Hooks.h"

//Credits: myzarfin/spook953

MAKE_HOOK(UTIL_TraceLine, S::UTIL_TraceLine(), void, __cdecl,
		  void* ecx, void* edx, Vector* vecAbsStart, Vector* vecAbsEnd, unsigned int mask, CTraceFilter* pFilter, CGameTrace* ptr)
{
	static auto dwDisplayDamageFeedback = S::DisplayDamageFeedback();

	if (reinterpret_cast<uintptr_t>(_ReturnAddress()) == dwDisplayDamageFeedback && pFilter)
	{
		*reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(pFilter) + 0x2C) = 1.0f;
		return;
	}

	return Hook.Original<FN>()(ecx, edx, vecAbsStart, vecAbsEnd, mask, pFilter, ptr);
}
