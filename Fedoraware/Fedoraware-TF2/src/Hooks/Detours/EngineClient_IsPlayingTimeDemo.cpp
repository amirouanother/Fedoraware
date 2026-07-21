#include "../Hooks.h"

MAKE_HOOK(EngineClient_IsPlayingTimeDemo, Utils::GetVFuncPtr(I::EngineClient, 78), bool, __fastcall,
		  void* ecx, void* edx)
{
	static uintptr_t dwInterpolateServerEntities = S::C_BaseEntity_InterpolateServerEntities();

	if (Vars::Misc::DisableInterpolation.Value)
	{
		if (reinterpret_cast<uintptr_t>(_ReturnAddress()) == (dwInterpolateServerEntities + 0xB8))
		{
			return true;
		}
	}

	return Hook.Original<FN>()(ecx, edx);
}