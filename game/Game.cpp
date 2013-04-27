#include "Game.h"
#include "InputManager.h"
#include <iostream>
#include <string>
Game::Game(Display* display, SoundControl* sc)
{
    this->_display = display;
    this->_sound = sc;
    this->_inputs = new InputManager();
    initAssets();
}

Game::~Game()
{
    delete _inputs;
}

void Game::run()
{
    bool quit = false;
    FrameRateRegulator fps = FrameRateRegulator(50);
    EventController events; 

    while(!quit)
    {
        events.update();
        if(events.quit())
        {
            quit = true;
        }
        else
        {
            float delta = fps.frameStart();
            _inputs->processInputs(delta);
            
        }
        fps.frameEnd();
    }
    std::cout << fps.frameCount << " " << fps.tickPassed << std::endl;
    std::cout << fps.averageFPS() << std::endl;
}

void Game::initAssets()
{
    _assets.bots.spriteSheet = _display->createSpriteSheet(Rectangle(32,32),10,10);
    _assets.bots.red.up = _display->createTexture(_assets.bots.spriteSheet,"img/bot/red/up.png");
    _assets.bots.red.right = _display->createTexture(_assets.bots.spriteSheet,"img/bot/red/right.png");
    _assets.bots.red.down = _display->createTexture(_assets.bots.spriteSheet,"img/bot/red/down.png");
    _assets.bots.red.left = _display->createTexture(_assets.bots.spriteSheet,"img/bot/red/left.png");
    _assets.bots.blue.up = _display->createTexture(_assets.bots.spriteSheet,"img/bot/blue/up.png");
    _assets.bots.blue.right = _display->createTexture(_assets.bots.spriteSheet,"img/bot/blue/right.png");
    _assets.bots.blue.down = _display->createTexture(_assets.bots.spriteSheet,"img/bot/blue/down.png");
    _assets.bots.blue.left = _display->createTexture(_assets.bots.spriteSheet,"img/bot/blue/left.png");
    _assets.bots.green.up = _display->createTexture(_assets.bots.spriteSheet,"img/bot/green/up.png");
    _assets.bots.green.right = _display->createTexture(_assets.bots.spriteSheet,"img/bot/green/right.png");
    _assets.bots.green.down = _display->createTexture(_assets.bots.spriteSheet,"img/bot/green/down.png");
    _assets.bots.green.left = _display->createTexture(_assets.bots.spriteSheet,"img/bot/green/left.png");
    _assets.bots.player.up = _display->createTexture(_assets.bots.spriteSheet,"img/bot/player/up.png");
    _assets.bots.player.right = _display->createTexture(_assets.bots.spriteSheet,"img/bot/player/right.png");
    _assets.bots.player.down = _display->createTexture(_assets.bots.spriteSheet,"img/bot/player/down.png");
    _assets.bots.player.left = _display->createTexture(_assets.bots.spriteSheet,"img/bot/player/left.png");

    _assets.inventory.spriteSheet = _display->createSpriteSheet(Rectangle(48,48),5,5);
    _assets.inventory.inventoryBG = _display->createTexture(_assets.inventory.spriteSheet,"img/inventory/inventorybg.png");
    _assets.inventory.ammo = _display->createTexture(_assets.inventory.spriteSheet,"img/inventory/ammo.png");
    _assets.inventory.placeholder = _display->createTexture(_assets.inventory.spriteSheet,"img/inventory/placeholder.png");
    _assets.inventory.scrapmetal = _display->createTexture(_assets.inventory.spriteSheet,"img/inventory/scrapmetal.png");

    _assets.selection.spriteSheet = _display->createSpriteSheet(Rectangle(8,8),2,2);
    _assets.selection.NW = _display->createTexture(_assets.selection.spriteSheet,"img/inventory/selection/NW.png");
    _assets.selection.NE = _display->createTexture(_assets.selection.spriteSheet,"img/inventory/selection/NE.png");
    _assets.selection.SW = _display->createTexture(_assets.selection.spriteSheet,"img/inventory/selection/SW.png");
    _assets.selection.SE = _display->createTexture(_assets.selection.spriteSheet,"img/inventory/selection/SE.png");

    _assets.tiles.spriteSheet = _display->createSpriteSheet(Rectangle(32,32),5,5);
    _assets.tiles.overlay.gray = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/grayoverlay.png");
    _assets.tiles.overlay.black = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/blackoverlay.png");
    _assets.tiles.door.red = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/reddoor.png");
    _assets.tiles.door.green = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/greendoor.png");
    _assets.tiles.door.blue = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/bluedoor.png");
    _assets.tiles.floor = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/floor.png");
    _assets.tiles.wall = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/wall.png");
    _assets.tiles.exit_open = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/exit.png");
    _assets.tiles.exit_locked = _display->createTexture(_assets.tiles.spriteSheet,"img/tiles/exit_locked.png");
    
    _assets.environment.spriteSheet = _display->createSpriteSheet(Rectangle(32,32),5,5);
    _assets.environment.crate = _display->createTexture(_assets.environment.spriteSheet,"img/environments/crate.png");
}
