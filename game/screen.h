#ifndef _GAME_SCREEN
#define _GAME_SCREEN

#include "InputManager.h"
#include "../framework/zf_framework.h"
class Game;
class InputManager;
class GameData;

class Screen
{
    public:
        Screen(Game* game);
        ~Screen();
        virtual void init(Display* display,Window* parentWindow) = 0;
        virtual bool update(InputManager* controller, float delta) = 0;
        virtual void draw(float delta) = 0;
    protected:
        Game* game;
};

class MainScreen : public Screen
{
    public :
        MainScreen(Game* game);
        ~MainScreen();
        void init(Display* display,Window* parent);
        bool update(InputManager* controller, float delta);
        void draw(float delta);

    private :
        int selection;
        Window* assignedWindow;
};
#endif
