#include "../screen.h"
#include "../objects.h"
#include "../Game.h"
#include <iostream>
GameScreen::GameScreen(Game* game)
    :Screen(game)
{
};
GameScreen::~GameScreen()
{
    if(worldScreen!=NULL)
    {
        delete worldScreen;
    }
    if(invScreen != NULL)
    {
        delete invScreen;
    }
}

void GameScreen::init(Display* display, Window* parent)
{
    assignedWindow = parent->createWindow();
    storedDisplay = display; 
    //ignore saving game for now. Just assume always new game.

    _player = new PlayerBot(game);

    currentWorld = new World(game);
    currentWorld->initWorld(game->generateWorld(4,4));
    currentWorld->initEnemies(1);
    currentWorld->initPlayer(_player);
    worldScreen = new WorldScreen(game,currentWorld,_player);
    worldScreen->init(display,assignedWindow); 
    
    invScreen= NULL;
    statsScreen = NULL;
}
void GameScreen::toggleInventory()
{
    if(invScreen != NULL)
    {
        delete invScreen;
        invScreen = NULL;
    }
    else
    {
        if(statsScreen != NULL)
        {
            toggleStats();
        }
        invScreen = new InventoryScreen(game,_player->inventory);
        invScreen->init(storedDisplay,assignedWindow);
    }
}
void GameScreen::toggleStats()
{
    if(statsScreen != NULL)
    {
        delete statsScreen;
        statsScreen = NULL;
    }
    else
    {
        if(invScreen != NULL)
        {
            toggleInventory();
        }
        statsScreen = new StatsScreen(game,_player);
        statsScreen->init(storedDisplay,assignedWindow);
    }
}
bool GameScreen::update(InputManager* inputs, float delta)
{
    if(inputs->inventory.thisPressed)
    {
        toggleInventory();
    }
    else if(inputs->stats.thisPressed)
    {
        toggleStats();
    }
    else if(invScreen != NULL)
    {
        invScreen->update(inputs,delta);
    }
    else
    {
        if(worldScreen != NULL)
        {
            worldScreen->update(inputs,delta);
        }
    }
}

void GameScreen::draw(float delta)
{
    if(worldScreen != NULL)
    {
        worldScreen->draw(delta);
        std::string info = "HP:";
        info+= toString(_player->getCurrentHp());
        info+= "/";
        info+= toString(_player->getMaxHp());
        info+= "         ";
        info+= "Action:";
        info+= toString(_player->getActionPoints());
        assignedWindow->drawString(info,game->_assets.fonts.mono36,Color(0,0,0),5,5);


    }
    if(invScreen != NULL)
    {
        invScreen->draw(delta);
    }
    if(statsScreen != NULL)
    {
        statsScreen->draw(delta);
    }
}
