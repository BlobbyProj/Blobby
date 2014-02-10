#include "enemy.h"

Enemy::Enemy(double X, double Y, int W, int H, std::string filename)
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

Enemy::~Enemy()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}
    
	delete[] filenames;
	delete keys;
}

void Enemy::draw()
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

void Enemy::load_surfaces()
{
	if (loaded == 0)
	{
		int i;
		for (i = 0; i < num_keys; i++)
		{
            // Makes the blue background transparent
			keys[i] = screen_manager->texture_load(filenames,1,170,204,255);
			screen_manager->texture_reference(keys[i]);
		}
		
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}

void Enemy::step()
{
    
        if (visible == 1 && loaded == 1)
        {
            // need to implement what enemy does each step
        }
            
}

void Enemy::attack()
{
    //implement attack after collisions?
}