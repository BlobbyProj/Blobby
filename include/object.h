#ifndef OBJECT_H
#define OBJECT_H

#include "main.h"
#include "screen.h"

class Object {
	protected:
		double X;
		double Y;
		unsigned int OID;
		unsigned int IID;
		bool Visible;
	public:
		double x() { return X; }
		double y() { return Y; }
		unsigned int iid() { return IID; }	
		bool visible() { return Visible; }
		
		virtual void step() {};
		virtual void events(SDL_Event *event) {};
};

#endif