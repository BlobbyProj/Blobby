#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "globals.h"
#include "point.h"

class Rectangle {
private:
    Point position;
    double width;
    double height;
public:
    Rectangle();

    void set_position(Point Position) { position = Position; }
    void set_width(double Width) { width = Width; }
    void set_height(double Height) { height = Height; }

    char get_collision(Rectangle bound);
};

#endif
