#ifndef _GAME_OBJECTS_H_
#define _GAME_OBJECTS_H_

#include "../framework/zf_framework.h"

class Game;
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
    protected:
        direction::Direction facingDirection; 

};

class RedBot : public Bot
{
    public:
        RedBot(Game* game);
        void draw(Window* window, float delta);
        void update(float delta);
};

class BlueBot : public Bot
{
    public:
        BlueBot(Game* game);
        void draw(Window* window, float delta);
        void update(float delta);
};

class GreenBot : public Bot
{
    public:
        GreenBot(Game* game);
        void draw(Window* window, float delta);
        void update(float delta);
};

class PlayerBot : public Bot
{
    public:
        PlayerBot(Game* game);
        void draw(Window* window, float delta);
        void update(float delta);

        int getMaxMove();

    protected:
};



#endif
