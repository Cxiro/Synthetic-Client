#include "Manager.h"
#include "../Synthetic.h"

Manager::Manager(Synthetic* instance){
    this->instance = instance;
    instance->setManager(this);
};

Synthetic* Manager::getInstance(){
    return this->instance;
};

std::vector<Category*> Manager::getCategories(){
    return this->categories;
};

void Manager::addCategory(Category* category){
    if(std::find(this->categories.begin(), this->categories.end(), category) == this->categories.end())
        this->categories.push_back(category);
};

void Manager::init(){
    this->initHooks();
    this->initModules();
    this->tick();
};

/* Hooks */

#include "../Hook/Hooks/ClientInstance/ClientInstance.h"

void Manager::initHooks(){
    if(MH_Initialize() == MH_OK){
        auto hook_clientInstance = new Hook_ClientInstance(this); /* Client Instance Hook */
    }
    else Utils::debugLogF("Failed to initialize MinHook!");
};

#include "../Category/Category.h"

/* Modules */

#include "../Module/Modules/TestModule.h"

void Manager::initModules(){
    Category* combat = new Category(this, "Combat");
    Category* movement = new Category(this, "Movement");
    Category* player = new Category(this, "Player");
    Category* world = new Category(this, "World");
    Category* visuals = new Category(this, "Visuals");
    Category* other = new Category(this, "Other");

    this->addCategory(combat);
    this->addCategory(movement);
    this->addCategory(player);
    this->addCategory(world);
    this->addCategory(visuals);
    this->addCategory(other);

    new TestModule(this, other);
};

void Manager::tick(){
    for(;;){
        for(auto c : this->categories){
            c->tickCategory();
        };
        Sleep(1);
    };
};