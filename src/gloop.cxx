#include "gloop.h"

#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"

Gloop::Gloop(double X, double Y, int W, int H, std::string fname, int flags)
{
	apply_flags(flags);
	type = 7;
    
	filename = fname;
	
	position.x = X;
	position.y = Y;
	previous_x = (int)X;
	previous_y = (int)Y;
	
    width = W;
    height = H;


	solid = 1;
}

Gloop::~Gloop()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}

	delete[] keys;
}

void Gloop::step()
{
	//If not dead
	int i;
	//{left, top, right, bottom}
	bool blocked[4] = {0,0,0,0};
    // if gloop collided with something, reverse velocity
	std::vector<ObjectManager::Collision>* collisions = object_manager->get_collisions(oid);
	for (i = 0; i < collisions->size(); i++)
	{
		unsigned int key = (*collisions)[i].oid;
		switch(object_manager->objects_type(key))
		{
			case 1: //Player
				trashed =1;
				break;
			case 5: //Block
				blocked[(*collisions)[i].type] = 1;
				break;
		}
	}
	delete collisions;



}

void Gloop::draw()
{
	if (visible == 1 && loaded == 1)
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
			load_surfaces();
		}
	}
}