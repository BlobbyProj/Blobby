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
    bool collected;
    double collected_time;
    PlayerCharacter *p;

public:
    // constructor for Powerup - creates new instance of Powerup object
    // param X         x coordinate for location of upper-left corner of Powerup
    // param Y         y coordinate for location of upper-left corner of Powerup
    // param width     width of Powerup in pixels
    // param height    height of Powerup in pixels
    // param fname     text file with the image paths
    // param time      how long the powerup will last
    // pre-conditions  Powerup does not yet exist and fname exists and contains the appropriate image paths
    // post-conditions Powerup exists
    Powerup(double X, double Y, int width, int height, std::string fname, double time, int flags=0);
    
    // destructor for Powerup - deletes instance of Powerup object
    // pre-conditions  Powerup exists
    // post-conditions Powerup no longer exists
    ~Powerup();
    
    // called every iteration of the game loop; inherited from Object
    // Checks for collisions with the player
    // Ensures powerup only lasts for set time
    void step();
    
    // called every time there is an event; inherited from Object
    // Powerup does nothing because once loaded no event affects it
    void events(SDL_Event *event) {};
    
    // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height
    // pre-conditions  object is visible and loaded
    // post-conditions object appears on texture
    void draw();
    
};


#endif
