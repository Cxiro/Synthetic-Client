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