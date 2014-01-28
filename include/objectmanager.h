#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class ObjectManager {
	private:
		std::vector<Object*> objects;
		
	public:
		~ObjectManager();
		
		unsigned int add(Object *object);
		unsigned int del(unsigned int val);
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif