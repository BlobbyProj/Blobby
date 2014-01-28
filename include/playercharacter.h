#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class PlayerCharacter : public Object {
	private:
		double vel;
		double xvel;
		double yvel;
	public:
		PlayerCharacter(double X, double Y, std::string filename, bool Visible);
		~PlayerCharacter();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif