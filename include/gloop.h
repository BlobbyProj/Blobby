#ifndef GLOOP_H
#define GLOOP_H

#include "object.h"

class Gloop : public Object {
	private:
		int previous_x;
		int previous_y;
	public:
        // constructor for Gloop - creates new instance of Gloop object
        // param X         x coordinate for location of upper-left corner of Gloop
        // param Y         y coordinate for location of upper-left corner of Gloop
        // param width     width of Gloop in pixels
        // param height    height of Gloop in pixels
        // param filename  filename of object image
        // pre-conditions  Gloop does not yet exist
        // post-conditions Gloop exists
		Gloop(double X, double Y, int width, int height, std::string fname, int flags=0);
    
        // destructor for Gloop - deletes instance of Enemy object
        // pre-conditions  Gloop exists
        // post-conditions Gloop no longer exists
		~Gloop();
		
        // called every iteration of the game loop; inherited from Object
        // checks if Gloop has collided with anything
        // pre-conditions  Gloop exists and level currently running
        // post-conditions Gloop is moving properly
		void step();
    
        // called every time there is an event; inherited from Object
        // Gloops are not effected by events so this function does nothing
		void events(SDL_Event *event) {};
    
        // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height; blurs movement
        // pre-conditions  object is visible and loaded
        // post-conditions object appears on texture
		void draw();
};

#endif
