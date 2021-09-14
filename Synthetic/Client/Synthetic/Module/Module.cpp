#include "Module.h"
#include "../Category/Category.h"

Module::Module(Manager* manager, Category* category, std::string name, uint64_t key){
    this->manager = manager;
    this->category = category;
    this->name = name;
    this->key = key;

    this->category->addModule(this);
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

Manager* Module::getManager(){
    return this->manager;
};

std::string Module::getName(){
    return this->name;
};

void Module::_tick(){
    if(wasEnabled != isEnabled){
        if(isEnabled)
            onEnable();
        else
            onDisable();
        wasEnabled = isEnabled;
    };
    if(isEnabled)
        onTick();
};