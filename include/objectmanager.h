#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include "globals.h"
#include "screen.h"
#include "object.h"

class ObjectManager {
	private:
		std::vector<Object*> objects;
		
	public:
		~ObjectManager();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		unsigned int add(Object *object);
};

#endif