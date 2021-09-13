#include "Module.h"

Module::Module(Manager* manager, std::string name, uint64_t key){
    this->manager = manager;
    this->name = name;
    this->key = key;
};

void Module::toggleState(){
    this->isEnabled = !this->isEnabled;
};

void Module::setState(bool state){
    this->isEnabled = state;
};

void Module::setKey(uint64_t key){
    this->key = key;
};

void Module::_tick(){
    if(isEnabled != wasEnabled){
        if(isEnabled)
            onEnable();
        else
            onDisable();
        isEnabled = wasEnabled;
    };
    if(isEnabled)
        onTick();
};