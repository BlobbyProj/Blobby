#include "rectangle.h"

#include "globals.h"

Rectangle::Rectangle()
{
	position.x = 0;
	position.y = 0;
    width = 0;
    height = 0;
}

Rectangle::Rectangle(Point p, double w, double h)
{
	position = p;
    width = w;
    height = h;
}


Rectangle::Rectangle(double x, double y, double w, double h)
{
    position.x = x;
    position.y = y;
    width = w;
    height = h;
}

unsigned int Rectangle::get_collision(Rectangle bound)
{
/*  
    Collision returned is a value 0-5
    0 = Collsion from the left
    1 = Collision from the top
    2 = Collision from the right
    3 = Collision from the bottom
    4 = No collision

        1
    ---------
    |       |
  0 |       | 2
    |       |
    ---------
        3
*/


    bool left = false;
    bool top = false;
    int overlapX = 0;
    int overlapY = 0;
    
    // Case 1: if bound overlaps from the left (checking x)
    if ( bound.position.x <= position.x && ( bound.position.x + bound.width ) >= position.x )
    {
        overlapX = bound.position.x + bound.width - position.x;
        left = true;
    }

    // Case 2: if bound overlaps from the right (checking x)
    if ( position.x <= bound.position.x && ( position.x + width ) >= bound.position.x )
    {
        overlapX = position.x + width - bound.position.x;
    }
    
    // Case 3: if bound overlaps from the top (checking y)
    if ( bound.position.y <= position.y && ( bound.position.y + bound.height ) >= position.y )
    {
        overlapY = bound.position.y + bound.height - position.y;
        top = true;
    }

    // Case 4: if bound overlaps from the bottom (checking y)
    if ( position.y <= bound.position.y && ( position.y + height ) >= bound.position.y )
    {
        overlapY = position.y + height - bound.position.y;
    }
    
    if (overlapX && overlapY) //If collision
    {
        if (overlapX >= overlapY) //Collision is from top/bottom
        {
            if (top)
                return 1;
            else
                return 3;
        }
        else if (overlapX < overlapY) //Collision is from left/right
        {
            if (left)
                return 0;
            else
                return 2;
        }
        //if diagonal does nothing...
    }
    return 4; //If no collision
}
