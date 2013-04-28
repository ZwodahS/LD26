#include "Game.h"
#include "World.h"
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

    //Screen* mainScreen = new MainScreen(this);
    //mainScreen->init(_display,_display->getParentWindow());
    //this->currentScreen = mainScreen;
    
    World w = World(this);
    w.initWorld(generateWorld(10,10));
    w.initEnemies(3);
    Screen* worldScreen = new WorldScreen(this,&w);
    worldScreen->init(_display,_display->getParentWindow());
    this->currentScreen = worldScreen;
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
            _display->clear();
            if(currentScreen->update(_inputs,delta))
            {
                currentScreen->draw(delta);
            }
            _display->flip();
        }
        fps.frameEnd();
    }
    std::cout << fps.frameCount << " " << fps.tickPassed << std::endl;
    std::cout << fps.averageFPS() << std::endl;
}

void Game::initAssets()
{
    _assets.bots.spriteSheet = _display->createSpriteSheet(Rectangle(32,32),10,10);
    _assets.bots.red.up = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/red/up.png");
    _assets.bots.red.right = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/red/right.png");
    _assets.bots.red.down = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/red/down.png");
    _assets.bots.red.left = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/red/left.png");
    _assets.bots.blue.up = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/blue/up.png");
    _assets.bots.blue.right = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/blue/right.png");
    _assets.bots.blue.down = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/blue/down.png");
    _assets.bots.blue.left = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/blue/left.png");
    _assets.bots.green.up = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/green/up.png");
    _assets.bots.green.right = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/green/right.png");
    _assets.bots.green.down = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/green/down.png");
    _assets.bots.green.left = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/green/left.png");
    _assets.bots.player.up = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/player/up.png");
    _assets.bots.player.right = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/player/right.png");
    _assets.bots.player.down = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/player/down.png");
    _assets.bots.player.left = _display->createTexture(_assets.bots.spriteSheet,"assets/img/bots/player/left.png");
    
    _assets.inventory.spriteSheet = _display->createSpriteSheet(Rectangle(48,48),5,5);
    _assets.inventory.inventoryBG = _display->createTexture(_assets.inventory.spriteSheet,"assets/img/inventory/inventorybg.png");
    _assets.inventory.ammo = _display->createTexture(_assets.inventory.spriteSheet,"assets/img/inventory/ammo.png");
    _assets.inventory.scrapmetal = _display->createTexture(_assets.inventory.spriteSheet,"assets/img/inventory/scrapmetal.png");

    _assets.selection.spriteSheet = _display->createSpriteSheet(Rectangle(8,8),2,2);
    _assets.selection.NW = _display->createTexture(_assets.selection.spriteSheet,"assets/img/inventory/selection/NW.png");
    _assets.selection.NE = _display->createTexture(_assets.selection.spriteSheet,"assets/img/inventory/selection/NE.png");
    _assets.selection.SW = _display->createTexture(_assets.selection.spriteSheet,"assets/img/inventory/selection/SW.png");
    _assets.selection.SE = _display->createTexture(_assets.selection.spriteSheet,"assets/img/inventory/selection/SE.png");

    _assets.tiles.spriteSheet = _display->createSpriteSheet(Rectangle(32,32),5,5);
    _assets.tiles.overlay.gray = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/grayoverlay.png");
    _assets.tiles.overlay.black = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/blackoverlay.png");
    _assets.tiles.door.red = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/reddoor.png");
    _assets.tiles.door.green = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/greendoor.png");
    _assets.tiles.door.blue = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/bluedoor.png");
    _assets.tiles.floor = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/floor.png");
    _assets.tiles.wall = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/wall.png");
    _assets.tiles.exit_open = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/exit.png");
    _assets.tiles.exit_locked = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/exit_locked.png");
    _assets.tiles.computer = _display->createTexture(_assets.tiles.spriteSheet,"assets/img/tiles/computer.png");
    
    _assets.environment.spriteSheet = _display->createSpriteSheet(Rectangle(32,32),5,5);
    _assets.environment.crate = _display->createTexture(_assets.environment.spriteSheet,"assets/img/environments/crate.png");

    _assets.fonts.mono = _display->loadTrueTypeFont("assets/fonts/MostlyMono.ttf",72);
}
