#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "globals.h"
#include "screenmanager.h"

class Object {
	protected:
		double x;
		double y;
		unsigned int oid;
		std::string *filenames;
		unsigned int num_keys;
		unsigned int *keys;
		int width;
		int height;
		bool loaded;
		bool visible;
		bool solid;
		
	public:
		Object() : width(0), height(0), loaded(0), visible(1), solid(0) {};
		virtual ~Object() {};
	
		double get_x() { return x; }
		double get_y() { return y; }
		std::string *get_filenames() { return filenames; }
		unsigned int get_num_keys() { return (num_keys*loaded); }
		unsigned int *get_keys() { return keys; }	
		bool get_visible() { return visible; }
		
		void set_oid(unsigned int val) { oid = val; }
		
		virtual void step()=0;
		virtual void events(SDL_Event *event)=0;
		virtual void draw()=0;
		virtual void load_surfaces()=0;
};

#endif