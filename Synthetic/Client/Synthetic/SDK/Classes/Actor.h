#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_ACTOR
#define CLIENT_SYNTHETIC_SDK_CLASSES_ACTOR

class Level;
class Dimension;
class VariantParameterList;
struct PredictedMovementValues;
struct StateVectorComponent;
enum ActorLocation;
struct IActorMovementProxy;
class ActorDamageSource;
enum InputMode;
struct UIProfanityContext;
enum MaterialType;
enum ActorDamageCause;
enum ActorEvent;
struct HashedString;
class ItemStack;
struct ItemActor;
enum ArmorSlot;
enum EquipmentSlot;
struct CompoundTag;
struct DataLoadHelper;
struct ActorLink;
enum ActorType;
struct ActorUniqueID;
enum LevelSoundEvent;
enum CommandPermissionLevel;
struct AttributeInstance;
struct Attribute;
struct MobEffectInstance;
struct AnimationComponent;
class ItemStackBase;
enum ItemUseMethod;
class Player;
struct ActorInteraction;
struct EquipmentTableDefinition;
struct LootTable;
enum AnimationComponentGroup;

#include "BlockSource.h"
#include "Block.h"

class Actor {
public:
    __int64 getRuntimeId(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 87 ? ? ? ? C7 45 EF ? ? ? ?") + 3);
        return *reinterpret_cast<__int64*>((uintptr_t)(this) + offset);
    };
    __int64 getRideRuntimeId(){
        using GetRideRuntimeId = __int64 (__thiscall*)(Actor*);
        static GetRideRuntimeId _GetRideRuntimeId = reinterpret_cast<GetRideRuntimeId>(Mem::findSig("40 53 48 83 EC 20 48 8B DA 48 8B 91 ? ? ? ? 48 83"));
        return _GetRideRuntimeId(this);
    };
    bool* groundState(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("80 BE ? ? ? ? ? ? ? 0F 57 C0 F3 0F 5C") + 2);
        return reinterpret_cast<bool*>((uintptr_t)(this) + offset);
    };
    Vec3<float>* velocity(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("F3 0F 10 82 ? ? ? ? F3 0F 59 C3 F3 0F 11 44 24 ? F3 0F 10 82") + 4);
        return reinterpret_cast<Vec3<float>*>((uintptr_t)(this) + (offset - 0x4));
    };
    Vec2<float>* bodyRot(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("89 87 ? ? ? ? E8 ? ? ? ? 48 8D 97 ? ? ? ? 48 8D 8F") + 2);
        return reinterpret_cast<Vec2<float>*>((uintptr_t)(this) + offset);
    };
    Vec2<float>* collision(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("F3 0F 10 81 ? ? ? ? C3 CC CC CC CC CC CC CC 48 89 5C 24 ? 57 48 83 EC ? 48 8B 01 ") + 4);
        return reinterpret_cast<Vec2<float>*>((uintptr_t)(this) + offset);
    };
    BlockSource* getRegionConst(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 97 ? ? ? ? 48 8B 4D ? E8 ? ? ? ? 90") + 3);
        return *reinterpret_cast<BlockSource**>((uintptr_t)(this) + offset);
    };
    Level* getLevel(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 89 ? ? ? ? 48 8B 01 4C 8D 8B ? ? ? ? 4C") + 3);
        return *reinterpret_cast<Level**>((uintptr_t)(this) + offset);
    };
    Dimension* getDimension(){
        static unsigned int offset = 0;
        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("49 8B 86 ? ? ? ? F3 0F 10 5D ? F3 0F 10 55 ? F3 0F 10 4D ?") + 3);
        return *reinterpret_cast<Dimension**>((uintptr_t)(this) + offset);
    };
private:
    virtual void Constructor();
public:
    virtual void onThreadCreate(char const*);
    virtual void reloadHardcodedClient(int, VariantParameterList*);
    virtual void initializeComponents(int, VariantParameterList*);
    virtual void reloadComponents(int, VariantParameterList*);
    virtual void _serverInitItemStackIds(void);
    virtual void _doInitialMove(void);
private:
    virtual void Function6();
public:
    virtual void reset(void);
    virtual __int64 getOnDeathExperience(void);
    virtual int getOwnerEntityType(void);
    virtual void remove(void);
    virtual void setPos(Vec3<float>*);
private:
    virtual void Function12();
public:
    virtual PredictedMovementValues* getPredictedMovementValues(void);
    virtual Vec3<float>* getPos(void);
    virtual Vec3<float>* getPosOld(void);
    virtual __int64 getPosExtrapolated(float);
    virtual __int64 getAttachPos(ActorLocation, float);
    virtual Vec3<float>* getFiringPos(void);
    virtual void setRot(Vec2<float>*);
    virtual void move(IActorMovementProxy*, Vec3<float>*);
    virtual void move(Vec3<float>*);
    virtual __int64 getInterpolatedRidingPosition(float);
    virtual float getInterpolatedBodyRot(float);
    virtual float getShadowHeightOffs(void);
private:
    virtual void Function25();
public:
    virtual float getYawSpeedInDegreesPerSecond(void);
    virtual float getInterpolatedWalkAnimSpeed(float);
    virtual Vec3<float>* getWorldPosition(void);
    virtual __int64 checkBlockCollisions(AABB*, std::function<void (BlockSource*, Block*, Vec3<float>*, Actor*)>);
    virtual void updateEntityInside(void);
    virtual __int64 updateEntityInside(AABB*);
    virtual bool isFireImmune(void);
private:
    virtual void Function33();
public:
    virtual __int64 blockedByShield(ActorDamageSource*, Actor*);
    virtual void teleportTo(Vec3<float>*, bool, int, int);
    virtual void tryTeleportTo(Vec3<float>*, bool, bool, int, int);
    virtual void chorusFruitTeleport(Vec3<float>*);
    virtual void lerpTo(Vec3<float>*, Vec2<float>*, int);
    virtual void lerpMotion(Vec3<float>*);
    virtual void tryCreateAddActorPacket(void);
    virtual void normalTick(void);
    virtual void baseTick(void);
    virtual void rideTick(void);
    virtual void positionRider(Actor*, float);
    virtual float getRidingHeight(void);
    virtual void startRiding(Actor*);
    virtual void addRider(Actor*);
    virtual void flagRiderToRemove(Actor*);
    virtual __int64 getExitTip(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &, InputMode);
    virtual bool intersects(Vec3<float>*, Vec3<float>*);
    virtual bool isFree(Vec3<float>*);
    virtual bool isFree(Vec3<float>*, float);
    virtual bool isInWall(void);
    virtual bool isInvisible(void);
    virtual bool canShowNameTag(void);
private:
    virtual void Function56();
public:
    virtual void setNameTagVisible(bool);
    virtual char* getNameTag(void);
private:
    virtual void Function59();
