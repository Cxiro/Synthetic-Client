#ifndef CLIENT_SYNTHETIC_HOOK_HOOK
#define CLIENT_SYNTHETIC_HOOK_HOOK

#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../SDK/Minecraft.h"

class Manager;

class Hook {
private:
    std::vector<uintptr_t> addresses = std::vector<uintptr_t>();
    bool initialized = false;
    Manager* manager;
public:
    virtual auto init() -> void {};
    
    auto removeHooks() -> void;
    auto setManager(Manager* manager) -> void;
    auto getManager() -> Manager*;
};

#endif /* CLIENT_SYNTHETIC_HOOK_HOOK */