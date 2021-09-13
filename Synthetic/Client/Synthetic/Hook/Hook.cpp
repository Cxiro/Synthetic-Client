#include "Hook.h"

void Hook::removeHooks(){
    if(!initialized)
        return;
    
    for(auto address : addresses) {
        //
    };
};

void Hook::setManager(Manager* manager){
    this->manager = manager;
};

Manager* Hook::getManager(){
    return this->manager;
};