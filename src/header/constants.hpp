//constants.hpp

#ifndef _CONSTANTS_H
#define _CONSTANTS_H

//window title
#define TITLE "Call of the Void v0.1"

//window dimensions
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;
const int PIXEL_RATIO = 2;

//debug
const bool SHOW_BOXES = true;

//game states
enum { STATE_NULL, STATE_TITLE, STATE_EXIT };

//sprite sheets
enum { SHEET_KNIGHT };

//moves
enum { MOVE_NONE };

//directions (counterclockwise from southwest, matching the sprite sheet layout)
enum { SOUTHWEST, SOUTHEAST, EAST, NORTHEAST, NORTHWEST, WEST };

#endif