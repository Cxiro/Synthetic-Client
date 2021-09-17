#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_GAMEMODE
#define CLIENT_SYNTHETIC_SDK_CLASSES_GAMEMODE

class GameMode {
public:
    Player* player;
private:
    virtual void Constructor();
public:
    virtual void startDestroyBlock(Vec3<int>*, UCHAR, bool &);
    virtual void destroyBlock(Vec3<int>*, UCHAR);
    virtual void continueDestroyBlock(Vec3<int>*, UCHAR, Vec3<float>*, bool &);
    virtual void stopDestroyBlock(Vec3<int>*);
    virtual void startBuildBlock(Vec3<int>*, UCHAR);
    virtual void buildBlock(Vec3<int>*);
    virtual void continueBuildBlock(Vec3<int>*, UCHAR);
    virtual void stopBuildBlock(void);
    virtual void tick(void);
    virtual float getPickRange(InputMode*, bool);
    virtual void useItem(ItemStack*);
    virtual void useItemOn(ItemStack*, Vec3<int>*, UCHAR, Vec3<float>*, Block const *);
    virtual void interact(Actor*, Vec3<float>*);
    virtual void attack(Actor*);
    virtual void releaseUsingItem(void);
    virtual void setTrialMode(bool);
    virtual bool isInTrialMode(void);
    virtual void registerUpsellScreenCallback(std::function<void (bool)>);
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_GAMEMODE */