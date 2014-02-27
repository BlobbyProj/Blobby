#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "object.h"

class PlayerCharacter : public Object {
	private:
		int previous_x;
		int previous_y;
		double vel;
		double xvel;
		double yvel;
		bool dir;
		bool blocked[4];
		bool pressed[3]; //0 = left, 1 = up, 2 = right
		char lives;
        int score;

	public:
        // constructor for PlayerCharacter - creates new instance of PlayerCharacter object
        // param X         x coordinate for location of upper-left corner of PlayerCharacter
        // param Y         y coordinate for location of upper-left corner of PlayerCharacter
        // param width     width of PlayerCharacter in pixels
        // param height    height of PlayerCharacter in pixels
        // param filename  filename of PlayerCharacter object image
        // pre-conditions  PlayerCharacter does not yet exist
        // post-conditions PlayerCharacter exists
		PlayerCharacter(double X, double Y, int width, int height, std::string *fnames);
    
        // destructor for PlayerCharacter - deletes instance of PlayerCharacter object
        // pre-conditions  PlayerCharacter exists
        // post-conditions PlayerCharacter no longer exists
		~PlayerCharacter();
		
        // called every iteration of the game loop; inherited from Object
        // checks if PlayerCharacter has collided with anything and acts accordingly
        // moves PlayerCharacter and applies gravity
        // post-conditions Any collisions are appropriately dealt with and PlayerCharacter moving correctly
		void step();
    
        // called every time there is an event; inherited from Object
        // changes PlayerCharacter's velocity appropriately depending on event
		void events(SDL_Event *event);
    
        // calls screenmanager->texture_apply to add PlayerCharacter to texture at specified (x,y) position and with specified width, height; blurs movement
        // pre-conditions  PlayerCharacter is visible and loaded
        // post-conditions PlayerCharacter appears on texture
		void draw();
    
        // instructs screenmanager to load the images for the PlayerCharacter
        // pre-conditions  PlayerCharacter's image filename is valid
        // post-conditions PlayerCharacter's image is ready to be shown
		void load_surfaces();
};

#endif