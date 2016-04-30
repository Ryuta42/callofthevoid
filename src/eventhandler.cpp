//eventhandler.cpp

#include "header/eventhandler.hpp"

EventHandler::EventHandler()
{
    quit = false;
    for (int i = 0; i < 20; i++)
    {
        keys[i] = -1;
        time[i] = 0;
    }
    for (int i = 0; i < 5; i++)
        taps[i] = 0;
}

void EventHandler::update()
{
    timer.update();
    
    while (SDL_PollEvent (&event) )
    {
        if (event.type == SDL_KEYDOWN)
            press(event.key.keysym.sym);
        
        if (event.type == SDL_KEYUP)
            release(event.key.keysym.sym);
        
        if (event.type == SDL_QUIT)
            quit = true;
    }
}

bool EventHandler::windowClosed()
{
    return quit;
}

bool EventHandler::held(int k, int t)
{
    for (int i = 0; i < 20; i++)
        if ((k == keys[i]) and (timer.getTime()-time[i] > t))
            return true;
    
    return false;
}

bool EventHandler::tapped(int k)
{
    for (int i = 0; i < 5; i++)
        if (k == taps[i])
        {
            taps[i] = 0;
            return true;
        }
    return false;
}

void EventHandler::press(int k)
{
    //is it in there?
    for (int i = 0; i < 20; i++)
        if (keys[i] == k)
            return;
    //fill it in if it's not there
    for (int i = 0; i < 20; i++)
        if (keys[i] == -1)
        {
            keys[i] = k;
            time[i] = timer.getTime();
            return;
        }
}

void EventHandler::release(int k)
{
    for (int i = 0; i < 20; i++)
        if (keys[i] == k)
        {
            //release the key
            keys[i] = -1;
            //was it held for a short time?
            if (timer.getTime()-time[i] < 150)
            {
                for (int i = 0; i < 4; i++)
                    taps[i+1] = taps[i];
                taps[0] = k;
            }
        }
}