#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_LOOPBACKPACKETSENDER
#define CLIENT_SYNTHETIC_SDK_CLASSES_LOOPBACKPACKETSENDER

class LoopbackPacketSender {
private:
	virtual ~LoopbackPacketSender();
public:
	virtual void send(Packet* packet);
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_LOOPBACKPACKETSENDER */