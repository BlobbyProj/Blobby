#include "gloop.h"

#include "objectmanager.h"

Gloop::Gloop(double X, double Y, int W, int H, std::string fname, int flags)
{
	apply_flags(flags);
	type = 7;
    
	filename = fname;
	
	position.x = X;
	position.y = Y;
	
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

void Gloop::draw()
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