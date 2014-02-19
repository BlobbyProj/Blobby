#ifndef BLOCK_H
#define BLOCK_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class Block : public Object {
public:
    Block(double X, double Y, int width, int height, std::string filename);
    ~Block();
    
    void step() {};
    void events(SDL_Event *event) {};
    void draw();
    void load_surfaces();
};

#endif