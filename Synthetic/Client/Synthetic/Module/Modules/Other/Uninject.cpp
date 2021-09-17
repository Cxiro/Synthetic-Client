#include "Uninject.h"

#include "../../../Manager/Manager.h"
#include "../../../Synthetic.h"

void Uninject::onEnable(){
    MH_DisableHook(MH_ALL_HOOKS);

    Sleep(1000);

    MH_Uninitialize();

    Sleep(1000);

    FreeLibraryAndExitThread(Mem::getHModule(), 1);
};