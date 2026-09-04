#include <Windows.h>
#include "Core/Core.h"
#include "Utils/Minidump/Minidump.h"

DWORD WINAPI MainThread(LPVOID lpParam)
{
	// Wait until the x64 game modules our init depends on are loaded before
	// proceeding. On x64 TF2 the audio system is "mss64.dll" (not "mss32.dll")
	// and shader names differ, so gate on the modules our interfaces and
	// signatures actually need. Allows autoinject at game start.
	while (!GetModuleHandleW(L"client.dll") ||
		!GetModuleHandleW(L"engine.dll") ||
		!GetModuleHandleW(L"materialsystem.dll"))
	{
		Sleep(2000);
	}

	g_Core.Load();

	while (!g_Core.ShouldUnload())
	{
		Sleep(20);
	}

	g_Core.Unload();

#ifndef _DEBUG
	SetUnhandledExceptionFilter(nullptr);
#endif
	FreeLibraryAndExitThread(static_cast<HMODULE>(lpParam), EXIT_SUCCESS);
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
#ifndef _DEBUG
		SetUnhandledExceptionFilter(Minidump::ExceptionFilter);
#endif

		if (const auto hMainThread = CreateThread(nullptr, 0, MainThread, hinstDLL, 0, nullptr))
		{
			CloseHandle(hMainThread);
		}
	}

	return TRUE;
}
