#include "objectmanager.h"

ObjectManager::~ObjectManager()
{
	int i;
	for (i = 0; i < objects.size(); i++)
		delete objects[i];
}

unsigned int ObjectManager::add(Object *object)
{	
	unsigned int oid = objects.size();
	object->set_oid(oid);
	objects.push_back(object);
	return oid;
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

void ObjectManager::draw()
{

	int i;
	screen->clear(global_background[0],global_background[1],global_background[2]);
	
	for( i = 0; i < objects.size(); i++)
	{
		objects[i]->draw();
/*		if (objects[i]->visible() == 1)
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
		}*/
	}
	screen->flip();
}
