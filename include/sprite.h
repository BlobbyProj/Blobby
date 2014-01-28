#ifndef SPRITE_H
#define SPRITE_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class Sprite : public Object {
	public:
		Sprite(double X, double Y, std::string filename);
		~Sprite();
		
		void step() {};
		void events(SDL_Event *event) {};
		void draw();
		void load_surfaces();
};

#endif