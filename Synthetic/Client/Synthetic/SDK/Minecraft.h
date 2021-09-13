#ifndef CLIENT_SYNTHETIC_SDK_MINECRAFT
#define CLIENT_SYNTHETIC_SDK_MINECRAFT

#include "Classes/ClientInstance.h"

class Minecraft {
private:
    static ClientInstance* instance;
public:
    static auto getClientInstance() -> ClientInstance*;
    static auto setClientInstance(ClientInstance*) -> void;
};

#endif /* CLIENT_SYNTHETIC_SDK_MINECRAFT */
