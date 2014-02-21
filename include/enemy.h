#ifndef ENEMY_H
#define ENEMY_H

#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "object.h"

class Enemy : public Object {
	private:
		int previous_x;
		int previous_y;
		double vel;
		double xvel;
		double yvel;
		
	public:
		// constructor for Enemy - creates new instance of Enemy object
		// param X         x coordinate for location of upper-left corner of Enemy
		// param Y         y coordinate for location of upper-left corner of Enemy
		// param width     width of Enemy in pixels
		// param height    height of Enemy in pixels
		// param filename  filename of object image (???)
		// pre-conditions  Enemy does not yet exist
		// post-conditions Enemy exists
		Enemy(double X, double Y, int width, int height, std::string filename);
		
		// destructor for Enemy - deletes instance of Enemy object
    	// pre-conditions  Enemy exists
   		// post-conditions Enemy no longer exists
		~Enemy();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif
