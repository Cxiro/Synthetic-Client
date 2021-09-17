#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_LEVEL
#define CLIENT_SYNTHETIC_SDK_CLASSES_LEVEL

class Dimension;
class Player;
class Actor;
struct PortalForcer;
struct ChangeDimensionRequest;
struct Spawner;
struct ProjectileFactory;
struct ActorDefinitionGroup;
struct ActorAnimationGroup;
struct ActorAnimationControllerGroup;
struct BlockDefinitionGroup;
struct PropertyGroupManager;
struct ActorSpawnRuleGroup;
struct SpawnGroupRegistry;
struct SpawnSettings;
struct BehaviorTreeGroup;
struct BehaviorFactory;
enum Difficulty { Peaceful = 0, Easy = 1, Normal = 2, Hard = 3 };
class DimensionConversionData;
class ActorUniqueID;
class LevelChunk;
class ActorRuntimeID;
//struct UUID;
struct MinecraftEventing;
struct BiomeRegistry;
struct BlockPalette;
struct FeatureRegistry;
struct FeatureTypeFactory;
struct JigsawStructureRegistry;
struct BiomeComponentFactory;
struct SurfaceBuilderRegistry;
struct LevelListener;
struct PauseManager;
class ActorDamageSource;
struct Explosion;
enum MaterialType;
class NavigationComponent;
struct LevelStorage;
struct LevelData;
struct PhotoStorage;
struct EducationLevelSettings;
struct TickingAreasManager;
struct TickingArea;
enum ParticleType;
struct ActorDefinitionIdentifier;
enum GamePublishSetting;
struct ClientPlayerEventCoordinator;
struct ActorEventCoordinator;
struct BlockEventCoordinator;
struct ItemEventCoordinator;
struct ServerNetworkEventCoordinator;
struct LevelEventCoordinator;
enum LevelEvent;
struct BossEventListener;
enum BossEventUpdateType;
class BossEventPacket;
class ChunkViewSource;
struct Bounds;
struct MolangVariableMap;
struct SavedDataStorage;
struct MapItemSavedData;
struct TaskGroup;
struct ResourcePackManager;
struct TradeTables;
struct ActorFactory;
struct ActorInfoRegistry;
struct EntitySystems;
class EntityNetId;
class Command;
class CommandOrigin;
enum  CommandOriginSystem;
enum CurrentCmdVersion;
struct PlayerMovementSettings;
struct PositionTrackingDBClient;
struct PositionTrackingDBServer;
struct Experiments;
struct UnknownBlockTypeRegistry;

#include "../../../Utils/Utils.h"

#include "Player.h"

