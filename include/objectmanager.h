#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include <map>
#include "globals.h"
#include "screenmanager.h"
#include "object.h"
#include "rectangle.h"

class ObjectManager {
	private:
		//std::vector<Object*> objects;
		//std::vector<Object*> pause_objects;
		unsigned int count;
		unsigned int pause_count;

		std::map<unsigned int,Object*> objects;
		std::map<unsigned int,Object*> pause_objects;
		
	public:
		ObjectManager() : count(0), pause_count(0) {};
		~ObjectManager();
		
		unsigned int objects_add(Object *object);
		bool objects_exist(unsigned int key);
		bool objects_delete(unsigned int key);
		void objects_clear();

		unsigned int pause_objects_add(Object *object);
		bool pause_objects_exist(unsigned int key);		
		bool pause_objects_delete(unsigned int key);
		void pause_objects_clear();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();

		std::vector<unsigned int>* get_collisions(unsigned int OID);
};

#endif