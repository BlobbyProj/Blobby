#include "image.h"

#include "globals.h"
#include "screenmanager.h"

Image::Image(double X, double Y, int W, int H, std::string fname)
{	
	type = 3;

	filename = fname;

	position.x = X;
	position.y = Y;
    width = W;
    height = H;
}

Image::~Image()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}

	delete[] keys;
}

void Image::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->texture_exist(keys[0]))
		{
			screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], 0);
		}
		else
		{
		ERROR("Image " << keys[0] << " failed to load")
		}
	}
}