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
    // constructor for Rectangle - creates new instance of a Rectangle with width, position, and height set to 0
    // returns Rectangle object
    // pre-conditions   Rectangle does not yet exist
    // post-conditions  Rectangle exists
    Rectangle();

    // constructor for Rectangle - creates new instance of a Rectangle
    // param position  position of upper-left corner using Point with double coordinates (x,y)
    // param width     width of Rectangle in pixels
    // param height    height of Rectangle in pixels
    // returns Rectangle object
    // pre-conditions   Rectangle does not yet exist
    // post-conditions  Rectangle exists
    Rectangle(Point position, double width, double height);

    // setter for position of Rectangle object
    // param Position  position of upper-left corner using Point with double coordinates (x,y)
    // pre-conditions  Rectangle exists
    // post-conditions Rectangle has new position for upper-left corner at Point Position
    void set_position(Point Position) { position = Position; }

    // setter for width of Rectangle object
    // param Width  width of Rectangle in pixels
    // pre-conditions  Rectangle exists
    // post-conditions Rectangle has new width set to Width
    void set_width(double Width) { width = Width; }

    // setter for height of Rectangle object
    // param Height  height of Rectangle in pixels
    // pre-conditions  Rectangle exists
    // post-conditions Rectangle has new height set to Height
    void set_height(double Height) { height = Height; }

    // checks if Rectangle object has collided with other Rectangle object
    // param bound  Rectangle object being checked for collision with this Rectangle object
    // returns unsigned int indicating if a collision has occurred and, if so, on which side (top, bottom, left, right) of bound
    // pre-conditions  two Rectangle objects exist
    // post-conditions have information on where collision has occurred
    unsigned int get_collision(Rectangle bound);
};

#endif
