#include "objectmanager.h"

ObjectManager::~ObjectManager()
{
	int i;
	for (i = 0; i < objects.size(); i++)
		delete objects[i];
}

void ObjectManager::add(Object *object)
{
	objects.push_back(object);
}

void ObjectManager::step()
{
	int i;
	for (i = 0; i < objects.size(); i++)
		objects[i]->step();
}

void ObjectManager::events(SDL_Event *event)
{
	int i;
	for (i = 0; i < objects.size(); i++)
		objects[i]->events(event);
}

void ObjectManager::draw(Screen *screen)
{
	int i;
	screen->clear(0,0,0);
	for( i = 0; i < objects.size(); i++)
	{
		if (objects[i]->visible() == 1)
		{
			if (screen->surface_exist(objects[i]->iid()))
			{
				screen->surface_apply( static_cast<int>(objects[i]->x())
									 , static_cast<int>(objects[i]->y())
									 , objects[i]->iid() );
			}
			else
			{
ERROR("Image " << objects[i]->iid() << " failed to load")
			}
		}
	}
	screen->flip();
}
