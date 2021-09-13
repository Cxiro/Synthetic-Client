#ifndef CLIENT_SYNTHETIC_MANAGER_MANAGER
#define CLIENT_SYNTHETIC_MANAGER_MANAGER

#include "../SDK/Minecraft.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"

class Synthetic;

class Manager {
private:
    Synthetic* instance;
public:
    Manager(Synthetic*);
    
    auto getInstance() -> Synthetic*;

    auto init() -> void;

    auto initHooks() -> void;
    auto initModules() -> void;
};

#endif /* CLIENT_SYNTHETIC_MANAGER_MANAGER */