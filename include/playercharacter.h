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

	public:
		// constructor for PlayerCharacter - creates new instance of PlayerCharacter object
		// param X         x coordinate for location of upper-left corner of PlayerCharacter
		// param Y         y coordinate for location of upper-left corner of PlayerCharacter
		// param width     width of PlayerCharacter in pixels
		// param height    height of PlayerCharacter in pixels
		// param filename  filename of PlayerCharacter object image
		// pre-conditions  PlayerCharacter does not yet exist
		// post-conditions PlayerCharacter exists
		PlayerCharacter(double X, double Y, int width, int height, std::string filename);

		// destructor for PlayerCharacter - deletes instance of PlayerCharacter object
    	// pre-conditions  PlayerCharacter exists
   		// post-conditions PlayerCharacter no longer exists
		~PlayerCharacter();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif
