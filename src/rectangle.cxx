#include "rectangle.h"

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

bool Rectangle::get_collision(Rectangle bound)
{
    bool overlapX = false;
    bool overlapY = false;
    
    // Case 1: if bound overlaps this from right side (only checking x)
    if ( this->position.x <= bound.position.x && (this->position.x + this->width) >= bound.position.x) {
        overlapX = true;
    }
    
    // Case 2: if bound overlaps this from left side (only checking x)
    if ( bound.position.x <= this->position.x && (bound.position.x + bound.width) >= this->position.x) {
        overlapX = true;
    }
    
    // Case 3: if bound overlaps this from the bottom (checking y)
    if ( bound.position.y <= (this->position.y + height) && bound.position.y >= this->position.y) {
        overlapY = true;
    }
    
    // Case 4: if bound overlaps this from the top (checking y)
    if ( this->position.y <= (bound.position.y + height) && this->position.y >= bound.position.y) {
        overlapY = true;
    }
    
    return (overlapY && overlapX);
}