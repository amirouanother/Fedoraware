#pragma once
#include <Windows.h>

static constexpr auto CLIENT_DLL = "client.dll";
static constexpr auto ENGINE_DLL = "engine.dll";
static constexpr auto SERVER_DLL = "server.dll";
static constexpr auto VSTDLIB_DLL = "vstdlib.dll";
static constexpr auto VGUI2_DLL = "vgui2.dll";
static constexpr auto MATSURFACE_DLL = "vguimatsurface.dll";
static constexpr auto MATSYSTEM_DLL = "MaterialSystem.dll";
static constexpr auto STUDIORENDER_DLL = "studiorender.dll";
static constexpr auto TIER0_DLL = "tier0.dll";
static constexpr auto VPHYSICS_DLL = "vphysics.dll";

class CSignature
{
	uintptr_t m_Address = 0;
	LPCSTR m_Module = nullptr;
	LPCSTR m_Pattern = nullptr;
	int m_Offset = 0;

	void Find();

public:
	CSignature(LPCSTR szModule, LPCSTR szPattern, int offset = 0)
		: m_Module(szModule), m_Pattern(szPattern), m_Offset(offset) { }

	uintptr_t operator()()
	{
		if (m_Address == 0) { Find(); }
		return m_Address;
	}

	template <typename T> T As() { return reinterpret_cast<T>(this->operator()()); }
};

#define MAKE_SIGNATURE(name, module, pattern, offset) inline CSignature name{ module, pattern, offset }

