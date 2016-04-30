 //point.cpp

#include <tgmath.h>
#include "header/point.hpp"

Point::Point()
{
    x = 0;
    y = 0;
}

int Point::getX() { return x; }

int Point::getY() { return y; }

float Point::angle() { return atan(y/x); }

float Point::magnitude() { return 0; }; //TODO

void Point::setX(int a) { x = a; }

void Point::setY(int a) { y = a; }