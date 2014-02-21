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
		bool trashed;

		//Characteristics
		bool visible;
		bool solid;
		bool fixed;
		
	public:
        // constructor for Object; sets all variables to default values
        // pre-conditions  Object does not yet exist
        // post-conditions Object exists
		Object() : type(0), width(0), height(0), loaded(0), trashed(0), visible(1), solid(0), fixed(0) {};
    
        // destructor for Object - deletes instance of object, must be defined by subclass
        // pre-conditions  Object exists
        // post-conditions Object no longer exists
		virtual ~Object() {};
	
        // returns x coordinate of position of Object's upper-left corner
		double get_x() { return position.x; }
    
        // returns y coordinate of position of Object's upper-left corner
		double get_y() { return position.y; }
    
        // returns OID of Object
		unsigned int get_oid() { return oid; }
    
        // returns type of object as int (defined below)
		unsigned int get_type() { return type; }
    
        // returns the filenames of the images
		std::string *get_filenames() { return filenames; }
    
        // returns the num_keys of the Object
		unsigned int get_num_keys() { return (num_keys*loaded); }
    
        // returns the keys of the Object
		unsigned int *get_keys() { return keys; }
    
        // returns value of trashed
		bool get_trashed() { return trashed; }
    
        // returns visible or not
		bool get_visible() { return visible; }
    
        // returns solid
		bool get_solid() { return solid; }
    
        // returns the bordering rectangle of an object
        Rectangle get_rectangle();
		
        // sets OID of Object
		void set_oid(unsigned int val) { oid = val; }
    
        // sets value of solid
		void set_solid( bool val ) { solid = val; }
		
        // called every iteration of the game loop; each subclass implements
		virtual void step()=0;
    
        // called every time there is an event; each subclass implements
		virtual void events(SDL_Event *event)=0;
    
        // Object will be drawn to screen; each subclass implements
		virtual void draw()=0;
    
        // called to load the images for the Object; each subclass implements
		virtual void load_surfaces()=0;
    
};

/* Object types:

	0 = Undefined
	1 = PlayerCharacter
	2 = Button
	3 = Image
	4 = Enemy
	5 = Block
	6 = Flag

*/

#endif
