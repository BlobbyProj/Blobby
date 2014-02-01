#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include "globals.h"
#include "screenmanager.h"
#include "object.h"
#include "rectangle.h"

class ObjectManager {
	private:
		std::vector<Object*> objects;
		std::vector<Object*> pause_objects;
		
	public:
		~ObjectManager();
		
		unsigned int objects_add(Object *object);
		bool objects_exist(unsigned int val);
		bool objects_delete(unsigned int val);
		void objects_clear();

		unsigned int pause_objects_add(Object *object);
		bool pause_objects_exist(unsigned int val);		
		bool pause_objects_delete(unsigned int val);
		void pause_objects_clear();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif