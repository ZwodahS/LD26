#ifndef _GAME_ASSETS_H_
#define _GAME_ASSETS_H_
#include "../framework/zf_framework.h"

struct InventoryAssets
{
    SpriteSheet spriteSheet;
    Texture inventoryBG;
    Texture smallAmmo;
    Texture bombAmmo;
    Texture scrapmetal;

    Texture bombLauncher;
    Texture smallGun;
    Texture wrench;

    Texture redDoorCard;
    Texture blueDoorCard;
    Texture greenDoorCard;

};

struct EnvironmentAssets
{
    SpriteSheet spriteSheet;
    Texture crate;
};

struct OverlayAssets
{
    Texture gray;
    Texture black;
};

struct DoorAssets
{
    Texture red;
    Texture blue;
    Texture green;   
};

struct TilesAssets
{
    SpriteSheet spriteSheet; // for all tiles assets
    OverlayAssets overlay;
    DoorAssets door;
    Texture floor;
    Texture wall;
    Texture exit_open;
    Texture exit_locked;
    Texture computer;
};

struct PlayerAssets
{
    Texture left;
    Texture right;
    Texture up;
    Texture down;
};

struct GreenBotAssets
{
    Texture left;
    Texture right;
    Texture up;
    Texture down;
};
struct BlueBotAssets
{
    Texture left;
    Texture right;
    Texture up;
    Texture down;
};
struct RedBotAssets
{
    Texture left;
    Texture right;
    Texture up;
    Texture down;
};

struct BotsAssets
{
    SpriteSheet spriteSheet;
    RedBotAssets red;
    BlueBotAssets blue;
    GreenBotAssets green;
    PlayerAssets player;
};

struct SelectionAssets
{
    SpriteSheet spriteSheet;
    Texture NW;
    Texture NE;
    Texture SW;
    Texture SE;    
};

struct FontsAssets
{
    Font* mono20;   
    Font* mono28;
    Font* mono36;
    ~FontsAssets()
    {
        delete mono36;
        delete mono28;
        delete mono20;
    }
};

struct OtherAssets
{
    Texture statsBackground;
    Texture inventoryBackground; 
    ~OtherAssets()
    {
        statsBackground.free();
        inventoryBackground.free();
    }    
};

struct Assets
{
    SelectionAssets selection;
    InventoryAssets inventory;
    EnvironmentAssets environment;
    TilesAssets tiles;
    BotsAssets bots;
    FontsAssets fonts;
    OtherAssets others;
};
#endif
