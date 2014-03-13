#ifndef SPIKE_H
#define SPIKE_H

#include "object.h"

class Spike : public Object {
	private:
	public:
        // constructor for Spike - creates new instance of Spike object
        // param X         x coordinate for location of upper-left corner of Spike
        // param Y         y coordinate for location of upper-left corner of Spike
        // param width     width of Spike in pixels
        // param height    height of Spike in pixels
        // param filename  filename of object image
        // pre-conditions  Spike does not yet exist
        // post-conditions Spike exists
		Spike(double X, double Y, int width, int height, std::string fname, int flags=0);
    
        // destructor for Spike - deletes instance of Enemy object
        // pre-conditions  Spike exists
        // post-conditions Spike no longer exists
		~Spike();
		
        // called every iteration of the game loop; inherited from Object
        // checks if Spike has collided with anything
        // pre-conditions  Spike exists and level currently running
        // post-conditions Spike is moving properly
		void step() {};
    
        // called every time there is an event; inherited from Object
        // Spikes are not effected by events so this function does nothing
		void events(SDL_Event *event) {};
    
        // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height; blurs movement
        // pre-conditions  object is visible and loaded
        // post-conditions object appears on texture
		void draw();
};

#endif
