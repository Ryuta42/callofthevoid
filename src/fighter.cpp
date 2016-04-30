//fighter.cpp

#include "header/fighter.hpp"

Fighter::Fighter()
{
    //initalize variables
    x = 100;
    y = 100;
    direction = 0;
    currentFrame = 0;
    currentMove = MOVE_NONE;
    speed = 1.0;
    next = 0;
    
    //TODO read from a file instead
    for (int i = 0; i < 6; i++)
    {
        stand[i] = Frame(0, 32, 32, 0, 0, 32, 32, SHEET_KNIGHT);
        stand[i].addPunishBox(11, 13, 8, 10);
        stand[i].addStandBox(11, 24, 8, 5);
    }
}

Fighter::~Fighter()
{
    
}

void Fighter::update(Timer* timer)
{
    
}

Frame* Fighter::getFrame()
{
    //calculate direction
    
    
    //standing
    if (currentMove == MOVE_NONE)
    {
        frame = &stand[direction];
    }
        
    frame->setPos(x, y);
    return frame;
}

void Fighter::setPos(int a, int b)
{
    x = a;
    y = b;
}
