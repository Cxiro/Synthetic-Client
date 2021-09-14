#ifndef CLIENT_SYNTHETIC_MODULE_MODULE
#define CLIENT_SYNTHETIC_MODULE_MODULE

#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../SDK/Minecraft.h"

class Manager;
class Category;

class Module {
private:
    std::string name;

    bool isEnabled = false, wasEnabled = false;
    
    uint64_t key;

    Manager* manager;
    Category* category;
public:
    Module(Manager* manager, Category*, std::string name, uint64_t key = NULL);

    auto toggleState() -> void;
    auto setState(bool) -> void;
    auto setKey(uint64_t) -> void;

    auto getManager() -> Manager*;
    auto getName() -> std::string;

    auto _tick() -> void;

    virtual void onTick() {};
    virtual void onEnable() {};
    virtual void onDisable() {};

    virtual void onClientInstance(ClientInstance*) {};
};

#endif /* CLIENT_SYNTHETIC_MODULE_MODULE */