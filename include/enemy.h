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
		char lives;

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
		
        // called every iteration of the game loop; inherited from Object
        // checks if enemy has collided with anything and adjusts velocity to compensate
        // pre-conditions  Enemy exists and level currently running
        // post-conditions Enemy is moving properly
		void step();
    
        // called every time there is an event; inherited from Object
        // Enemies are not effected by events so this function does nothing
		void events(SDL_Event *event) {};
    
        // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height; blurs movement
        // pre-conditions  object is visible and loaded
        // post-conditions object appears on texture
		void draw();
    
        // instructs screenmanager to load the images for the Enemy
        // pre-conditions  Enemy's image filename is valid
        // post-conditions Enemy's image is ready to be shown
		void load_surfaces();
};

#endif
