#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class PlayerCharacter : public Object {
	private:
		int previous_x;
		int previous_y;
		double vel;
		double xvel;
		double yvel;
		
	public:
		PlayerCharacter(double X, double Y, int width, int height, std::string filename);
		~PlayerCharacter();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
    
        Rectangle get_rectangle();
};

#endif