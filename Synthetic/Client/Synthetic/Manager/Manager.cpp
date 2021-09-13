#include "Manager.h"
#include "../Synthetic.h"

Manager::Manager(Synthetic* instance){
    this->instance = instance;
    instance->setManager(this);
};

Synthetic* Manager::getInstance(){
    return this->instance;
};

void Manager::init(){
    this->initHooks();
    this->initModules();
};

/* Hooks */

#include "../Hook/Hooks/ClientInstance/ClientInstance.h"

void Manager::initHooks(){
    if(MH_Initialize() == MH_OK){
        auto hook_clientInstance = new Hook_ClientInstance(this); /* Client Instance Hook */
    }
    else Utils::debugLogF("Failed to initialize MinHook!");
};

void Manager::initModules(){
    //
};