#include "flag.h"

#include "image.h"
#include "objectmanager.h"

Flag::Flag(double X, double Y, int W, int H, std::string fname, int flags)
{
	apply_flags(flags);
	type = 6;
	
	position.x = X;
	position.y = Y;
    width = W;
    height = H;

    timed = 0;
	
	filename = fname;
    
    solid = 1;
}

Flag::~Flag()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}
    
	delete[] keys;
}

void Flag::step()
{
	if (solid == 0)
	{
		if (timed == 0) {
			if (global_gamestate == NUM_LEVELS + 3){
				object_manager->objects_add(new Image(0, 0, WIDTH, HEIGHT, "media/backgrounds/win.txt", Object::FIXED));
			}
			else {
				object_manager->objects_add(new Image(0, 0, WIDTH, HEIGHT, "media/backgrounds/success.txt", Object::FIXED));
		
			}
		}
	timed += global_timestep;
	}
	if (timed >= 2){
		global_gamestate = 2;
	}
}

void Flag::draw()
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
