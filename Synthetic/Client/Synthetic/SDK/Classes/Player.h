#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_PLAYER
#define CLIENT_SYNTHETIC_SDK_CLASSES_PLAYER

#include "Actor.h"

#include "Actor.h"
#include "PlayerInventory.h"
#include "GameMode.h"

class Mob;

struct TextureUVCoordinateSet;

struct IMobMovementProxy;

class BodyControl;

struct ChunkSource;

struct Tick;

class ChunkPos;

class TextObjectRoot;

class ResolvedTextObject;

enum GameType { Survival = 0, Creative = 1, Adventure = 2, Default = 5 };

struct IMinecraftEventing;

struct EventPacket;

struct IContainerManager;

struct Container;

class Item;

struct InventoryTransaction;

class ComplexInventoryTransaction;

class Packet;

struct PlayerEventCoordinator;

struct MoveInputHandler;

enum ClientPlayMode;

enum MovementEventType;

class Player : public Actor {
public:
    PlayerInventory* getSupplies(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 91 ? ? ? ? 80 BA ? ? ? ? ? ? ? 48 8B 8A ? ? ? ? 8B 52 ? 48 8B 01 48") + 3);
        return *reinterpret_cast<PlayerInventory**>((uintptr_t)(this) + offset);
    };
    float* airAcc(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("F3 0F 11 88 ? ? ? ? C3 CC CC CC 48 8B 41 ? F3 0f 10 80 ? ? ? ? C3 CC CC CC 48 83") + 4);
        return reinterpret_cast<float*>((uintptr_t)(this) + offset);
    };
    GameMode* getGameModeInst(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("48 8B BE ? ? ? ? 48 8B 8E ? ? ? ? 48 89 6C") + 3);
        return *reinterpret_cast<GameMode**>((uintptr_t)(this) + offset);
    };
    int* getPlayerGameType(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("8B 81 ? ? ? ? 83 F8 01 ? ? 83 F8 05 ? ? 48 8B") + 2);
        return reinterpret_cast<int*>((uintptr_t)(this) + offset);
    };
public:
    virtual void knockback(Actor*, float, float, float, float, float, float);
    virtual void resolveDeathLoot(int, ActorDamageSource*);
private:
    virtual void Function372();
public:
    virtual void setSleeping(bool);
    virtual void setSprinting(bool);
    virtual void playAmbientSound(void);
    virtual LevelSoundEvent getAmbientSound(void);
    virtual LevelSoundEvent getHurtSound(void);
    virtual LevelSoundEvent getDeathSound(void);
    virtual __int64 getAmbientSoundPostponeTicks(void);
    virtual __int64 getAmbientSoundPostponeTicksRange(void);
    virtual TextureUVCoordinateSet* getItemInHandIcon(ItemStack*, int);
    virtual float getSpeed(void);
    virtual void setSpeed(float);
    virtual float getJumpPower(void);
    virtual bool hurtEffects(ActorDamageSource*, int, bool, bool);
    virtual __int64 getMeleeWeaponDamageBonus(Mob*);
    virtual __int64 getMeleeKnockbackBonus(void);
    virtual void travel(IMobMovementProxy*, float, float, float);
    virtual void travel(float, float, float);
    virtual void applyFinalFriction(float, bool);
    virtual void updateWalkAnim(void);
    virtual void aiStep(IMobMovementProxy*);
    virtual void aiStep(void);
    virtual void pushActors(void);
    virtual void lookAt(Actor *, float, float);
    virtual bool isLookingAtAnEntity(void);
    virtual bool checkSpawnRules(bool);
    virtual bool checkSpawnObstruction(void);
    virtual float getAttackAnim(float);
    virtual __int64 getItemUseDuration(void);
    virtual float getItemUseStartupProgress(void);
    virtual float getItemUseIntervalProgress(void);
    virtual __int64 getItemuseIntervalAxis(void);
    virtual __int64 getTimeAlongSwing(void);
private:
    virtual void Function404();
public:
    virtual float getMaxHeadXRot(void);
    virtual Actor* getLastHurtByMob(void);
    virtual void setLastHurtByMob(Mob*);
    virtual Player* getLastHurtByPlayer(void);
    virtual void setLastHurtByPlayer(Player*);
    virtual Mob* getLastHurtMob(void);
    virtual void setLastHurtMob(Actor*);
private:
    virtual void Function412();
public:
    virtual void doHurtTarget(Actor*, ActorDamageCause*);
private:
    virtual void Function414();
public:
    virtual void leaveCaravan(void);
    virtual void joinCaravan(Mob*);
    virtual bool hasCaravanTail(void);
    virtual ActorUniqueID getCaravanHead(void);
    virtual __int64 getArmorValue(void);
    virtual float getArmorCoverPercentage(void);
    virtual void hurtArmor(ActorDamageSource const &, int, std::bitset<4> const &);
    virtual void hurtArmor(ActorDamageSource*, int);
    virtual void hurtArmorSlot(ActorDamageSource const &, int, ArmorSlot);
    virtual void setDamagedArmor(ArmorSlot, ItemStack*);
    virtual __int64 sendArmorDamage(std::bitset<4> const &);
    virtual __int64 sendArmor(std::bitset<4> const &);
    virtual void containerChanged(int);
    virtual void updateEquipment(void);
    virtual void clearEquipment(void);
    virtual std::vector<ItemStack*> getAllArmor(void);
    virtual __int64 getAllArmorID(void);
    virtual __int64 getAllHand(void);
    virtual __int64 getAllEquipment(void);
    virtual __int64 getArmorTypeHash(void);
    virtual void dropEquipmentOnDeath(void);
    virtual void dropEquipmentOnDeath(ActorDamageSource*, int);
    virtual void clearVanishEnchantedItemsOnDeath(void);
    virtual void sendInventory(bool);
    virtual int getDamageAfterMagicAbsorb(ActorDamageSource*, int);
    virtual bool createAIGoals(void);
