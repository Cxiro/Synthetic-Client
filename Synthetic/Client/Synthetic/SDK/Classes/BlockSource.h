#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_BLOCKSOURCE
#define CLIENT_SYNTHETIC_SDK_CLASSES_BLOCKSOURCE

#include "Block.h"

class BlockSource {
public:
    Block* getBlock(Vec3<int> blockPos){
        using GetBlock = Block * (__thiscall*)(BlockSource*, Vec3<int>*);
		static GetBlock _GetBlock = reinterpret_cast<GetBlock>(Mem::findSig("48 89 5C 24 ? 57 48 83 EC 20 48 8B F9 48 8B DA 8B 4A 04 0F BF 47 2A 3B C8"));
		return _GetBlock(this, &blockPos);
    };
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_BLOCKSOURCE */