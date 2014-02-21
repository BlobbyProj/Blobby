#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "globals.h"
#include "screenmanager.h"
#include "levelmanager.h"
#include "point.h"
#include "rectangle.h"

class Object {
	protected:
		Point position;
		unsigned int oid;
		unsigned int type;
		std::string *filenames;
		unsigned int num_keys;
		unsigned int *keys;
		int width;
		int height;
		bool loaded;

		//Characteristics
		bool visible;
		bool solid;
		bool fixed;
		
	public:
		Object() : type(0), width(0), height(0), loaded(0), visible(1), solid(0), fixed(0) {};
		virtual ~Object() {};
	
		double get_x() { return position.x; }
		double get_y() { return position.y; }
		unsigned int get_oid() { return oid; }
		unsigned int get_type() { return type; }
		std::string *get_filenames() { return filenames; }
		unsigned int get_num_keys() { return (num_keys*loaded); }
		unsigned int *get_keys() { return keys; }
		bool get_visible() { return visible; }
		bool get_solid() { return solid; }
        Rectangle get_rectangle();
		
		void set_oid(unsigned int val) { oid = val; }
		
		virtual void step()=0;
		virtual void events(SDL_Event *event)=0;
		virtual void draw()=0;
		virtual void load_surfaces()=0;
    
};

/* Object types:

	0 = Undefined
	1 = PlayerCharacter
	2 = Button
	3 = Image
	4 = Enemy
	5 = Block

*/

#endif
