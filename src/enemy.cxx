#include "enemy.h"

#include "objectmanager.h"

Enemy::Enemy(double X, double Y, int W, int H, std::string fname, int flags)
{
	apply_flags(flags);
	type = 4;

	position.x = X;
	position.y = Y;
	previous_x = (int)X;
	previous_y = (int)Y;
	
    width = W;
    height = H;
    
	filename = fname;
	
	xvel = 80;
	yvel = 0;
	vel = 80;

	solid = 1;
	lives = 1;
}

Enemy::~Enemy()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}

	delete[] keys;
}

void Enemy::step()
{
	if (lives < 1) //If dead
	{
        FallingObj::step();
		return;
	}

	//If not dead
	int i;
	std::vector<ObjectManager::Collision>* collisions = object_manager->get_collisions(oid);
	for (i = 0; i < collisions->size(); i++)
	{
		unsigned int key = (*collisions)[i].oid;
		switch(object_manager->objects_type(key))
		{
			case 1: //Player
				lives--;
				break;
		}
	}
	delete collisions;

	//Apply gravity
	if (position.y < 460-height)
	{
		yvel += global_gravity*global_timestep;
	}
    

	//Apply movement
	if (xvel != 0)
	{
		bool block = false;
		
		Rectangle newbound(position.x + xvel*global_timestep, position.y, width, height);
		collisions = object_manager->get_collisions(oid, newbound);
		for (i = 0; i < collisions->size(); i++)
		{
			unsigned int key = (*collisions)[i].oid;
			if (object_manager->objects_type(key) == 5)
			{
				block = true;
				if (object_manager->objects_get(key)->get_x()+(object_manager->objects_get(key)->get_width()/2.0) > position.x+(width/2.0))
					position.x = object_manager->objects_get(key)->get_x()-width;
				else
					position.x = object_manager->objects_get(key)->get_x()+object_manager->objects_get(key)->get_width();
			}
		}
		delete collisions;
		if (block == false)
			position.x = position.x + xvel*global_timestep;
		else
			xvel = -xvel;
	}

	if (yvel != 0)
	{
		Rectangle newbound(position.x, position.y + yvel*global_timestep, width, height);
		bool block = false;

		collisions = object_manager->get_collisions(oid, newbound);
		for (i = 0; i < collisions->size(); i++)
		{
			unsigned int key = (*collisions)[i].oid;
			if (object_manager->objects_type(key) == 5)
			{
				block = true;
				if (object_manager->objects_get(key)->get_y()+(object_manager->objects_get(key)->get_height()/2.0) > position.y+(height/2.0))
					position.y = object_manager->objects_get(key)->get_y()-height;
				else
					position.y = object_manager->objects_get(key)->get_y()+object_manager->objects_get(key)->get_height()-0.1;
			}
		}
		delete collisions;
		if (block == false)
			position.y = position.y + yvel*global_timestep;
		else
			yvel = 0;
	}

	//Contain enemy
	if (position.x < 0)
        xvel = -1*xvel;
		//position.x = 0;
	if (position.x > level_manager->get_level_width()-width)
		//position.x = level_manager->get_level_width()-width;
        xvel = -1*xvel;
	if (position.y > level_manager->get_level_height()-20-height)
	{
		position.y = level_manager->get_level_height()-20-height;
		yvel = 0;
	}

	if (lives == 0)
		yvel = -200;
}

void Enemy::draw()
{
	if (visible == 1)
	{
		if (loaded == 1)
		{
			if (screen_manager->texture_exist(keys[0]))
			{	
				int averaged_x = (previous_x+(int)position.x)/2;
				int averaged_y = (previous_y+(int)position.y)/2;
				
				if (averaged_x != (int)position.x || averaged_y != (int)position.y)
	                // this affects blur
					screen_manager->texture_apply( averaged_x, averaged_y, fixed, width, height, keys[0], 0, 50 );
					
				screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], 0, 255 );
					
				previous_x = (int)position.x;
				previous_y = (int)position.y;
			}
			else
			{
				ERROR("Image " << keys[0] << " failed to load")
			}
		}
		else
		{
			load_surfaces();
		}
	}
}