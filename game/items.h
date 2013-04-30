#ifndef _GAME_ITEMS_H_
#define _GAME_ITEMS_H_
#include "../framework/zf_framework.h"
enum ItemType
{
    Type_Resource_Ammo_Small,
    Type_Resource_Ammo_Heavy,
    Type_Resource_Ammo_Bomb,
    Type_Resource_ScrapMetal,
    Type_Equipment_Wrench,
    Type_Equipment_SmallArm,
    Type_Equipment_SniperRifle,
    Type_Equipment_BombLauncher,
    Type_Passive_DoorKey_RED,
    Type_Passive_DoorKey_BLUE,
    Type_Passive_DoorKey_GREEN,
    Type_Passive_Augmentation,
};
class Game;
class Item
{
    public:
        Item(ItemType type,Game* game);
        ~Item();
        ItemType _type;
        Game* _game;
        virtual int getCount();
        virtual void draw(Window* window, float delta, int x , int y) = 0;
        virtual void drawInfo(Window* window, float delta, int x , int y) = 0;
};

class Resource : public Item
{
    public:
        Resource(ItemType type,Game* game,int count);
        ~Resource();
        virtual int getCount();
        int count;
};


class Ammo : public Resource
{
    public:
        Ammo(ItemType type,Game* game,int count);
        ~Ammo(); 
};

class SmallAmmo : public Ammo
{
    public:
        SmallAmmo(Game* game,int count);
        ~SmallAmmo();
        void draw(Window* window, float delta, int x , int y);
        void drawInfo(Window* window, float delta, int x, int y);
};

class BombAmmo : public Ammo
{
    public:
        BombAmmo(Game* game,int count);
        ~BombAmmo();
        void draw(Window* window, float delta, int x , int y);
        void drawInfo(Window* window, float delta, int x, int y);
};


class ScrapMetal : public Resource
{
    public:
        ScrapMetal(Game* game,int count);
        ~ScrapMetal();
        void draw(Window* window, float delta, int x , int y);
        void drawInfo(Window* window, float delta, int x, int y);
};

class Equipment : public Item
{
    public:
        Equipment(ItemType type,Game* game);
        ~Equipment();
};

class Wrench : public Equipment
{
    public:
        Wrench(Game* game);
        ~Wrench();
        void draw(Window* window, float delta, int x , int y);
        void drawInfo(Window* window, float delta, int x, int y);
};

class SmallGun : public Equipment
{
    public:
        SmallGun(Game* game);
        ~SmallGun();
        void draw(Window* window, float delta, int x , int y);
        void drawInfo(Window* window, float delta, int x, int y);
        
};

class BombLauncher : public Equipment
{
    public:
        BombLauncher(Game* game);
        ~BombLauncher();
        void draw(Window* window, float delta, int x , int y);
        void drawInfo(Window* window, float delta, int x, int y);
};
class Passive : public Item
{
    public:
        Passive(ItemType type,Game* game);
        ~Passive();
};

class DoorKey : public Passive
{
    public:
        DoorKey(Game* game,int color);
        ~DoorKey();
        void draw(Window* window, float delta, int x , int y);
        void drawInfo(Window* window, float delta, int x, int y);

        int color;
};

class Augmentation : public Passive
{
    public:
        Augmentation(Game* game,int ap, int hp, int vision);
        ~Augmentation();
        void draw(Window* window, float delta,int x, int y);
        void drawInfo(Window* window, float delta, int x, int y);

        int bonusHp;
        int bonusAp;
        int bonusVision;
};

#endif
