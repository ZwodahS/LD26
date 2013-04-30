#ifndef _GAME_SCREEN
#define _GAME_SCREEN

#include "World.h"
#include "InputManager.h"
#include "../framework/zf_framework.h"
#include "Inventory.h"
class Game;
class InputManager;
class GameData;

class Screen
{
    public:
        Screen(Game* game);
        ~Screen();
        virtual void init(Display* display,Window* parentWindow) = 0;
        virtual bool update(InputManager* inputs, float delta) = 0;
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
        bool update(InputManager* inputs, float delta);
        void draw(float delta);

    private :
        int selection;
        Window* assignedWindow;
        int color;
};


class WorldScreen : public Screen
{
    public :
        WorldScreen(Game* game,World* world,PlayerBot* player);
        ~WorldScreen();
        void init(Display* display,Window* parent);
        bool update(InputManager* inputs, float delta);
        void draw(float delta);
        void endTurn();
        void newTurn();
        void fireWeapon();
    private :
        CameraWindow* assignedWindow;
        World* world;
        int moveMade;
        
        PlayerBot* _player;
        bool AITurn;
        Weapon* weapon;
        Grid selectedGrid;
};

class CleanupScreen : public Screen
{
    public :
        CleanupScreen(Game* game);
        ~CleanupScreen();
        void init(Display* display,Window* parent);
        bool update(InputManager* inputs, float delta);
        void draw(float delta);

    private :
        Window* assignedWindow;
};

class InventoryScreen : public Screen
{
    public :
        InventoryScreen(Game* game,Inventory* inventory);
        void init(Display* display, Window* parent);
        bool update(InputManager* inputs, float delta);
        void draw(float delta);

    private:
        Inventory* inventory;
        Window* assignedWindow;
        int selectedIndex;
};

class StatsScreen : public Screen
{
    public :
        StatsScreen(Game* game, PlayerBot* player);
        ~StatsScreen();
        void init(Display* display,Window* parent);
        bool update(InputManager* inputs, float delta);
        void draw(float delta);

    private:
        Window* assignedWindow;
        PlayerBot* player;
};
class GameScreen : public Screen
{
    public :
        GameScreen(Game* game);
        ~GameScreen();
        void init(Display* display,Window* parent);
        bool update(InputManager* inputs, float delta);
        void draw(float delta);

    private :
        Window* assignedWindow;
        Display* storedDisplay;

        PlayerBot* _player;

        InventoryScreen* invScreen;
        WorldScreen* worldScreen;
        StatsScreen* statsScreen;

        World* currentWorld;

        void toggleInventory();
        void toggleStats();
};
#endif
