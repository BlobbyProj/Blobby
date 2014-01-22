#ifndef OBJECT_H
#define OBJECT_H

#include "globals.h"
#include "screen.h"

class Object {
	protected:
		double X;
		double Y;
		unsigned int OID;
		unsigned int *IID;
		bool Visible;
		
	public:
		double x() { return X; }
		double y() { return Y; }
		unsigned int iid(unsigned int val) { return IID[val]; }	
		bool visible() { return Visible; }
		
		void oid(unsigned int val) { OID = val; }
		
		virtual void step()=0;
		virtual void events(SDL_Event *event)=0;
		virtual void draw()=0;
};

#endif