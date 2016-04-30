//fighter.hpp

#ifndef _FIGHTER_H
#define _FIGHTER_H

#include "constants.hpp"
#include "timer.hpp"
#include "frame.hpp"

class Fighter
//an object that is displayed on the screen
//keeps track of animation between frames
{
public:
    //constructors and destructors
    Fighter();
    ~Fighter();
    
    //update method
    void update(Timer* timer);
    
    //getters
    Frame* getFrame();
    
    //setters
    void setPos(int x, int y);
    
    
private:
    int x, y;               //x and y position
    int direction;          //0-5, clockwise from northeast
    int currentFrame;       //which frame is showing?
    int currentMove;        //if we're executing a move: which one?
    float speed;            //animation speed (can be overridden for individual frames)
    float next;             //counts until next frame
    
    //frames: contain animation and hit/punish/stand box information
    Frame* frame;           //pointer to current frame
    Frame stand[6];         //standing
    //Frame run[6];         //running
    //Move move[??];        //jumping, rolling, attacking
};

#endif