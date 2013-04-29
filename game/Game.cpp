#include "Game.h"
#include "World.h"
#include "InputManager.h"
#include "objects.h"
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
    Screen* mainScreen = new MainScreen(this);
    mainScreen->init(_display,_display->getParentWindow());
    this->currentScreen = mainScreen;
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
                _display->flip();
            }
        }
        fps.frameEnd();
    }
    std::cout << fps.frameCount << " " << fps.tickPassed << std::endl;
    std::cout << fps.averageFPS() << std::endl;
}

void Game::toGameScreen()
{
    if(currentScreen != NULL)
    {
        delete currentScreen;
    }
    currentScreen = new GameScreen(this);
    currentScreen->init(_display,_display->getParentWindow());
}
