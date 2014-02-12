#include "objectmanager.h"

ObjectManager::~ObjectManager()
{    
    for( i= objects.begin(); i!=objects.end(); i++){
        delete i->second;
    }
    objects.clear();
    for( i= pause_objects.begin(); i!=pause_objects.end(); i++){
        delete i->second;
    }
    pause_objects.clear();
}

unsigned int ObjectManager::objects_add(Object *object)
{	
	unsigned int oid = objects.size();
	object->set_oid(oid);
    objects.insert(std::pair<unsigned int,Object*>(oid,object));
	return oid;
}

bool ObjectManager::objects_exist(unsigned int OID)
{
	if (objects.find(OID) != objects.end())
    {
		return 1;
	}
	return 0;
}

bool ObjectManager::objects_delete(unsigned int OID)
{
	if (objects_exist(OID))
	{
        delete objects[OID];
        objects.erase(OID);
		return 0;
	}
	return -1;
}

void ObjectManager::objects_clear()
{
    for(i= objects.begin(); i!=objects.end(); i++){
        delete i->second;
    }
    objects.clear();
}

unsigned int ObjectManager::pause_objects_add(Object *object)
{	
	unsigned int oid = pause_objects.size();
	object->set_oid(oid);
    pause_objects.insert(std::pair<unsigned int,Object*>(oid,object));
	return oid;
}

bool ObjectManager::pause_objects_exist(unsigned int OID)
{
	if (pause_objects.find(OID) != pause_objects.end())
    {
		return 1;
	}
	return 0;
}

bool ObjectManager::pause_objects_delete(unsigned int OID)
{
	if (pause_objects_exist(OID))
	{
		delete pause_objects[OID];
        pause_objects.erase(OID);
		return 0;
	}
	return -1;
}

void ObjectManager::pause_objects_clear()
{
    for(i= pause_objects.begin(); i!=pause_objects.end(); i++){
        delete i->second;
    }
    pause_objects.clear();
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