//titlescreen.cpp

#include "header/titlescreen.hpp"

TitleScreen::TitleScreen()
{
    loadSuccess = true;
    nextState = STATE_NULL;

}

TitleScreen::~TitleScreen()
{
    
}

void TitleScreen::events()
{
    //updates event handler
    eventhandler.update();

    //quitting
    if (eventhandler.windowClosed())
        nextState = STATE_EXIT;
    
    //TODO remove this shit
    if (eventhandler.held(SDLK_k, 250))
        fighter.setPos(100, 100);
    if (eventhandler.tapped(SDLK_o))
        cout << "tap" << endl;
}

void TitleScreen::logic()
{
    
}

void TitleScreen::render()
{
    //clear
    window->clear();
    
    //draw meow
    window->draw(fighter.getFrame());
    
    //render everything
    window->render();
}