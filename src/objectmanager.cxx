#include "objectmanager.h"

ObjectManager::~ObjectManager()
{
	objects_clear();
	pause_objects_clear();
}

unsigned int ObjectManager::objects_add(Object *object)
{
	object->set_oid(count);
	objects.insert(std::pair<unsigned int,Object*>(count,object));
	count++;
}

bool ObjectManager::objects_exist(unsigned int key)
{
	if (objects.find(key) != objects.end())
		return 1;
	else
		return 0;
}

bool ObjectManager::objects_delete(unsigned int key)
{
	if (objects_exist(key))
	{
		delete objects[key];
		objects.erase(key);
		return 0;
	}
	return -1;
}

void ObjectManager::objects_clear()
{
	std::map<unsigned int,Object*>::iterator it;
	for (it = objects.begin(); it != objects.end(); ++it)
	{
		delete it->second;
	}
	objects.clear();
	count = 0;
}

unsigned int ObjectManager::pause_objects_add(Object *object)
{
	object->set_oid(pause_count);
	pause_objects.insert(std::pair<unsigned int,Object*>(pause_count,object));
	pause_count++;
}

bool ObjectManager::pause_objects_exist(unsigned int key)
{
	if (pause_objects.find(key) != pause_objects.end())
		return 1;
	else
		return 0;
}

bool ObjectManager::pause_objects_delete(unsigned int key)
{
	if (pause_objects_exist(key))
	{
		delete pause_objects[key];
		pause_objects.erase(key);
		return 0;
	}
	return -1;
}

void ObjectManager::pause_objects_clear()
{
	std::map<unsigned int,Object*>::iterator it;
	for (it = pause_objects.begin(); it != pause_objects.end(); ++it)
	{
		delete it->second;
	}
	pause_objects.clear();
	pause_count = 0;
}

void ObjectManager::step()
{
	if (global_paused == 0)
	{
		std::map<unsigned int,Object*>::iterator it;
		for (it = objects.begin(); it != objects.end(); ++it)
			it->second->step();
	}
	else
	{
		std::map<unsigned int,Object*>::iterator it;
		for (it = pause_objects.begin(); it != pause_objects.end(); ++it)
			it->second->step();
	}
}

void ObjectManager::events(SDL_Event *event)
{
	if (global_paused == 0)
	{
		std::map<unsigned int,Object*>::iterator it;
		for (it = objects.begin(); it != objects.end(); ++it)
			it->second->events(event);
	}
	else
	{
		std::map<unsigned int,Object*>::iterator it;
		for (it = pause_objects.begin(); it != pause_objects.end(); ++it)
			it->second->events(event);
	}
}

void ObjectManager::draw()
{
	screen_manager->clear(global_background[0],global_background[1],global_background[2]);
	screen_manager->texture_apply(0,0, 640, 480, global_background_key,0);
	if (global_paused == 0)
	{
		std::map<unsigned int,Object*>::iterator it;
		for (it = objects.begin(); it != objects.end(); ++it)
			it->second->draw();
	}
	else
	{
		std::map<unsigned int,Object*>::iterator it;
		for (it = pause_objects.begin(); it != pause_objects.end(); ++it)
			it->second->draw();
	}
	screen_manager->show();
}

void ObjectManager::load_surfaces()
{
	if (global_paused == 0)
	{
		std::map<unsigned int,Object*>::iterator it;
		for (it = objects.begin(); it != objects.end(); ++it)
			it->second->load_surfaces();
	}
	else
	{
		std::map<unsigned int,Object*>::iterator it;
		for (it = pause_objects.begin(); it != pause_objects.end(); ++it)
			it->second->load_surfaces();
	}
}

std::vector<unsigned int>* ObjectManager::get_collisions(unsigned int OID)
{
	std::vector<unsigned int>* collisions = new std::vector<unsigned int>;
    
	Rectangle bound = objects[OID]->get_rectangle();
    
	std::map<unsigned int,Object*>::iterator it;
	for (it = objects.begin(); it != objects.end(); ++it)
	{
		if (it->second->get_oid() != OID && it->second->get_solid() == 1)
		{
			if (bound.get_collision(it->second->get_rectangle()) == 1)
			{
				collisions->push_back(it->first);
			}
		}
	}
	return collisions;
}