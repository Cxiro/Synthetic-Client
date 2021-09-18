#include "Manager.h"
#include "../Synthetic.h"

Manager::Manager(Synthetic* instance){
    this->instance = instance;
    instance->setManager(this);
};

Synthetic* Manager::getInstance(){
    return this->instance;
};

void Manager::addCategory(Category* category){
    if(std::find(this->categories.begin(), this->categories.end(), category) == this->categories.end())
        this->categories.push_back(category);
};

std::vector<Category*> Manager::getCategories(){
    return this->categories;
};

bool Manager::isUsingKey(uint64_t key){
    return this->keyMap[key];
};

void Manager::setToKeyMap(uint64_t key, bool isDown){
    this->keyMap[key] = isDown;
};

void Manager::init(){
    this->initHooks();
    this->initModules();
    this->tick();
};

/* Hooks */

#include "../Hook/Hooks/ClientInstance/ClientInstance.h"
#include "../Hook/Hooks/Actor/Actor.h"
#include "../Hook/Hooks/GameMode/GameMode.h"
#include "../Hook/Hooks/Key/Key.h"
#include "../Hook/Hooks/MinecraftUIRenderContext/MinecraftUIRenderContext.h"
#include "../Hook/Hooks/LoopbackPacketSender/LoopbackPacketSender.h"

void Manager::initHooks(){
    if(MH_Initialize() == MH_OK){
        Utils::debugLogF("Initialized MinHook!");
        auto hook_clientInstance = new Hook_ClientInstance(this); /* Client Instance Hook */
        auto hook_actor = new Hook_Actor(this); /* Actor Hooks */
        auto hook_gm = new Hook_GameMode(this); /* GameMode Hooks */
        auto hook_key = new Hook_Key(this); /* Key Hook */
        auto hook_renderCtx = new Hook_MinecraftUIRenderContext(this); /* MinecraftUIRenderContext Hook */
        auto hook_loopback = new Hook_PacketSender(this); /* LoopbackPacketSender Hook */
    }
    else Utils::debugLogF("Failed to initialize MinHook!");
};

#include "../Category/Category.h"

/* Modules */

/* Combat */

#include "../Module/Modules/Combat/Killaura.h"
#include "../Module/Modules/Combat/Hitbox.h"

/* Movement */

#include "../Module/Modules/Movement/Jetpack.h"

/* Player */

/* Visuals */

#include "../Module/Modules/Visuals/Zoom.h"
#include "../Module/Modules/Visuals/TabGui.h"
#include "../Module/Modules/Visuals/ModuleList.h"

/* World */

/* Other */

#include "../Module/Modules/Other/FreeLook.h"
#include "../Module/Modules/Other/MineplexFlight.h"
#include "../Module/Modules/Other/TestModule.h"
#include "../Module/Modules/Other/Uninject.h"

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
    
    /* Combat */

    new Killaura(this, combat);
    new Hitbox(this, combat);

    /* Movement */

    new Jetpack(this, movement);

    /* Visuals */
    
    new Zoom(this, visuals);
    new TabGui(this, visuals);
    new ModuleList(this, visuals);

    /* Other */

    new FreeLook(this, other);
    new MineplexFlight(this, other);
    new TestModule(this, other);
    new Uninject(this, other);
};

void Manager::tick(){
    for(;;){
        for(auto c : this->categories){
            c->tickCategory();
        };
        Sleep(1);
    };
};