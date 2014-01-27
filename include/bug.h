#ifndef BUG_H
#define BUG_H

#include "globals.h"
#include "screen.h"
#include "object.h"

class Bug : public Object {
	private:
		double vel;
		double xvel;
		double yvel;
	public:
		Bug(double X, double Y, unsigned int IID, bool Visible);
		~Bug();
		
		void step();
		void events(SDL_Event *event);
		void draw();
};

#endif