#ifndef CLIENT_SYNTHETIC_SYNTHETIC
#define CLIENT_SYNTHETIC_SYNTHETIC

#include "Manager/Manager.h"

#include "../Math/Math.h"
#include "../Mem/Mem.h"

class Synthetic {
private:
    Manager* manager;
    std::string name;
    std::string version;
public:
    Synthetic();
    /* Initialize */
    auto init() -> void;
    /* Manager */
    auto setManager(Manager*) -> void;
    auto getManager() -> Manager*;
    /* Name & version */
    auto getName() -> std::string;
    auto getVer() -> std::string;
};

#endif /* CLIENT_SYNTHETIC_SYNTHETIC */