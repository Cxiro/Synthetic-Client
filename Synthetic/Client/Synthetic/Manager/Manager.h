#ifndef CLIENT_SYNTHETIC_MANAGER_MANAGER
#define CLIENT_SYNTHETIC_MANAGER_MANAGER

#include "../SDK/Minecraft.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"

class Synthetic;
class Category;

class Manager {
private:
    Synthetic* instance;

    std::vector<Category*> categories;
public:
    Manager(Synthetic*);
    
    auto getInstance() -> Synthetic*;
    auto addCategory(Category*) -> void;
    std::vector<Category*> getCategories();

    auto init() -> void;

    auto initHooks() -> void;
    auto initModules() -> void;

    auto tick() -> void;
};

#endif /* CLIENT_SYNTHETIC_MANAGER_MANAGER */