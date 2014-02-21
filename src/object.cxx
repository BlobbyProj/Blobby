#include "object.h"

Rectangle Object::get_rectangle()
{
    return Rectangle(position, width, height);
}