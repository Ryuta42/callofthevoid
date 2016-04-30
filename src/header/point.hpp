//point.hpp

#ifndef _POINT_H
#define _POINT_H



class Point
//defines a 2-dimensional vector with some basic trig functions
{
public:
    //constructor
    Point();
    
    //getters
    int getX();
    int getY();
    float angle();     //returns the angle of the vector
    float magnitude();  //returns the magnitude of the vector
    
    //setters
    void setX(int a);
    void setY(int a);
    
private:
    int x, y;
};

#endif