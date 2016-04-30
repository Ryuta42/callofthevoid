//titlescreen.hpp

#ifndef _TITLESCREEN_H
#define _TITLESCREEN_H

#include "constants.hpp"
#include "eventhandler.hpp"
#include "fighter.hpp"
#include "gamestate.hpp"

class TitleScreen : public GameState
{
public:
    //constructors and destructors
    TitleScreen();
    ~TitleScreen();
    
    //methods
    void events();
    void logic();
    void render();
    
    //getters
    
private:
    EventHandler eventhandler;
    
    Fighter fighter; //TODO dumb
};

#endif