namespace S
{
	// Hooks - x64 signatures
	MAKE_SIGNATURE(CBaseAnimating_FrameAdvance, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 57 48 81 EC ? ? ? ? 44 0F 29 54 24", 0x0);
	MAKE_SIGNATURE(CBaseAnimating_Interpolate, CLIENT_DLL, "48 89 5C 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9", 0x0);
	MAKE_SIGNATURE(CBaseAnimating_MaintainSequenceTransitions, CLIENT_DLL, "40 55 53 56 57 48 81 EC ? ? ? ? 48 8B 05", 0x0);
	MAKE_SIGNATURE(CBaseAnimating_UpdateClientSideAnimation, CLIENT_DLL, "48 89 5C 24 ? 57 48 83 EC ? 48 8B D9 E8 ? ? ? ? 48 8B F8 48 85 C0 74 ? 48 8B 00 48 8B CF FF 90 ? ? ? ? 84 C0 75 ? 33 FF 48 3B DF", 0x0);
	MAKE_SIGNATURE(CBaseCombatWeapon_AddToCritBucket, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 0F 57 C9", 0x0);
	MAKE_SIGNATURE(CBaseCombatWeapon_IsAllowedToWithdrawFromCritBucket, CLIENT_DLL, "40 53 48 83 EC ? 0F B6 41 ? 48 8B D9 84 C0", 0x0);
	MAKE_SIGNATURE(CBaseEntity_FireBullets, CLIENT_DLL, "48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8B FA 4C 8B E2 48 8B D9", 0x0);
	MAKE_SIGNATURE(CBaseEntity_Interpolate, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 8B B1", 0x0);
	MAKE_SIGNATURE(CBaseEntity_SetAbsVelocity, CLIENT_DLL, "48 89 5C 24 ? 57 48 83 EC ? F3 0F 10 81 ? ? ? ? 48 8B DA 0F 2E 02", 0x0);
	MAKE_SIGNATURE(C_BaseEntity_AddVar, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B F9 48 8B DA 4C 8B F1", 0x0);
	MAKE_SIGNATURE(C_BaseEntity_BaseInterpolatePart1, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B 79", 0x0);
	MAKE_SIGNATURE(C_BaseEntity_InterpolateServerEntities, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(C_BaseEntity_ResetLatched, CLIENT_DLL, "48 85 C9 74 ? 48 8B 41 ? 48 85 C0 74 ? 48 8B 40 ? C3", 0x0);
	MAKE_SIGNATURE(CBasePlayer_CalcViewModelView, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8B EC 48 83 EC ? 45 0F 28 F1", 0x0);
	MAKE_SIGNATURE(CBaseViewModel_ShouldFlipViewModel, CLIENT_DLL, "48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 E8 ? ? ? ? 84 C0 74 ? 48 8B CF E8 ? ? ? ? 8B 88 ? ? ? ? 85 C9 74 ? 33 C0 48 83 C4", 0x0);
	MAKE_SIGNATURE(COP_RenderSprites_RenderSpriteCard, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 05", 0x0);
	MAKE_SIGNATURE(CTFPlayer_AvoidPlayers, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B F9 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CTFPlayer_FireEvent, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 48 83 EC ? 48 8B 59", 0x0);
	MAKE_SIGNATURE(CTFRagdoll_CreateTFRagdoll, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 48 8B D7 FF 50 ? 48 8B 0D ? ? ? ? 48 85 C9 0F 84 ? ? ? ? 48 8B 01 48 8B D7 FF 50 ? 84 C0 74 ? 48 8D 8F", 0x0);
	MAKE_SIGNATURE(CTFWeaponBase_CalcIsAttackCritical, CLIENT_DLL, "48 89 74 24 ? 57 48 83 EC ? 48 8B F9 E8 ? ? ? ? 48 8B C8 C7 44 24 ? ? ? ? 4C 8D 0D ? ? ? ? 33 D2 4C 8D 05 ? ? ? ? E8 ? ? ? ? 48 8B F0 48 85 C0 0F 84 ? ? ? ? 48 8B 10", 0x0);
	MAKE_SIGNATURE(CTFWeaponBase_UpdateAllViewmodelAddons, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B D9 E8 ? ? ? ? 48 8B F8", 0x0);
	MAKE_SIGNATURE(CAchievementMgr_CheckAchievementsEnabled, CLIENT_DLL, "40 53 48 83 EC ? 48 8B D9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 84 C0 74 ? 48 8B CB E8 ? ? ? ? 84 C0 75 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 84 C0 75 ? 33 C0 48 83 C4", 0x0);
	MAKE_SIGNATURE(CBaseClient_Connect, ENGINE_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B 59", 0x0);
	MAKE_SIGNATURE(CBaseClient_Disconnect, ENGINE_DLL, "40 53 48 83 EC ? 48 8B D9 E8 ? ? ? ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CBaseClient_SendSignonData, ENGINE_DLL, "48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 48 8B D7 FF 50 ? 84 C0 74 ? E8 ? ? ? ? 84 C0 74 ? B9 ? ? ? ? E8 ? ? ? ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CEconItemSchema_GetItemDefinition, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B F2 48 8B 49 ? 48 85 C9 74 ? 48 8B 01 48 8B D7 FF 50 ? 48 85 C0 74 ? 48 8B 40 ? 48 8B 08 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 84 C0 75 ? 48 8B 4E ? 48 85 C9 74 ? 48 8B 01 48 8B D7 FF 50 ? 48 85 C0 74 ? 48 8B 40 ? 48 8B 08 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? 48 8B D7 FF 50", 0x0);
	MAKE_SIGNATURE(CEconNotification_HasNewItems, CLIENT_DLL, "40 53 48 83 EC ? 48 8B D9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 88 43 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 84 C0 75 ? 32 C0 48 83 C4", 0x0);
	MAKE_SIGNATURE(CheckSimpleMaterial, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 85 C9 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 33 D2 48 8B 01 FF 50 ? 48 85 C0 74 ? 48 8B 08 48 8B 01 FF 50 ? 48 8B CF FF 50 ? 84 C0 74 ? B9 ? ? ? ? 48 8B 01 FF 50 ? 84 C0 74 ? B9 ? ? ? ? E8 ? ? ? ? 84 C0 75 ? B8 ? ? ? ? EB ? 33 C0 48 8B 5C 24 ? 48 8B 74 24 ? 48 83 C4", 0x0);
	MAKE_SIGNATURE(CHudCrosshair_GetDrawPosition, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 48 8B D7 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 48 8B D7 FF 50 ? 8B F8", 0x0);
	MAKE_SIGNATURE(CInterpolatedVarArrayBase_Interpolate, CLIENT_DLL, "48 89 5C 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 0F 84 ? ? ? ? 48 8B 86", 0x0);
	MAKE_SIGNATURE(CInventoryManager_ShowItemsPickedUp, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B D9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 48 8B D3 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 84 C0 75 ? 33 DB", 0x0);
	MAKE_SIGNATURE(CL_LoadWhitelist, ENGINE_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CL_Move, ENGINE_DLL, "40 55 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8B 2D", 0x0);
	MAKE_SIGNATURE(CL_SendMove, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 86 ? ? ? ? 48 85 C0 74 ? 48 8B 08 48 8B 01 FF 50", 0x0);
	MAKE_SIGNATURE(CL_ReadPackets, ENGINE_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(ClientModeTFNormal_UpdateSteamRichPresence, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 81 EC ? ? ? ? 48 8B 59", 0x0);
	MAKE_SIGNATURE(ClientState_GetClientInterpAmount, ENGINE_DLL, "40 53 48 83 EC ? 48 8B D9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? F3 0F 10 05", 0x0);
	MAKE_SIGNATURE(ClientState_ProcessFixAngle, ENGINE_DLL, "48 89 5C 24 ? 56 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 8B F1 48 85 C0 74 ? 48 8B 08 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CMatchInviteNotification_OnTick, CLIENT_DLL, "48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? E8 ? ? ? ? 48 8B 4F", 0x0);
	MAKE_SIGNATURE(CNetChan_SendNetMsg, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F1 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 86", 0x0);
	MAKE_SIGNATURE(CNewParticleEffect_DrawModel, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(COcclusionSystem_IsOccluded, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CRendering3dView_EnableWorldFog, CLIENT_DLL, "40 53 48 83 EC ? 48 8B D9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? F3 0F 10 05", 0x0);
	MAKE_SIGNATURE(CSequenceTransitioner_CheckForSequenceChange, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CSkyboxView_Enable3dSkyboxFog, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 75 ? B9", 0x0);
	MAKE_SIGNATURE(CSoundEmitterSystem_EmitSound, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 75 ? 48 8B 4F", 0x0);
	MAKE_SIGNATURE(CStaticPropMgr_ComputePropOpacity, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CStaticPropMgr_DrawStaticProps, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CTFGameRules_ModifySentChat, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 75 ? 48 8B 4F", 0x0);
	MAKE_SIGNATURE(CTFGCClientSystem_UpdateAssignedLobby, CLIENT_DLL, "40 55 53 41 54 41 56 41 57 48 8B EC", 0x0);
	MAKE_SIGNATURE(CTFPartyClient_BCanRequestToJoinPlayer, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CTFPlayerInventory_GetMaxItemCount, CLIENT_DLL, "48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 75 ? 48 8B 47", 0x0);
	MAKE_SIGNATURE(CTFPlayerShared_InCond, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CTFPlayerShared_IsPlayerDominated, CLIENT_DLL, "48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 75 ? 48 8B 47", 0x0);
	MAKE_SIGNATURE(CViewRender_DrawUnderwaterOverlay, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(DataTable_Warning, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(DoEnginePostProcessing, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(DSP_Process, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(FX_FireBullets, CLIENT_DLL, "48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8B FA 4C 8B E2 48 8B D9", 0x0);
	MAKE_SIGNATURE(GetClientInterpAmount, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? F3 0F 10 05", 0x0);
	MAKE_SIGNATURE(IsLocalPlayerUsingVisionFilterFlags, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(KeyValues_SetInt, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(NetChannel_SendDatagram, ENGINE_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(NotificationQueue_Add, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(S_StartDynamicSound, ENGINE_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 75 ? 48 8B 4F", 0x0);
	MAKE_SIGNATURE(UTIL_TraceLine, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B FA 4C 8B F1", 0x0);
	MAKE_SIGNATURE(ViewRender_PerformScreenSpaceEffects, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CMaterial_Uncache, MATSYSTEM_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(CTFMatchSummary_OnTick, CLIENT_DLL, "48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);

	// Functions
	MAKE_SIGNATURE(CMatchInviteNotification_AcceptMatch, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 8B 86", 0x0);
	MAKE_SIGNATURE(CTFKnife_IsBehindAndFacingTarget, CLIENT_DLL, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);

	// Additional hook signatures
	MAKE_SIGNATURE(CBaseAnimating_SetupBones, CLIENT_DLL, "48 8B C4 44 89 40 ? 48 89 50 ? 55 53", 0x0);
	MAKE_SIGNATURE(CBasePlayer_PostDataUpdate_SetAbsVelocityCall, CLIENT_DLL, "0F 28 74 24 ? 8B D6", 0x0);
	MAKE_SIGNATURE(CBasePlayer_CalcFreezeCamView, CLIENT_DLL, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D", 0x0);
	MAKE_SIGNATURE(C_BaseEntity_MoveToLastReceivedPosition, CLIENT_DLL, "48 89 5C 24 ? 57 48 81 EC ? ? ? ? 48 8B F9 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF 50 ? 84 C0 74 ? 48 8B 0D", 0x0);
	MAKE_SIGNATURE(PlayerShouldDraw, CLIENT_DLL, "84 C0 74 ? 32 C0 48 8B 74 24", 0x0);
	MAKE_SIGNATURE(WearableShouldDraw, CLIENT_DLL, "84 C0 0F 85 ? ? ? ? 41 BF", 0x0);
	MAKE_SIGNATURE(HudScopeShouldDraw, CLIENT_DLL, "84 C0 74 ? 48 8B CB E8 ? ? ? ? 48 85 C0 74 ? 48 8B CB E8 ? ? ? ? 48 8B C8 48 8B 10 FF 92 ? ? ? ? 83 F8 ? 0F 94 C0", 0x0);
	MAKE_SIGNATURE(StartDrawing, MATSURFACE_DLL, "40 53 56 57 48 83 EC ? 48 8B F9 80 3D", 0x0);
	MAKE_SIGNATURE(FinishDrawing, MATSURFACE_DLL, "40 53 48 83 EC ? 33 C9", 0x0);
	MAKE_SIGNATURE(CTFWeaponBaseGun_FireBullet_Call, CLIENT_DLL, "0F 28 7C 24 ? 4C 8D 9C 24 ? ? ? ? 49 8B 5B ? 49 8B 6B ? 49 8B 73 ? 41 0F 28 73 ? 49 8B E3", 0x0);
	MAKE_SIGNATURE(DisplayDamageFeedback, CLIENT_DLL, "84 C0 0F 84 ? ? ? ? 48 8B 06 48 8B CE FF 90 ? ? ? ? 49 8B 16", 0x0);

	// Values
	MAKE_SIGNATURE(RandomSeed, CLIENT_DLL, "0F B6 1D ? ? ? ? 89 9D", 0x0);
	MAKE_SIGNATURE(AllowSecureServers, ENGINE_DLL, "48 8D 0D ? ? ? ? 48 89 0D ? ? ? ? 48 8B 49 ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 50 ? 84 C0 74 ? C6 05", 0x2);
}
