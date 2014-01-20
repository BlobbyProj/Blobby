#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include "main.h"
#include "screen.h"
#include "object.h"

class ObjectManager {
	private:
		std::vector<Object*> objects;
	public:
		~ObjectManager();
		
		void step();
		void events(SDL_Event *event);
		void draw(Screen *screen);
		void add(Object *object);
};

#endif