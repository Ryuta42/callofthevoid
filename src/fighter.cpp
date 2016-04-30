//fighter.cpp

#include "header/fighter.hpp"
#include <iostream>

Fighter::Fighter()
{
    //initalize variables
    x = 0;
    y = 0;
    direction = 0;
    currentFrame = 0;
    currentMove = MOVE_NONE;
    frameRate = 0;
    next = 0;
    
    //TODO read from a file instead
    for (int i = 0; i < 6; i++)
    {
        stand[i] = Frame(0, 0, 0, 32, 32, 0, 0, 32, 32, SHEET_KNIGHT);
        stand[i].addPunishBox(11, 13, 8, 10);
        stand[i].addStandBox(11, 24, 8, 5);
    }
}

Fighter::~Fighter()
{
    
}

void Fighter::update(Timer* timer)
{
    float delta = timer->getDelta();
    
    //TODO apply acceleration to velocity
    
    //TODO apply velocity to position
}

Frame* Fighter::getFrame()
{
    //calculate direction
    
    
    //standing
    if (currentMove == MOVE_NONE)
    {
        updateFrameWithPosition(&stand[direction]);
    }
    
    return &frame;
}

void Fighter::setPos(int a, int b)
{
    x = a;
    y = b;
}

void Fighter::updateFrameWithPosition(Frame* f)
{
    frame = *f;
    frame.setPos(x + f->getX(), y + f->getY());
}

void Fighter::accelerate(float x, float y)
{
    //TODO the magnitude of the vector determines % of max acceleration
    //for keyboard/d-pad controls, assume max acceleration
    //translate angle and magnitude into appropriate x/y acceleration
    
}