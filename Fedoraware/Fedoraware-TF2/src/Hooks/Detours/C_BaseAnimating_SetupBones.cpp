#include "../Hooks.h"
#include "../HookManager.h"



MAKE_HOOK(C_BaseAnimating_SetupBones, S::CBaseAnimating_SetupBones(), bool, __fastcall,
	void* ecx, void* edx, matrix3x4* pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
{
	//const auto g_iModelBoneCounter = **reinterpret_cast<unsigned long**>(g_Pattern.Find(L"client.dll", L"A1 ? ? ? ? 09 B3 ? ? ? ? 89 83 ? ? ? ? 8B 83 ? ? ? ? 23 C6 3B C6 0F 84 ? ? ? ? 8B 35 ? ? ? ? 8B CE 8B 06 FF 50 64 80 BF") + 0x1);
	//if (DWORD pAnimating = reinterpret_cast<uintptr_t>(ecx)){
	//	*(unsigned int*)((DWORD)pAnimating + 361) = 0xFF7FFFFF;
	//	*(unsigned int*)((DWORD)pAnimating + 358) = (g_iModelBoneCounter - 1);
	//}
	//const auto C_BaseAnimating_InvalidateBoneCaches = g_HookManager.GetMapHooks()["C_BaseAnimating_InvalidateBoneCaches"];
	//if (C_BaseAnimating_InvalidateBoneCaches){
	//	C_BaseAnimating_InvalidateBoneCaches->Original<void(__cdecl*)()>()();
	//}
	return Hook.Original<FN>()(ecx, edx, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
}
