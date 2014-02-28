//TODO: Fix Comments ***

#include "gloop.h"

Gloop::Gloop(double X, double Y, int W, int H, std::string filename)
{
	type = 7;

	position.x = X;
	position.y = Y;
	previous_x = (int)X;
	previous_y = (int)Y;
	
    width = W;
    height = H;
    
	filenames = new std::string;
	filenames[0] = filename;
	
	num_keys = 1;
	keys = new unsigned int[num_keys];

	solid = 1;
}

Gloop::~Gloop()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}

	delete filenames;
	delete[] keys;
}

void Gloop::step()
{
	//If not dead
	int i;
	//{left, top, right, bottom}
	bool blocked[4] = {0,0,0,0};
    // if enemy collided with something, reverse velocity
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
ERROR("Image " << keys[0] << " failed to load")
		}
	}
}

void Gloop::load_surfaces()
{
	if (loaded == 0)
	{
		int i;
		for (i = 0; i < num_keys; i++)
		{
			keys[i] = screen_manager->texture_load(filenames,1,0,255,0);
			screen_manager->texture_reference(keys[i]);
		}
		
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}
