// dllmain.cpp : Définit le point d'entrée de l'application DLL.
#include "gaymode.h"
#include "framework.h"
#include "PC.h"

DWORD Main(LPVOID)
{
    AllocConsole();
    FILE* streamPtr;
    freopen_s(&streamPtr, "CONOUT$", "w", stdout);
    // unlocked console!
    SetConsoleTitleA("FMOD ON TOP!!!");

    MH_Initialize();
    InitGObjects();

    LOG_("UwU time to open levle!!!");
    LOG_("skidada!da!ad!dad!ad!a");

    MH_CreateHook((LPVOID)GetOffsetBRUH(0x2D39300), TickFlushHook, (void**)&TickFlushOG);
    MH_EnableHook((LPVOID)GetOffsetBRUH(0x2D39300));

    // 0x2C03D20

    MH_CreateHook((LPVOID)GetOffsetBRUH(0x2C03D20), KickPlayer, nullptr);
    MH_EnableHook((LPVOID)GetOffsetBRUH(0x2C03D20));

    // 0x15392D0

    MH_CreateHook((LPVOID)GetOffsetBRUH(0x2C03D20), ValFailure1, nullptr);
    MH_EnableHook((LPVOID)GetOffsetBRUH(0x2C03D20));

    MH_CreateHook((LPVOID)GetOffsetBRUH(0x30100A0), UWorldGetNetMode, nullptr);
    MH_EnableHook((LPVOID)GetOffsetBRUH(0x2C03D20));

    MH_CreateHook((LPVOID)GetOffsetBRUH(0x29A40F0), AActorGetNetMode, nullptr);
    MH_EnableHook((LPVOID)GetOffsetBRUH(0x29A40F0));

    InitHoksPC();
    InitAbilities();

    GetEngine()->GameInstance->LocalPlayers[0]->PlayerController->SwitchLevel(L"Athena_Terrain");
    GetEngine()->GameInstance->LocalPlayers.Remove(0);

    HOKSREAL();

    return 1;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        // Creates the main theread!
        CreateThread(0, 0, Main, 0, 0, 0);
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

