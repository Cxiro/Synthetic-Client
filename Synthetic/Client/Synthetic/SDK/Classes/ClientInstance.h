#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE

#include "../../../Mem/Mem.h"
#include "../../../Math/Math.h"
#include "../../../Utils/Utils.h"

#include "GameSettings.h"
#include "MinecraftGame.h"
#include "GuiData.h"
#include "Level.h"
#include "Dimension.h"
#include "Block.h"
#include "BlockSource.h"
#include "GameMode.h"
#include "Player.h"
#include "Container.h"
#include "PlayerInventory.h"

#include "MinecraftUIRenderContext.h"
#include "LoopbackPacketSender.h"
#include "Packet.h"

class ClientInstance {
public:
    auto getBaseAddr() -> uintptr_t;
    auto getSettings() -> GameSettings*;
    auto getMinecraftGame() -> MinecraftGame*;
    auto getGuiData() -> GuiData*;
    auto getPlayer() -> Player*;
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_CLIENTINSTANCE */