#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle {
private:
    Point position;
    double width;
    double height;
public:
    Rectangle(double x, double y, double width, double height);
};

#endif
