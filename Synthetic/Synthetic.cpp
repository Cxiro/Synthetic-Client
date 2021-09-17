#include <Windows.h>
#include <thread>

#include "Client/Synthetic/Synthetic.h"

void init(HMODULE hModule){
    Mem::setHModule(hModule);
    Synthetic* client = new Synthetic();
};

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpReserved){
    switch(fdwReason){
        case DLL_PROCESS_ATTACH:
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);
        break;
    }
    return TRUE;
};