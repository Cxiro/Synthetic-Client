#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE

#include "../../../Mem/Mem.h"
#include "../../../Math/Math.h"
#include "../../../Utils/Utils.h"

#include "GameSettings.h"
#include "MinecraftGame.h"
#include "Player.h"

class ClientInstance {
public:
    auto getBaseAddr() -> uintptr_t;
    auto getSettings() -> GameSettings*;
    auto getMinecraftGame() -> MinecraftGame*;
    auto getPlayer() -> Player*;
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE */