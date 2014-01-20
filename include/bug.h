#ifndef BUG_H
#define BUG_H

#include "main.h"
#include "screen.h"
#include "object.h"

class Bug : public Object {
	private:
		double vel;
		double xvel;
		double yvel;
	public:
		Bug(double x, double y, int iid, bool visible);
		
		void step();
		void events(SDL_Event *event);
};

#endif