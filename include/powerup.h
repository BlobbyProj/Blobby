#ifndef POWERUP_H
#define POWERUP_H

#include "object.h"
#include "playercharacter.h"

/* 
 This class represents objects that Blobby can collect and will temporarily give him an ability
 */
class Powerup : public Object {
private:
    double time;
    // 1 for ability to kill enemy (default)
    int ability;
    bool collected;
    int collected_time;
    PlayerCharacter *p;

public:
    // param time is how long the powerup will last
    Powerup(double X, double Y, int width, int height, std::string fname, int flags=0, double time=5.0);
    //Powerup(double time);
    ~Powerup();
    void step();
    void events(SDL_Event *event) {};
    void draw();
    int get_ability();
    
};


#endif