public:
    virtual char* getFormattedNameTag(void);
    virtual void filterFormattedNameTag(UIProfanityContext*);
    virtual void setNameTag(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
private:
    virtual void Function63();
public:
    virtual void setScoreTag(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual char* getScoreTag(void);
    virtual bool isInWater(void);
    virtual bool hasEnteredWater(void);
    virtual bool isImmersedInWater(void);
    virtual bool isInLava(void);
    virtual bool isUnderLiquid(MaterialType);
    virtual bool isOverWater(void);
    virtual void setBlockMovementSlowdownMultiplier(Vec3<float>*);
    virtual void resetBlockMovementSlowdownMultiplier(void);
private:
    virtual void Function74();
    virtual void Function75();
public:
    virtual float getShadowRadius(void);
    virtual Vec3<float>* getHeadLookVector(float);
private:
    virtual void Function78();
public:
    virtual bool canSee(Vec3<float>*);
    virtual bool canSee(Actor*);
    virtual __int64 isSkyLit(float);
    virtual __int64 getBrightness(float);
private:
    virtual void Function83();
    virtual void Function84();
public:
    virtual void onAboveBubbleColumn(bool);
    virtual void onInsideBubbleColumn(bool);
    virtual bool isImmobile(void);
    virtual bool isSilent(void);
private:
    virtual void Function89();
    virtual void Function90();
    virtual void Function91();
    virtual void Function92();
public:
    virtual void setSneaking(bool);
private:
    virtual void Function94();
    virtual void Function95();
public:
    virtual bool isAlive(void);
    virtual bool isOnFire(void);
    virtual bool isOnHotBlock(void);
private:
    virtual void Function99();
    virtual void Function100();
    virtual void Function101();
    virtual void Function102();
    virtual void Function103();
public:
    virtual bool isAffectedByWaterBottle(void);
    virtual bool canAttack(Actor*, bool);
    virtual void setTarget(Actor*);
private:
    virtual void Function107();
    virtual void Function108();
public:
    virtual void attack(Actor*, ActorDamageCause*);
    virtual void performRangedAttack(Actor*, float);
private:
    virtual void Function111();
public:
    virtual __int64 getEquipmentCount(void);
    virtual void setOwner(__int64);
    virtual void setSitting(bool);
private:
    virtual void Function115();
    virtual void Function116();
public:
    virtual __int64 getInventorySize(void);
    virtual __int64 getEquipSlots(void);
    virtual __int64 getChestSlots(void);
    virtual void setStanding(bool);
    virtual bool canPowerJump(void);
    virtual void setCanPowerJump(bool);
private:
    virtual void Function123();
    virtual void Function124();
    virtual void Function125();
    virtual void Function126();
public:
    virtual bool shouldRender(void);
    virtual bool isInvulnerableTo(ActorDamageSource*);
    virtual ActorDamageCause* getBlockDamageCause(Block*);
    virtual void actuallyHurt(int, ActorDamageSource*, bool);
private:
    virtual void Function131();
public:
    virtual void doFireHurt(int);
    virtual void onLightningHit(void);
private:
    virtual void Function134();
public:
    virtual void feed(int);
    virtual void handleEntityEvent(ActorEvent, int);
    virtual float getPickRadius(void);
    virtual HashedString* getActorRendererId(void); /* Off 380 */
    virtual ItemActor* spawnAtLocation(ItemStack*, float);
    virtual ItemActor* spawnAtLocation(Block*, int, float);
    virtual ItemActor* spawnAtLocation(Block*, int);
    virtual ItemActor* spawnAtLocation(int, int, float);
    virtual ItemActor* spawnAtLocation(int, int);
    virtual void despawn(void);
    virtual void killed(Actor*);
private:
    virtual void Function146();
public:
    virtual void setArmor(ArmorSlot, ItemStack*);
    virtual ItemStack* getArmor(ArmorSlot);
private:
    virtual void Function149();
    virtual void Function150();
public:
    virtual float getModelScale(void);
    virtual ItemStack* getEquippedSlot(EquipmentSlot);
private:
    virtual void Function153();
public:
    virtual ItemStack* getCarriedItem(void);
    virtual void setCarriedItem(ItemStack*);
    virtual void setOffhandSlot(ItemStack*);
    virtual ItemStack* getEquippedTotem(void);
    virtual void consumeTotem(void);
    virtual void save(CompoundTag*);
    virtual void saveWithoutId(CompoundTag*);
    virtual void load(CompoundTag*, DataLoadHelper*);
    virtual void loadLinks(CompoundTag*, std::vector<ActorLink,std::allocator<ActorLink>>*, DataLoadHelper*);
    virtual uint8_t getEntityTypeId(void);
private:
    virtual void Function164();
public:
    virtual ActorUniqueID* getSourceUniqueID(void);
    virtual void setOnFire(int);
    virtual void extinguishFire(void);
    virtual void thawFreezeEffect(void);
private:
    virtual void Function169();
public:
    virtual bool isWearingLeatherArmor(void);
    virtual AABB* getHandleWaterAABB(void);
    virtual void handleInsidePortal(Vec3<int>*);
    virtual __int64 getPortalCooldown(void);
private:
    virtual void Function174();
public:
    virtual __int64 getDimensionId(void);
private:
    virtual void Function176();
    virtual void Function177();
public:
    virtual void changeDimension(__int64);
    virtual ActorUniqueID* getSourceUniqueID2(void);
    virtual void checkFallDamage(float, bool);
    virtual void causeFallDamage(float, float, ActorDamageSource);
    virtual void handleFallDistanceOnServer(float, float, bool);
    virtual void playSynchronizedSound(LevelSoundEvent, Vec3<float>*, int, bool);
    virtual void playSynchronizedSound(LevelSoundEvent,Vec3<float>*, Block*, bool);
    virtual void onSynchedDataUpdate(int);
    virtual bool canAddRider(Actor*);
private:
    virtual void Function187();
    virtual void Function188();
    virtual void Function189();
    virtual void Function190();
public:
    virtual void tickLeash(void);
    virtual void sendMotionPacketIfNeeded(void);
private:
    virtual void Function193();
public:
    virtual void stopRiding(bool, bool, bool);
    virtual void startSwimming(void);
    virtual void stopSwimming(void);
private:
    virtual void Function197();
public:
    virtual CommandPermissionLevel getCommandPermissionLevel(void);
    virtual bool isClientSide(void);
    virtual AttributeInstance* getMutableAttribute(Attribute*);
    virtual AttributeInstance* getAttribute(Attribute*);
private:
    virtual void Function202();
public:
    virtual void heal(int);
    virtual bool isInvertedHealAndHarm(void);
    virtual bool canBeAffected(MobEffectInstance*);
    virtual bool canBeAffected(int);
    virtual bool canBeAffectedByArrow(MobEffectInstance*);
    virtual void onEffectAdded(MobEffectInstance*);
    virtual void onEffectUpdated(MobEffectInstance*);
    virtual void onEffectRemoved(MobEffectInstance*);
    virtual AnimationComponent* getAnimationComponent(void);
    virtual void openContainerComponent(Player*);
    virtual void swing();
    virtual void useItem(ItemStackBase*, ItemUseMethod, bool);
private:
    virtual void Function215();
    virtual void Function216();
    virtual void Function217();
public:
    virtual float calcGroundFriction(Actor*, Vec3<int>*);
    virtual float getRiderYRotation(Actor*);
    virtual float getYHeadRot(void);
    virtual bool isWorldBuilder(void);
    virtual bool isInCreativeMode(void);
    virtual bool isAdventure(void);
    virtual void add(ItemStack*);
    virtual void drop(ItemStack*, bool);
    virtual bool getInteraction(Player*, ActorInteraction*, Vec3<float>*);
private:
    virtual void Function227();
    virtual void Function228();
public:
    virtual void setSize(float, float);
    virtual __int64 getLifeSpan(void);
    virtual void onOrphan(void);
    virtual void wobble(void);
    virtual bool wasHurt(void);
    virtual void startSpinAttack(void);
private:
    virtual void Function235();
public:
    virtual void setDamageNearbyMobs(bool);
private:
    virtual void Function237();
public:
    virtual void reloadLootTable(EquipmentTableDefinition*);
    virtual void reloadLootTable(void);
    virtual LootTable* getLootTable(void);
private:
    virtual void Function241();
    virtual void Function242();
public:
    virtual void kill(void);
    virtual void die(ActorDamageSource*);
    virtual bool shouldTick(void);
    virtual std::shared_ptr<IActorMovementProxy> createMovementProxy(void);
    virtual std::shared_ptr<IActorMovementProxy> getMovementProxy(void);
    virtual float getNextStep(float);
private:
    virtual void Function249();
    virtual void Function250();
    virtual void Function251();
public:
    virtual bool outOfWorld(void);
    virtual void _hurt(ActorDamageSource*, int, bool, bool);
    virtual void markHurt(void);
    virtual AnimationComponent* _getAnimationComponent(std::shared_ptr<AnimationComponent*>*, AnimationComponentGroup);
    virtual void readAdditionalSaveData(CompoundTag*, DataLoadHelper*);
    virtual void addAdditionalSaveData(CompoundTag*);
    virtual void _playStepSound(Vec3<int>*, Block*);
    virtual void _playFlySound(Vec3<int>*, Block*);
private:
    virtual void Function360();
public:
    virtual void checkInsideBlocks(float);
    virtual void pushOutOfBlocks(Vec3<float>*);
    virtual void updateWaterState(void);
    virtual void doWaterSplashEffect(void);
    virtual void spawnTrailBubbles(void);
    virtual void updateInsideBlock(void);
    virtual void _removeRider(ActorUniqueID*, bool, bool, bool);
    virtual void _onSizeUpdated(void);
private:
    virtual void Function369();
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_ACTOR */