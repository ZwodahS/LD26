#ifndef _GAME_OBJECTS_H_
#define _GAME_OBJECTS_H_

#include "../framework/zf_framework.h"
class Inventory;
class Game;
class World;
class MapObject
{
    public:
        MapObject(Game* game);
    
        void setLocation(int row, int col);
        void moveLocation(int rowDiff , int colDiff);
        void setPosition(int x , int y);
        virtual void draw(Window* window,float delta) = 0;
        virtual void update(float delta) = 0;
        virtual void alignPosition();
        virtual bool isMoving();
        virtual Point2 getCurrentPosition();
        virtual Point2 getTargetPosition();
        virtual Grid getLocation();
    protected:
        Grid _location; // the current grid position
        Point2 _position; // the current position (draw movement)
        Game* _game;
        int _moveSpeed ; // pixel per secs
        void linearMove(float delta); // move the object directly to the target position.
};

class Bot : public MapObject
{
    public:
        Bot(Game* game);
        
        void faceTo(direction::Direction d);

        int getCurrentHp();
        virtual int getMaxHp();

        bool damage(int amount);
    protected:
        direction::Direction facingDirection; 

        int currentHp;
        int maxHp;
};

class AIBot : public Bot
{
    public:
        AIBot(Game* game);
        
        void resetMoves();
        bool stillHasMoves();
        virtual void processAI(World* world) = 0;
        void moveTowardLastSeen(World* world);
        void randomMove(); // ask the AI to randomly move since not seen
        virtual void updateSight(World* world)=0;
    protected:
        int maxMove;
        int moveLeft;
        bool hasSeen;
        Grid lastSeen;
};

class RedBot : public AIBot
{
    public:
        RedBot(Game* game);
        void draw(Window* window, float delta);
        void update(float delta);
        void processAI(World* world);
        void updateSight(World* world);
};

class BlueBot : public AIBot
{
    public:
        BlueBot(Game* game);
        void draw(Window* window, float delta);
        void update(float delta);
        void processAI(World* world);
        void updateSight(World* world);
};

class GreenBot : public AIBot
{
    public:
        GreenBot(Game* game);
        void draw(Window* window, float delta);
        void update(float delta);
        void processAI(World* world);
        void updateSight(World* world);
};

class PlayerBot : public Bot
{
    public:
        PlayerBot(Game* game);
        void draw(Window* window, float delta);
        void update(float delta);

        
        Inventory* inventory;
        int getActionPoints();
        int getMaxPoints();
        void resetPoints();
        int getMoveCost();
        int getSight();
        void moved();
        bool canMove();
    protected:
        int pointLeft;
        int maxPoint;
};



#endif
