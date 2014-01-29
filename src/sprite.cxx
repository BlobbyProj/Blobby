#include "sprite.h"

Sprite::Sprite(double X, double Y, std::string filename)
{	
	x = X;
	y = Y;
	
	filenames = new std::string[1];
	filenames[0] = filename;
	
	num_keys = 1;
	keys = new unsigned int[num_keys];
}

Sprite::~Sprite()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->surface_dereference(keys[i]);
	}

	delete[] filenames;
	delete keys;
}

void Sprite::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->surface_exist(keys[0]))
		{
			screen_manager->surface_apply( (int)x, (int)y, keys[0], 0);
		}
		else
		{
ERROR("Image " << keys[0] << " failed to load")
		}
	}
}

void Sprite::load_surfaces()
{
	if (loaded == 0)
	{
		int i;
		for (i = 0; i < num_keys; i++)
		{	
			keys[i] = screen_manager->surface_load(filenames,1);
			screen_manager->surface_reference(keys[i]);
		}
		
		width = screen_manager->surface_width(keys[0],0);
		height = screen_manager->surface_height(keys[0],0);
		
		loaded = 1;
	}
}