class Level {
public:
    virtual ~Level();
    virtual void initialize(__int64, __int64);
    virtual void postProcessResources(void);
    virtual void startLeaveGame(void);
    virtual bool isLeaveGameDone(void);
    virtual Dimension* createDimension(int);
    virtual Dimension* getDimension(int);
    virtual void forEachDimension(std::function<bool (Dimension const &)>);
private:
    virtual void Function8();
public:
    virtual unsigned int getChunkTickRange(void);
    virtual PortalForcer* getPortalForcer(void);
    virtual void requestPlayerChangeDimension(Player &, std::unique_ptr<ChangeDimensionRequest,std::default_delete<ChangeDimensionRequest>>);
    virtual void entityChangeDimension(Actor&, int);
    virtual Spawner* getSpawner(void);
    virtual ProjectileFactory* getProjectileFactory(void);
    virtual ActorDefinitionGroup* getEntityDefinitions(void);
    virtual ActorAnimationGroup* getActorAnimationGroup(void);
    virtual ActorAnimationControllerGroup* getActorAnimationControllerGroup(void);
    virtual BlockDefinitionGroup* getBlockDefinitions(void);
    virtual unsigned __int64 getLastHurtTimestamp(void);
private:
    virtual void Function20();
public:
    virtual PropertyGroupManager* getActorPropertyGroup(void);
    virtual ActorSpawnRuleGroup* getSpawnRules(void);
    virtual SpawnGroupRegistry* getSpawnGroupRegistry(void);
private:
    virtual void Function24();
public:
    virtual SpawnSettings* getSpawnSettings(void);
    virtual void setSpawnSettings(SpawnSettings*);
    virtual BehaviorTreeGroup* getBehaviorTreeGroup(void);
    virtual BehaviorFactory* getBehaviorFactory(void);
    virtual Difficulty getDifficulty(void);
    virtual DimensionConversionData getDimensionConversionData(void);
    virtual float getSpecialMultiplier(int);
    virtual bool hasCommandsEnabled(void);
    virtual bool useMsaGamertagsOnly(void);
    virtual void setMsaGamertagsOnly(bool);
    virtual void addEntity(BlockSource &, std::unique_ptr<Actor,std::default_delete<Actor>>);
    virtual void addGlobalEntity(BlockSource &, std::unique_ptr<Actor,std::default_delete<Actor>>);
    virtual void addAutonomousEntity(BlockSource &, std::unique_ptr<Actor,std::default_delete<Actor>>);
    virtual void addPlayer(std::unique_ptr<Player,std::default_delete<Player>>);
    virtual void suspendPlayer(Player*);
    virtual void resumePlayer(Player*);
    virtual bool isPlayerSuspended(Player*);
    virtual std::unique_ptr<Actor, std::default_delete<Actor>>* takeEntity(ActorUniqueID);
    virtual std::unique_ptr<Actor, std::default_delete<Actor>>* borrowEntity(ActorUniqueID, LevelChunk*);
    virtual Actor* fetchEntity(ActorUniqueID, bool);
    virtual Actor* getRuntimeEntity(ActorRuntimeID, bool);
    virtual Actor* getMob(ActorUniqueID);
    virtual Player* getPlayer(ActorUniqueID);
    virtual Player* getPlayer(UUID*);
    virtual Player* getPlayer(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual Player* getPlayerByXuid(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual Player* getPlayerFromUnknownIdentifier(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual Player* getPlatformPlayer(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual Player* getPlayerFromServerId(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual Player* getRuntimePlayer(ActorRuntimeID);
    virtual Player* getNextPlayer(ActorUniqueID const &, bool);
    virtual Player* getPrevPlayer(ActorUniqueID const &, bool);
    virtual __int64 getNumRemotePlayers(void);
    virtual Player* getPrimaryLocalPlayer(void);
    virtual Player* getRandomPlayer(void);
    virtual __int64 getNewPlayerId(void);
    virtual MinecraftEventing* getEventing(void);
    virtual __int64 getPlayerColor(Player*);
    virtual __int64 getCurrentTick(void);
    virtual __int64 getCurrentServerTick(void);
    virtual void removeAllNonPlayerEntities(ActorUniqueID);
    virtual BiomeRegistry* getBiomeRegistry(void);
private:
    virtual void Function67();
public:
    virtual BlockPalette* getBlockPalette(void);
private:
    virtual void Function69();
public:
    virtual FeatureRegistry* getFeatureRegistry(void);
private:
    virtual void Function71();
public:
    virtual FeatureTypeFactory* getFeatureTypeFactory(void);
private:
    virtual void Function73();
public:
    virtual JigsawStructureRegistry* getJigsawStructureRegistry(void);
private:
    virtual void Function75();
public:
    virtual gsl::not_null<__int64>* getStructureManager(void);
private:
    virtual void Function77();
public:
    virtual BiomeComponentFactory* getBiomeComponentFactory(void);
private:
    virtual void Function79();
public:
    virtual SurfaceBuilderRegistry* getSurfaceBuilderRegistry(void);
private:
    virtual void Function81();
public:
    virtual __int64 getDimensionFactory(void);
private:
    virtual void Function83();
public:
    virtual __int64 getLightTextureImageBuilderFactory(void);
private:
    virtual void Function85();
private:
    virtual void addListener(LevelListener*);
    virtual void removeListener(LevelListener*);
    virtual void tickEntities(void);
    virtual void tickEntitySystems(void);
    virtual PauseManager* getPauseManager(void);
private:
    virtual void Function91();
public:
    virtual void onPlayerDeath(Player &, ActorDamageSource const &);
    virtual void tick(void);
private:
    virtual void Function94();
public:
    virtual void animateTick(Actor*);
    virtual void explode(Explosion*);
    virtual void explode(BlockSource*, Actor*, Vec3<float>*, float, bool, bool, float, bool);
    virtual void spawnParticleEffect(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &, Actor const &, Vec3<float> const &);
    virtual void spawnParticleEffect(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &, Vec3<float> const &, Dimension *);
    virtual void denyEffect(BlockSource &, Vec3<float> const &);
    virtual void potionSplash(Vec3<float> const &, __int64 Color, bool);
    virtual bool checkAndHandleWater(Actor*);
    virtual bool checkMaterial(AABB*, MaterialType, BlockSource*);
    virtual bool extinguishFire(BlockSource*, Vec3<int>*, UCHAR);
    virtual __int64 findPath(Actor &, Actor &, NavigationComponent &);
    virtual __int64 findPath(Actor &, int, int, int, NavigationComponent &);
    virtual void updateSleepingPlayerList(void);
    virtual __int64 getTime(void);
    virtual void setTime(int);
    virtual unsigned int getSeed(void);
    virtual Vec3<int>* getDefaultSpawn(void);
    virtual void setDefaultSpawn(Vec3<int>*);
private:
    virtual void Function113();
public:
    virtual void setDefaultGameType(GameType);
    virtual GameType getDefaultGameType(void);
    virtual void setDifficulty(Difficulty);
    virtual void setMultiplayerGameIntent(bool);
    virtual bool getMultiplayerGameIntent(void);
    virtual void setMultiplayerGame(bool);
    virtual bool isMultiplayerGame(void);
    virtual void setLANBroadcastIntent(bool);
    virtual bool getLANBroadcastIntent(void);
    virtual void setLANBroadcast(bool);
    virtual bool getLANBroadcast(void);
    virtual void setXBLBroadcastIntent(GamePublishSetting);
    virtual GamePublishSetting getXBLBroadcastIntent(void);
    virtual bool hasXBLBroadcastIntent(void);
    virtual void setXBLBroadcastMode(GamePublishSetting);
    virtual GamePublishSetting getXBLBroadcastMode(void);
    virtual bool hasXBLBroadcast(void);
    virtual void setPlatformBroadcastIntent(GamePublishSetting);
    virtual GamePublishSetting getPlatformBroadcastIntent(void);
    virtual bool hasPlatformBroadcastIntent(void);
    virtual void setPlatformBroadcastMode(GamePublishSetting);
    virtual GamePublishSetting getPlatformBroadcastMode(void);
    virtual bool hasPlatformBroadcast(void);
    virtual void setHasLockedBehaviorPack(bool);
private:
    virtual void Function138();
public:
    virtual void setCommandsEnabled(bool);
    virtual void setWorldTemplateOptionsUnlocked(void);
    virtual bool hasLevelStorage(void);
    virtual LevelStorage* getLevelStorage(void);
private:
    virtual void Function143();
public:
    virtual LevelData* getLevelData(void);
private:
    virtual void Function145();
public:
    virtual PhotoStorage* getPhotoStorage(void);
    virtual void createPhotoStorage(void);
    virtual void setEducationLevelSettings(EducationLevelSettings);
    virtual std::optional<EducationLevelSettings> const & getEducationLevelSettings(void);
    virtual void save(void);
    virtual void saveEducationLevelSettings(void);
    virtual void saveLevelData(void);
    virtual void saveGameData(void);
    virtual void saveVillages(void);
    virtual void savePlayers(void);
    virtual void savePlayer(Player*);
    virtual void saveBiomeData(void);
    virtual void saveDirtyChunks(void);
    virtual void saveAdditionalData(void);
    virtual __int64 requestTimedStorageDeferment(void);
    virtual void _checkUserStorage(void);
    virtual void getTickingAreasMgr(void);
    virtual void getTickingArea(UUID*);
    virtual void addParticle(ParticleType, Vec3<float> const &, Vec3<float> const &, int, CompoundTag const *, bool);
    virtual void sendServerLegacyParticle(ParticleType, Vec3<float> const &, Vec3<float> const &,int);
    virtual void playSound(BlockSource &, LevelSoundEvent, Vec3<float> const &, int, ActorDefinitionIdentifier const &, bool, bool);
    virtual void playSound(LevelSoundEvent, Vec3<float> const &, float, float);
    virtual void _handleSoundEvent(LevelSoundEvent, Vec3<float> const &, int, ActorDefinitionIdentifier const &, bool, bool);
    virtual void playSynchronizedSound(BlockSource &, LevelSoundEvent, Vec3<float> const &, int,ActorDefinitionIdentifier const &, bool, bool);
    virtual void playSynchronizedSound(BlockSource &, LevelSoundEvent, Vec3<float> const &, Block const &, ActorDefinitionIdentifier const &, bool, bool);
    virtual void setRemotePlayerEventCoordinator(std::unique_ptr<PlayerEventCoordinator,std::default_delete<PlayerEventCoordinator>> &&);
    virtual PlayerEventCoordinator* getRemotePlayerEventCoordinator(void);
private:
    virtual void Function173();
    virtual void Function174();
public:
    virtual void setClientPlayerEventCoordinator(std::unique_ptr<ClientPlayerEventCoordinator,std::default_delete<ClientPlayerEventCoordinator>> &&);
    virtual ClientPlayerEventCoordinator* getClientPlayerEventCoordinator(void);
    virtual void setActorEventCoordinator(std::unique_ptr<ActorEventCoordinator,std::default_delete<ActorEventCoordinator>> &&);
    virtual ActorEventCoordinator* getActorEventCoordinator(void);
    virtual void setBlockEventCoordinator(std::unique_ptr<BlockEventCoordinator,std::default_delete<BlockEventCoordinator>> &&);
    virtual BlockEventCoordinator* getBlockEventCoordinator(void);
    virtual void setItemEventCoordinator(std::unique_ptr<ItemEventCoordinator,std::default_delete<ItemEventCoordinator>> &&);
    virtual ItemEventCoordinator* getItemEventCoordinator(void);
    virtual void setServerNetworkEventCoordinator(std::unique_ptr<ServerNetworkEventCoordinator,std::default_delete<ServerNetworkEventCoordinator>> &&);
    virtual ServerNetworkEventCoordinator* getServerNetworkEventCoordinator(void);
    virtual LevelEventCoordinator* getLevelEventCoordinator(void);
    virtual void handleLevelEvent(LevelEvent, CompoundTag const &);
    virtual void handleLevelEvent(LevelEvent, Vec3<float> const &, int);
    virtual void handleSoundEvent(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &, Vec3<float> const &, float, float);
    virtual void handleSoundEvent(LevelSoundEvent, Vec3<float> const &, int, ActorDefinitionIdentifier const &, bool, bool);
    virtual void handleStopSoundEvent(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual void handleStopAllSounds(void);
    virtual void broadcastLevelEvent(LevelEvent, CompoundTag const &, Player*);
    virtual void broadcastLevelEvent(LevelEvent, Vec3<float> const &, int, Player*);
    virtual void broadcastLocalEvent(BlockSource &, LevelEvent, Vec3<float> const &, Block const &);
    virtual void broadcastLocalEvent(BlockSource &, LevelEvent, Vec3<float> const &, int);
    virtual void broadcastSoundEvent(BlockSource &, LevelSoundEvent, Vec3<float> const &, int, ActorDefinitionIdentifier const &, bool, bool);
    virtual void broadcastSoundEvent(BlockSource &, LevelSoundEvent, Vec3<float> const &, Block const &, ActorDefinitionIdentifier const &, bool, bool);
    virtual void broadcastActorEvent(Actor &, ActorEvent, int);
    virtual void addBossEventListener(BossEventListener*);
    virtual void removeBossEventListener(BossEventListener*);
    virtual void broadcastBossEvent(BossEventUpdateType);
    virtual void broadcastBossEvent(BossEventUpdateType, ActorUniqueID const &, BossEventPacket const &);
    virtual bool areBossEventListenersReady(void);
    virtual void addChunkViewTracker(std::weak_ptr<ChunkViewSource>);
    virtual void pruneChunkViewTrackers(void);
    virtual void onChunkReload(Bounds const &);
    virtual std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getPlayerNames(void);
    virtual __int64 getActivePlayerCount(void);
    virtual void forEachPlayer(std::function<bool (Player const &)>);
private:
    virtual void Function310();
public:
    virtual Player* findPlayer(std::function<bool (Player const &)>);
    virtual __int64 getUserCount(void);
private:
    virtual void Function313();
    virtual void Function314();
public:
    virtual void onChunkLoaded(ChunkSource*, LevelChunk*);
    virtual void onChunkDiscarded(LevelChunk*);
    virtual void queueEntityRemoval(std::unique_ptr<Actor,std::default_delete<Actor>> &&, bool);
    virtual void removeEntityReferences(Actor*, bool);
    virtual void forceRemoveEntity(Actor*);
    virtual void forceFlushRemovedPlayers(void);
    virtual void loadFunctionManager(void);
    virtual void levelCleanupQueueEntityRemoval(std::unique_ptr<Actor,std::default_delete<Actor>> &&, bool);
    virtual void registerTemporaryPointer(__int64);
    virtual void unregisterTemporaryPointer(__int64);
    virtual void destroyBlock(BlockSource &, Vec3<int>* &, bool);
    virtual void upgradeStorageVersion(__int64);
    virtual void suspendAndSave(void);
    virtual void waitAsyncSuspendWork(void);
    virtual void _destroyEffect(Vec3<int>*, Block*, int);
    virtual void addParticleEffect(HashedString*, Actor*, HashedString*, Vec3<float>*, MolangVariableMap*);
    virtual void addParticleEffect(HashedString*, Vec3<float>*, MolangVariableMap*);
    virtual void addTerrainParticleEffect(Vec3<int>*, Block*, Vec3<float>*, float, float, float);
    virtual void addTerrainSlideEffect(Vec3<int>*, Block*, Vec3<float>*, float, float, float);
    virtual void addBreakingItemParticleEffect(Vec3<float> const &, ParticleType, TextureUVCoordinateSet const &, bool);
    virtual ActorUniqueID getNewUniqueID(void);
    virtual ActorRuntimeID getNextRuntimeID(void);
private:
    virtual void Function336();
    virtual void Function337();
public:
    virtual bool isExporting(void);
    virtual void setIsExporting(bool);
    virtual SavedDataStorage* getSavedData(void);
    virtual MapItemSavedData* getMapSavedData(CompoundTag const *);
private:
    virtual void Function342();
public:
    virtual MapItemSavedData* getMapSavedData(ActorUniqueID);
    virtual void requestMapInfo(ActorUniqueID, bool);
    virtual ActorUniqueID expandMapByID(ActorUniqueID, bool);
    virtual bool copyAndLockMap(ActorUniqueID, ActorUniqueID);
    virtual __int64 createMapSavedData(std::vector<ActorUniqueID,std::allocator<ActorUniqueID>> const &, Vec3<int> const &, int ,int);
    virtual MapItemSavedData* createMapSavedData(ActorUniqueID const &, Vec3<int> const &, int, int);
    virtual __int64 getScreenshotsFolder(void);
    virtual std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getLevelId(void);
    virtual void setLevelId(std::basic_string<char,std::char_traits<char>,std::allocator<char>>);
    virtual TaskGroup* getSyncTasksGroup(void);
    virtual TaskGroup* getIOTasksGroup(void);
    virtual ResourcePackManager* getClientResourcePackManager(void);
    virtual ResourcePackManager* getServerResourcePackManager(void);
    virtual TradeTables* getTradeTables(void);
    virtual void addEntryToTagCache(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual void addEntriesToTagCache(std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>>>>);
    virtual void dropEntryFromTagCache(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual void clearTagCache(void);
    virtual void decrementTagCache(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &, __int64 &);
    virtual void incrementTagCache(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &, __int64 &);
    virtual bool isEdu(void);
    virtual ActorFactory* getActorFactory(void);
private:
    virtual void Function365();
public:
    virtual ActorInfoRegistry* getActorInfoRegistry(void);
    virtual __int64 getEntityRegistryOwner(void);
    virtual EntitySystems* getEntitySystems(void);
    virtual __int64 getLevelEntity(void);
    virtual __int64 _clientHandleAddOwnedEntity(EntityNetId);
    virtual __int64 _clientHandleAddWeakRefEntity(EntityNetId, __int64 const &);
    virtual __int64 _clientHandleRemoveOwnedEntity(EntityNetId);
private:
    virtual void Function373();
public:
    virtual void runCommand(Command &, CommandOrigin &, CommandOriginSystem);
    virtual void runCommand(HashedString const &, CommandOrigin &, CommandOriginSystem, CurrentCmdVersion);
    virtual __int64 getTagRegistry(void);
    virtual PlayerMovementSettings* getPlayerMovementSettings(void);
    virtual void setPlayerMovementSettings(PlayerMovementSettings*);
private:
    virtual void Function378();
public:
    virtual PositionTrackingDBClient* getPositionTrackerDBClient(void);
    virtual PositionTrackingDBServer* getPositionTrackerDBServer(void);
    virtual void flushRunTimeLighting(void);
    virtual void loadBlockDefinitionGroup(Experiments*);
    virtual void initializeBlockDefinitionGroup(void);
    virtual UnknownBlockTypeRegistry* getUnknownBlockTypeRegistry(void);
private:
    virtual void Function385();
public:
    virtual std::unordered_map<UUID, class PlayerListEntry, struct std::hash<UUID>, struct std::equal_to<UUID>, class std::allocator<struct std::pair<UUID const, class PlayerListEntry>>> getPlayerList(void);
private:
    virtual void Function387();
public:
    virtual std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getPlayerXUID(UUID);
    virtual std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getPlayerPlatformOnlineId(UUID);
    virtual Vec3<float>* getGazeDirection(void);
    virtual std::unordered_set<class gsl::not_null<Actor*>, struct std::hash<class gsl::not_null<Actor*>>, struct std::equal_to<class gsl::not_null<Actor*>>, class std::allocator<class gsl::not_null<Actor*>>>* getGlobalEntities(void);
public:

    auto getPlayers() -> std::vector<Player*>{
        auto players = std::vector<Player*>();

        uintptr_t start = (uintptr_t)(this) + 0x58;
        uintptr_t end = (uintptr_t)(this) + 0x60;

        size_t size = (size_t)(end - start) / sizeof(uintptr_t);

        for(size_t I = 0; I < size; I++){
            Player* curr = *reinterpret_cast<Player**>(start + (I * sizeof(uintptr_t)));
            if(curr != nullptr)
                players.push_back(curr);
        };

        return players;
    };

    auto getEntities() -> std::vector<Actor*>{
        std::vector<Actor*> entities = std::vector<Actor*>();

        static unsigned int offset = NULL;

        if(offset == NULL)
            offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 99 ? ? ? ? 48 3B DF ? ? 0F 1F 44 ? ? 48 8B 06") + 3);

        uintptr_t base = (uintptr_t)(this) + offset;
        uintptr_t start = *(uintptr_t*)(base);
        uintptr_t end = *(uintptr_t*)(base + 0x8);

        size_t size = (size_t)(end - start) / sizeof(uintptr_t);

        for(size_t I = 0; I < size; I++){
            Actor* curr = *(Actor**)(start + (I * sizeof(uintptr_t)));
            if(curr != nullptr)
                entities.push_back(curr);
        };

        return entities;
    };
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_LEVEL */
