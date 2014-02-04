#ifndef IMAGE_H
#define IMAGE_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class Image : public Object {
	public:
		Image(double X, double Y, int width, int height, std::string filename);
		~Image();
		
		void step() {};
		void events(SDL_Event *event) {};
		void draw();
		void load_surfaces();
};

#endif