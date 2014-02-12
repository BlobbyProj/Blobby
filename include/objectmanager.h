#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

//#include <vector>
#include <map>
#include "globals.h"
#include "screenmanager.h"
#include "object.h"
#include "rectangle.h"

class ObjectManager {
	private:
        std::map<unsigned int,Object*> objects;
        std::map<unsigned int,Object*> pause_objects;
        std::map<unsigned int,Object*>::iterator i;
		
	public:
		~ObjectManager();
		
		unsigned int objects_add(Object *object);
		bool objects_exist(unsigned int OID);
		bool objects_delete(unsigned int OID);
		void objects_clear();

		unsigned int pause_objects_add(Object *object);
		bool pause_objects_exist(unsigned int OID);
		bool pause_objects_delete(unsigned int OID);
		void pause_objects_clear();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();

		bool get_collision(unsigned int OID);
};

#endif