#include <Windows.h>
#include <thread>

#include "Client/Synthetic/Synthetic.h"

void init(){
    Synthetic* client = new Synthetic();
};

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpReserved){
    switch(fdwReason){
        case DLL_PROCESS_ATTACH:
            std::thread(init).detach();
        break;
    }
    return TRUE;
};