#ifndef CLIENT_SYNTHETIC_SDK_CLASSES_CONTAINER
#define CLIENT_SYNTHETIC_SDK_CLASSES_CONTAINER

struct ContainerContentChangeListener;

class Container {
private:
    virtual ~Container();
    virtual void Function0();
    virtual void Function1();
public:
    virtual void addContentChangeListener(ContainerContentChangeListener*);
    virtual void removeContentChangeListener(ContainerContentChangeListener*);
private:
    virtual void Function4();
public:
    virtual bool hasRoomForItem(ItemStack*);
    virtual void addItem(ItemStack*);
    virtual void addItemToFirstEmptySlot(ItemStack*);
private:
    virtual void Function8();
public:
    virtual void setItemWithForceBalance(int, ItemStack*, bool);
    virtual void removeItem(int, int);
    virtual void removeAllItems(void);
    virtual void dropContents(BlockSource*, Vec3<float>*, bool);
private:
    virtual void Function13();
    virtual void Function14();
    virtual void Function15();
    virtual void Function16();
public:
    virtual std::vector<ItemStack*> getSlotCopies(void);
    virtual std::vector<ItemStack*> getSlots(void);
    virtual int getItemCount(ItemStack*);
    virtual int findFirstSlotForItem(ItemStack*);
private:
    virtual void Function21();
    virtual void Function22();
public:
    virtual void setContainerChanged(int);
    virtual void setContainerMoved(void);
    virtual void setCustomName(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &);
    virtual bool hasCustomName(void);
    virtual void readAdditionalSaveData(CompoundTag*);
    virtual void addAdditionalSaveData(CompoundTag*);
    virtual void createTransactionContext(std::function<void (Container &,int,ItemStack const &,ItemStack const &)>,std::function<void (void)>);
private:
    virtual void Function30();
public:
    virtual bool isEmpty(void);
};

#endif /* CLIENT_SYNTHETIC_SDK_CLASSES_CONTAINER */