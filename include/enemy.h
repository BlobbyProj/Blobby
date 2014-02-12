#ifndef ENEMY_H
#define ENEMY_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class Enemy : public Object {
public:
    Enemy(double X, double Y, int width, int height, std::string filename);
    ~Enemy();
    
    void step();
    void events(SDL_Event *event){};
    void draw();
    void load_surfaces();
    void attack();
};


#endif