#include "LoopbackPacketSender.h"

#include "../../../Manager/Manager.h"
#include "../../../Category/Category.h"
#include "../../../Module/Module.h"

Hook_PacketSender::Hook_PacketSender(Manager* manager){
    this->setManager(manager);
};

typedef void(__thiscall* Send)(LoopbackPacketSender*, Packet*);
Send _Send;

Manager* p_manager = nullptr;

void send_Callback(LoopbackPacketSender* loopbackSender, Packet* packet){

    bool cancel = false;
    
    if(p_manager != nullptr){
        for(auto c : p_manager->getCategories()){
            for(auto m : c->modules){
                if(m->getState())
                    m->onPacket(packet, &cancel);
            };
        };
    };

    if(!cancel) _Send(loopbackSender, packet);
};

void Hook_PacketSender::init(){
    auto sig = Mem::findSig("48 8B 41 10 4C 8B 09 4C 8B 40 48 41 80 B8 ? ? ? ? ? 74 04 49 FF 61 30");

    p_manager = this->getManager();

    if(!sig)
        return Utils::debugLogF("Failed to find signature for LoopbackPacketSender sendToServer");
    
    if(MH_CreateHook((void*)sig, &send_Callback, reinterpret_cast<LPVOID*>(&_Send)) == MH_OK){
        Utils::debugLogF("Successfully created hook for LoopbackPacketSender sendToServer");
        MH_EnableHook((void*)sig);
    }
    else {
        Utils::debugLogF("Failed to create hook for LoopbackPacketSender sendToServer");
    };
};