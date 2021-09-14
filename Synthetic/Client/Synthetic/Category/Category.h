#ifndef CLIENT_SYNTHETIC_CATEGORY_CATEGORY
#define CLIENT_SYNTHETIC_CATEGORY_CATEGORY

#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../SDK/Minecraft.h"

#include "../Module/Module.h"

class Manager;

class Category {
public:
    std::string name;

    std::vector<Module*> modules;

    Manager* manager;
    
    Category(Manager*, std::string);

    auto addModule(Module*) -> void;
    auto tickCategory() -> void;
};

#endif /* CLIENT_SYNTHETIC_CATEGORY_CATEGORY */