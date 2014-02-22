#include "flag.h"

Flag::Flag(double X, double Y, int W, int H, std::string *fnames)
{
	type = 6;
	
	position.x = X;
	position.y = Y;
    width = W;
    height = H;

    timed = 0;
	
	filenames = fnames;
	
	num_keys = 2;
	keys = new unsigned int[num_keys];
    
    solid = 1;
}

Flag::~Flag()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}
    
	delete[] filenames;
	delete[] keys;
}

void Flag::step()
{
	if (solid == 0)
		timed += global_timestep;
	if (timed >= 2)
		global_gamestate = 0;
}

void Flag::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->texture_exist(keys[0]))
		{
			screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], 0);
		}
		else
		{
            ERROR("Flag " << keys[0] << " failed to load")
		}
		if (solid == 0)
		{
			if (screen_manager->texture_exist(keys[1]))
			{
				screen_manager->texture_apply( 0, 0, 1, WIDTH, HEIGHT, keys[1], 0);
			}
			else
			{
	            ERROR("Flag " << keys[1] << " failed to load")
			}
		}
	}
}

void Flag::load_surfaces()
{
	if (loaded == 0)
	{
		int i;

		keys[0] = screen_manager->texture_load(filenames,1,0,255,0);
		screen_manager->texture_reference(keys[0]);

		keys[1] = screen_manager->texture_load(&(filenames[1]),1,0,255,0);
		screen_manager->texture_reference(keys[1]);
		
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}
