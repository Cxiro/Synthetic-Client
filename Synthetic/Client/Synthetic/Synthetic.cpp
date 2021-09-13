#include "Synthetic.h"

Synthetic::Synthetic(){
    this->name = std::string("Synthetic Utility");
    this->version = std::string("0.1");
    
    Utils::initDebugFWithPath(this->name.c_str());
    Utils::debugLogF("Initialized Synthetic Utility!", this->name.c_str());

    this->init();
};

void Synthetic::init(){
    Manager* manager = new Manager(this);
    manager->init();
};

void Synthetic::setManager(Manager* ptr){
    if(ptr == nullptr)
        return;
    this->manager = ptr;
};

Manager* Synthetic::getManager(){
    return this->manager;
};

std::string Synthetic::getName(){
    return this->name;
};

std::string Synthetic::getVer(){
    return this->version;
};