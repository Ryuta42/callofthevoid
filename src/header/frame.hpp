//frame.hpp

#ifndef _FRAME_H
#define _FRAME_H

#include <SDL2/SDL.h>
#include "rectlist.hpp"

using namespace std;

//frame.hpp

class Frame
//for game objects: characters, collidable terrain, etc.
//contains all draw and collision information
{
public:
    //constructors and destructors
    Frame(){};
    Frame(int delayTime, int pos_x, int pos_y, int pos_width, int pos_height,
        int crop_x, int crop_y, int crop_width, int crop_height, int sheet_id);
    
    //getters
    int getX();
    int getY();
    int getSheet();
    SDL_Rect getPos();
    SDL_Rect getCrop();
    RectList* getHitBox();
    RectList* getPunishBox();
    RectList* getStandBox();
    
    //setters
    void addHitBox(int x, int y, int w, int h);
    void addPunishBox(int x, int y, int w, int h);
    void addStandBox(int x, int y, int w, int h);
    void setPos(int x, int y);
    
    //TODO collision detection
    
private:
    //boxes
    int sheet;                      //which sprite sheet does this use?
    SDL_Rect pos;                   //where to draw in window
    SDL_Rect crop;                  //where to draw from sheet
    SDL_Rect temp;                  //for returning rects
    RectList hit;                   //hit boxes (where your weapons are)
    RectList punish;                //punish boxes (where your vitals are)
    RectList stand;                 //stand boxes (collision between entities)
    int delay;                      //extra delay in ms (for longer frames)
};

#endif