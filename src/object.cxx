#include "object.h"

Rectangle Object::get_rectangle() {
    Rectangle *bound = new Rectangle(position, width, height);
    return *bound;
}