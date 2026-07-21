#include "../Hooks.h"

MAKE_HOOK(C_BaseEntity_MoveToLastReceivedPosition, S::C_BaseEntity_MoveToLastReceivedPosition(), void, __fastcall,
	void* ecx, void* edx, bool force)
{
	return Hook.Original<FN>()(ecx, edx, force);
}