private:
    virtual void Function441();
public:
    virtual bool setItemSlot(EquipmentSlot, ItemStack*);
    virtual void setTransitioningSitting(bool);
    virtual void attackAnimation(Actor*, float);
private:
    virtual void Function445();
    virtual void Function446();
    virtual void Function447();
    virtual void Function448();
public:
    virtual void ascendLadder(void);
    virtual void ascendBlockByJumping(void);
    virtual void descendBlockByCrouching(void);
    virtual void dropContainer(void);
    virtual std::unique_ptr<BodyControl, struct std::default_delete<BodyControl>> initBodyControl(void);
    virtual void jumpFromGround(IMobMovementProxy*);
    virtual void jumpFromGround(void);
private:
    virtual void Function556();
public:
    virtual void newServerAiStep(void);
private:
    virtual void Function558();
public:
    virtual __int64 getDamageAfterEnchantReduction(ActorDamageSource*, int);
    virtual int getDamageAfterArmorAbsorb(ActorDamageSource*, int);
    virtual void dropBags(void);
    virtual void tickDeath(void);
    virtual void updateGliding(void);
private:
    virtual void Function564();
public:
    virtual void prepareRegion(ChunkSource*);
    virtual void destroyRegion(void);
    virtual void suspendRegion(void);
    virtual void resendAllChunks(void);
    virtual bool _fireWillChangeDimension(void);
    virtual void _fireDimensionChanged(void);
    virtual __int64 changeDimensionWithCredits();
    virtual __int64 tickWorld(Tick*);
private:
    virtual void Function573();
public:
    virtual std::vector<ChunkPos, class std::allocator<ChunkPos>> getTickingOffsets(void);
    virtual void moveView(void);
    virtual void setName(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual void checkMovementStats(Vec3<float>*);
private:
    virtual void Function578();
    virtual void Function579();
public:
    virtual void respawn(void);
private:
    virtual void Function581();
public:
    virtual void resetPos(bool);
private:
    virtual void Function583();
public:
    virtual bool hasResource(int);
    virtual void completeUsingItem(void);
    virtual void setPermissions(int);
    virtual void startDestroying(void);
    virtual void stopDestroying(void);
private:
    virtual void Function589();
    virtual void Function590();
public:
    virtual void openTrading(ActorUniqueID*, bool);
    virtual bool canOpenContainerScreen(void);
private:
    virtual void Function593();
    virtual void Function594();
public:
    virtual void openInventory(void);
private:
    virtual void Function596();
    //virtual void Function597();
public:
    virtual void displayClientMessage(std::string*);
    virtual void displayTextObjectMessage(TextObjectRoot const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual void displayTextObjectWhisperMessage(ResolvedTextObject const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual void displayWhisperMessage(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual void startSleepInBed(Vec3<int>*);
    virtual void stopSleepInBed(bool, bool);
    virtual bool canStartSleepInBed(void);
    virtual __int64 getSleepTimer(void);
    virtual __int64 getPreviousTickSleepTimer(void);
private:
    virtual void Function606();
    virtual void Function607();
public:
    virtual bool isHostingPlayer(void);
    virtual bool isLoading(void);
    virtual bool isPlayerInitialized(void);
private:
    virtual void Function611();
public:
    virtual void registerTrackedBoss(ActorUniqueID);
    virtual void unRegisterTrackedBoss(ActorUniqueID);
    virtual void setPlayerGameType(GameType);
    virtual void initHUDContainerManager(void);
    virtual void _crit(Actor*);
    virtual IMinecraftEventing* getEventing(void);
private:
    virtual void Function618();
public:
    virtual void sendEventPacket(EventPacket*);
    virtual void addExperience(int);
    virtual void addLevels(int);
    virtual void setContainerData(IContainerManager*, int, int);
    virtual void slotChanged(IContainerManager*, Container*, int, ItemStack*, ItemStack*, bool);
    virtual void inventoryChanged(Container*, int, ItemStack*, ItemStack*, bool);
    virtual void refreshContainer(IContainerManager*);
    virtual void deleteContainerManager(void);
    virtual float setFieldOfViewModifier(float);
    virtual bool is2DPositionRelevant(__int64, Vec3<int>*);
    virtual bool isEntityRelevant(Actor*);
    virtual bool isTeacher(void);
    virtual void onSuspension(void);
    virtual void onLinkedSlotsChanged(void);
    virtual void startCooldown(Item*);
    virtual int getItemCooldownLeft(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual bool isItemInCooldown(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual void sendInventoryTransaction(InventoryTransaction*);
    virtual void sendComplexInventoryTransaction(std::unique_ptr<ComplexInventoryTransaction,std::default_delete<ComplexInventoryTransaction>>);
    virtual void sendNetworkPacket(Packet*);
    virtual PlayerEventCoordinator* getPlayerEventCoordinator(void);
    virtual MoveInputHandler* getMoveInputHandler(void);
    virtual InputMode getInputMode(void);
    virtual ClientPlayMode getPlayMode(void);
    virtual void reportMovementTelemetry(MovementEventType);
    virtual void onMovePlayerPacketNormal(Vec3<float>* ,Vec2<float>*, float);
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_PLAYER */