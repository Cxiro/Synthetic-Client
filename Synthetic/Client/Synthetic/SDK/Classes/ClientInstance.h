#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE

#include "../../../Mem/Mem.h"
#include "../../../Math/Math.h"
#include "../../../Utils/Utils.h"

#include "GameSettings.h"
#include "MinecraftGame.h"
#include "Level.h"
#include "Dimension.h"
#include "Block.h"
#include "BlockSource.h"
#include "Player.h"
#include "Container.h"
#include "PlayerInventory.h"

#include "MinecraftUIRenderContext.h"

class ClientInstance {
public:
    auto getBaseAddr() -> uintptr_t;
    auto getSettings() -> GameSettings*;
    auto getMinecraftGame() -> MinecraftGame*;
    auto getPlayer() -> Player*;
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE */