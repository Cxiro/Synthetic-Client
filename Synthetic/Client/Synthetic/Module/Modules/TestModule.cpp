#include "TestModule.h"

void TestModule::onTick(){
    //
};

void TestModule::onEnable(){
    Utils::debugLogF(std::string("Enabled " + this->getName()).c_str());
};

void TestModule::onDisable(){
    Utils::debugLogF(std::string("Disabled " + this->getName()).c_str());
};

void TestModule::onClientInstance(ClientInstance* instance){
    if(instance == nullptr)
        return;
    
    auto player = instance->getPlayer();

    if(player == nullptr)
        return;
    
    std::ostringstream o;
    o << std::hex << player << std::endl;

    Utils::debugLogF(std::string("Player: " + o.str()).c_str());
};