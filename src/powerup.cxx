#include "powerup.h"
#include "objectmanager.h"

Powerup::Powerup(double X, double Y, int W, int H, std::string fname, int flags)
{
	apply_flags(flags);
	type = 8;
    
	filename = fname;
    
	position.x = X;
	position.y = Y;
    width = W;
    height = H;
    
    solid = 1;
}

Powerup::~Powerup()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}
    
	delete[] keys;
}

void Powerup::draw()
{
	if (visible == 1)
	{
		if (loaded == 1)
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
		else
		{
			load_surfaces();
		}
	}
}