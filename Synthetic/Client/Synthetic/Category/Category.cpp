#include "Category.h"

Category::Category(Manager* manager, std::string name){
    this->manager = manager;
    this->name = name;
    this->modules = std::vector<Module*>();
};

void Category::addModule(Module* module){
    if(std::find(modules.begin(), modules.end(), module) == modules.end())
        modules.push_back(module);
};

void Category::tickCategory(){
    for(auto m : modules){
        m->_tick();
    };
};