#ifndef FLAG_H
#define FLAG_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class Flag : public Object {
private:
	double timed;

public:
    Flag(double X, double Y, int width, int height, std::string *fnames);
    ~Flag();
    
    void step();
    void events(SDL_Event *event) {};
    void draw();
    void load_surfaces();
};

#endif