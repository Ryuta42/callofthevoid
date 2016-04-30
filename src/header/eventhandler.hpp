//eventhandler.hpp

#ifndef _EVENTHANDLER_H
#define _EVENTHANDLER_H

#include <iostream>
#include <SDL2/SDL.h>
#include "timer.hpp"

using namespace std;

class EventHandler
//keeps track of all user input (keyboard/controller)
//TODO: mouse functionality
//TODO: controller functionality
//TODO: tapped doesn't work
{
public:
    //constructors and destructors
    EventHandler();
    
    //public methods
    void update();      //called every frame
    
    //getters
    bool windowClosed();        //was the window closed?
    bool held(int k, int t);    //key k held for t milliseconds?
    bool tapped(int k);         //was key k tapped?
    
private:
    //SDL event object
    SDL_Event event;
    
    //timer
    Timer timer;
    
    //internal methods
    void press(int k);      //flags key as pressed
    void release(int k);    //flags key as unpressed
    int keys[20];           //list of current keys held
    float time[20];         //how long the keys have been held
    int taps[5];            //list of recently tapped keys
    
    //internal variables
    bool quit;
};

#endif