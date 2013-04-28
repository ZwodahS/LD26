#ifndef _GAME_GAME_H_
#define _GAME_GAME_H_
#include "InputManager.h"
#include "assets.h"
#include "screen.h"
#include "tiles.h"
#include "../framework/zf_framework.h"
class Game
{
    public:
        Game(Display* display, SoundControl* sc);
        ~Game();

        void run();

        Display* _display;
        SoundControl* _sound;
        InputManager* _inputs;

        Assets _assets;
        std::vector<std::vector<Tile*> > generateWorld(int row , int col);

        void toGameScreen();
    protected:
        Screen* currentScreen;            
    private:
        void initAssets();        

        World* currentWorld;
};
#endif

