#ifndef OBJECT_H
#define OBJECT_H

#include "globals.h"
#include "screen.h"

class Object {
	protected:
		double x;
		double y;
		unsigned int oid;
		unsigned int *iid;
		bool visible;
		
	public:
		double get_x() { return x; }
		double get_y() { return y; }
		unsigned int get_iid(unsigned int val) { return iid[val]; }	
		bool get_visible() { return visible; }
		
		void set_oid(unsigned int val) { oid = val; }
		
		virtual void step()=0;
		virtual void events(SDL_Event *event)=0;
		virtual void draw()=0;
};

#endif