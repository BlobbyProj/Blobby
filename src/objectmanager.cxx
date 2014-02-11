#include "objectmanager.h"

ObjectManager::~ObjectManager()
{
	int i;
	for (i = 0; i < objects.size(); i++)
		delete objects[i];
	for (i = 0; i < pause_objects.size(); i++)
		delete pause_objects[i];
}

unsigned int ObjectManager::objects_add(Object *object)
{	
	unsigned int oid = objects.size();
	object->set_oid(oid);
	objects.push_back(object);
	return oid;
}

bool ObjectManager::objects_exist(unsigned int val)
{
	if (val < objects.size())
	{
		return 1;
	}
	return 0;
}

bool ObjectManager::objects_delete(unsigned int val)
{
	if (objects_exist(val))
	{
		delete objects[val];
		objects.erase(objects.begin()+val);
		return 0;
	}
	return -1;
}

void ObjectManager::objects_clear()
{
	int i;
	while (objects.size() != 0)
	{
		delete objects[0];
		objects.erase(objects.begin());
	}
}

unsigned int ObjectManager::pause_objects_add(Object *object)
{	
	unsigned int oid = pause_objects.size();
	object->set_oid(oid);
	pause_objects.push_back(object);
	return oid;
}

bool ObjectManager::pause_objects_exist(unsigned int val)
{
	if (val < pause_objects.size())
	{
		return 1;
	}
	return 0;
}

bool ObjectManager::pause_objects_delete(unsigned int val)
{
	if (pause_objects_exist(val))
	{
		delete pause_objects[val];
		pause_objects.erase(pause_objects.begin()+val);
		return 0;
	}
	return -1;
}

void ObjectManager::pause_objects_clear()
{
	int i;
	while (pause_objects.size() != 0)
	{
		delete pause_objects[0];
		pause_objects.erase(pause_objects.begin());
	}
}

void ObjectManager::step()
{
	int i;
	if (global_paused == 0)
	{
		for (i = 0; i < objects.size(); i++)
			objects[i]->step();
	}
	else
	{
		for (i = 0; i < pause_objects.size(); i++)
			pause_objects[i]->step();
	}
}

void ObjectManager::events(SDL_Event *event)
{
	int i;
	if (global_paused == 0)
	{
		for (i = 0; i < objects.size(); i++)
			objects[i]->events(event);
	}
	else
	{
		for (i = 0; i < pause_objects.size(); i++)
			pause_objects[i]->events(event);
	}
}

void ObjectManager::draw()
{
	int i;
	screen_manager->clear(global_background[0],global_background[1],global_background[2]);
	screen_manager->texture_apply(0,0, 640, 480, global_background_key,0);
	if (global_paused == 0)
	{
		for( i = 0; i < objects.size(); i++)
			objects[i]->draw();
	}
	else
	{
		for( i = 0; i < pause_objects.size(); i++)
			pause_objects[i]->draw();
	}
	screen_manager->show();
}

void ObjectManager::load_surfaces()
{
	int i;
	if (global_paused == 0)
	{
		for ( i = 0; i < objects.size(); i++)
			objects[i]->load_surfaces();
	}
	else
	{
		for ( i = 0; i < pause_objects.size(); i++)
			pause_objects[i]->load_surfaces();
	}
}

bool get_collision(unsigned int OID)
{
	return false;
}