#include "image.h"

Image::Image(double X, double Y, int W, int H, std::string filename)
{	
	position.x = X;
	position.y = Y;
    width = W;
    height = H;
	
	filenames = new std::string[1];
	filenames[0] = filename;
	
	num_keys = 1;
	keys = new unsigned int[num_keys];
}

Image::~Image()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}

	delete[] filenames;
	delete keys;
}

void Image::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->texture_exist(keys[0]))
		{
			screen_manager->texture_apply( (int)position.x, (int)position.y, width, height, keys[0], 0);
		}
		else
		{
		ERROR("Image " << keys[0] << " failed to load")
		}
	}
}

void Image::load_surfaces()
{
	if (loaded == 0)
	{
		int i;
		for (i = 0; i < num_keys; i++)
		{
			keys[i] = screen_manager->texture_load(filenames,1);
			screen_manager->texture_reference(keys[i]);
		}
		
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}
