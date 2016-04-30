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
    Frame* getFrame();      //gets a pointer to the current frame
    
    //setters
    void setPos(int x, int y);
    void updateFrameWithPosition(Frame* f);
        //updates the current frame's position relative to the fighter's position
    
    //movement
    void accelerate(float x, float y);
    
    
private:
    int x, y;               //x and y position
    int direction;          //direction from 0-5, starting at southwest, proceeding counterclockwise
    
    int currentFrame;       //which frame of the current animation is showing?
    int currentMove;        //if we're executing a move: which one?
    float frameRate;        //animation speed (can be delayed for individual frames)
    float next;             //counts until next frame
    
    //frames: contain animation and hit/punish/stand box information
    Frame frame;           //pointer to current frame
    Frame stand[6];         //standing
    //Frame run[6];         //running
    //Move move[??];        //jumping, rolling, attacking
};

#endif