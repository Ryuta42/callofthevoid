/*
    Untitled Game for CIS 422
    By Gabriel Branton, Miles Chew, Joeseph McLaughlin
    
    Build on OS X:
    g++ src/main.cpp src/utility.cpp src/point.cpp src/timer.cpp src/eventhandler.cpp src/rectlist.cpp src/frame.cpp src/fighter.cpp src/window.cpp src/gamestate.cpp src/titlescreen.cpp -o "CotV" -framework SDL2 -framework SDL2_image -framework SDL2_ttf
*/

////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tgmath.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "header/constants.hpp"
#include "header/utility.hpp"
#include "header/point.hpp"
#include "header/timer.hpp"
#include "header/eventhandler.hpp"
#include "header/rectlist.hpp"
#include "header/frame.hpp"
#include "header/fighter.hpp"
#include "header/window.hpp"
#include "header/gamestate.hpp"
#include "header/titlescreen.hpp"

using namespace std;

////////////////////////////////////////

//main.cpp

bool init()
//basic initialization
{
    //seed the random number generator
    srand(time(NULL));

    //initialize SDL
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        cout << "SDL Initialization Error" << endl;
        success = false;
    }
    return success;
}

void cleanup()
//closes SDL
{
    SDL_Quit();
}

int main()
{
    if (init()) //initialize SDL
    {
        //create the window
        Window window;
        
        //create the gamestate and pass it the window
        GameState* gamestate = new TitleScreen();
        gamestate->setWindow(&window);
        
        //we change this when we want to change state
        int stateID = STATE_EXIT;
        
        //did everything initialize properly?
        if (window.getLoadSuccess() and gamestate->getLoadSuccess())
            stateID = STATE_NULL;
        
        //main game loop
        while (stateID != STATE_EXIT)
        {
            //get user input
            gamestate->events();
            
            //do game logic
            gamestate->logic();
            
            //render to the screen
            gamestate->render();
            
            //change state
            stateID = gamestate->getNextState();
            if (stateID != STATE_NULL)
            {
                if (stateID != STATE_EXIT) delete gamestate; //delete the old gamestate
                switch (stateID)
                {
                    default:
                    case STATE_TITLE: //title screen
                        gamestate = new TitleScreen();
                        break;
                }
                gamestate->setWindow(&window); //pass window to new state
            }
            
        }
    }
    
    //exit
    cleanup(); //clean up SDL objects
    return 0;
}
