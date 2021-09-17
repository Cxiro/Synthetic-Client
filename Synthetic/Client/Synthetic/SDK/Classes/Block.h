#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_BLOCK
#define CLIENT_SYNTHETIC_SDK_CLASSES_BLOCK

class Material { /* this specific class here was Fetched from Horion */
public:
	int type; // 5 for water, 6 for lava
	bool isFlammable;
	bool isNeverBuildable;
	bool isAlwaysDestroyable;
	bool isReplaceable;
	bool isLiquid;  // 0x0008
private:
	char pad2[0x3]; // 0x009
public:
	float translucency;  // 0x00C
	bool isBlockingMotion;
	bool isBlockingPrecipitation;
	bool isSolid;
	bool isSuperHot;
	float color[4];
};

class BlockLegacy {
private:
    char pad_0x0000[0xD8]; //0x0000
public:
    Material* material;

    __int16 getBlockItemId(){
        using GetBlockItemId = __int16 (__fastcall*)(BlockLegacy*);
		static GetBlockItemId _GetBlockItemId = reinterpret_cast<GetBlockItemId>(Mem::findSig("0F B7 91 ? ? ? ? B8 ? ? ? ? 66 3B D0 72 09 B8 ? ? ? ? 66 2B C2 C3"));
		return _GetBlockItemId(this);
    };
};

class Block {
private:
    char pad_0x0000[0x10]; //0x0000
public:
	BlockLegacy* legacy; //0x0010
};


#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_BLOCK */