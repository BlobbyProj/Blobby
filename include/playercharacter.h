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
		PlayerCharacter(double X, double Y, int width, int height, std::string *fnames);
		~PlayerCharacter();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif