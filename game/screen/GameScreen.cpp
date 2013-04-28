#include "../screen.h"
#include "../objects.h"
#include "../Game.h"
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
    currentWorld->initEnemies(3);
    currentWorld->initPlayer(_player);
    worldScreen = new WorldScreen(game,currentWorld,_player);
    worldScreen->init(display,assignedWindow); 

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
        invScreen = new InventoryScreen(game,_player->inventory);
        invScreen->init(storedDisplay,assignedWindow);
    }
}
bool GameScreen::update(InputManager* inputs, float delta)
{
    if(inputs->inventory.thisPressed)
    {
        toggleInventory();
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
    }
    if(invScreen != NULL)
    {
        invScreen->draw(delta);
    }
}
