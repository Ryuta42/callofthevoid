//frame.cpp

#include "header/frame.hpp"

Frame::Frame(int delayTime, int pos_x, int pos_y, int pos_width, int pos_height,
        int crop_x, int crop_y, int crop_width, int crop_height, int sheet_id)
{
    pos.x = pos_x;
    pos.y = pos_y;
    delay = delayTime;
    pos.w = pos_width;
    pos.h = pos_height;
    crop.x = crop_x;
    crop.y = crop_y;
    crop.w = crop_width;
    crop.h = crop_height;
    sheet = sheet_id;
}

int Frame::getX() { return pos.x; }

int Frame::getY() { return pos.y; }

int Frame::getSheet() { return sheet; }

SDL_Rect Frame::getPos() { return pos; }

SDL_Rect Frame::getCrop() { return crop; }

RectList* Frame::getHitBox()
//returns a pointer to this fighter's list of hit boxes
{
    return &hit;
}

RectList* Frame::getPunishBox()
{
    return &punish;
}

RectList* Frame::getStandBox()
{
    return &stand;
}

void Frame::addHitBox(int x, int y, int w, int h)
{
    hit.addRect(x, y, w, h);
}

void Frame::addPunishBox(int x, int y, int w, int h)
{
    punish.addRect(x, y, w, h);
}

void Frame::addStandBox(int x, int y, int w, int h)
{
    stand.addRect(x, y, w, h);
}

void Frame::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}