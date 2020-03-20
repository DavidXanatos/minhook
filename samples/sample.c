/* MinHook Sample */
#include <windows.h>
#include "MinHook.h"

typedef int (WINAPI *MESSAGEBOXW)(HWND, LPCWSTR, LPCWSTR, UINT);

MESSAGEBOXW fpMessageBoxW = NULL;

int WINAPI DetourMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    return fpMessageBoxW(hWnd, L"Hooked!", lpCaption, uType);
}

int main(void)
{
    if (MH_Initialize() != MH_OK)
    {
        return EXIT_FAILURE;
    }

    if (MH_CreateHookApiEx(L"user32", "MessageBoxW", &DetourMessageBoxW, &fpMessageBoxW) != MH_OK)
    {
        return EXIT_FAILURE;
    }

    if (MH_EnableHook(&MessageBoxW) != MH_OK)
    {
        return EXIT_FAILURE;
    }

    MessageBoxW(NULL, L"Not hooked...", L"MinHook Sample", MB_OK);

    if (MH_DisableHook(&MessageBoxW) != MH_OK)
    {
        return EXIT_FAILURE;
    }

    MessageBoxW(NULL, L"Not hooked...", L"MinHook Sample", MB_OK);

    if (MH_Uninitialize() != MH_OK)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
