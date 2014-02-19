#include "enemy.h"

Enemy::Enemy(double X, double Y, int W, int H, std::string filename)
{	
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
	
	xvel = 0;
	yvel = 0;
	vel = 0;

	solid = 1;
}

Enemy::~Enemy()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}

	delete filenames;
	delete[] keys;
}

void Enemy::events(SDL_Event *event)
{
	//events code?
}



void Enemy::step()
{
    // set veloctiy based on position
    if(position.x >= 500){
		xvel = -80;
	}else if(position.x <= 300){
		xvel = 80;
	}
	
    // if enemy collided with something, reverse velocity
    std::vector<unsigned int>* collisions = object_manager->get_collisions(oid);
    if (!collisions->empty()){
        xvel = xvel * (-1);
    }
    delete collisions;
    
    position.x +=  xvel*global_timestep;
}

void Enemy::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->texture_exist(keys[0]))
		{	
			int averaged_x = (previous_x+(int)position.x)/2;
			int averaged_y = (previous_y+(int)position.y)/2;
			
			if (averaged_x != (int)position.x || averaged_y != (int)position.y)
                // this affects blur
				screen_manager->texture_apply( averaged_x, averaged_y, width, height, keys[0], 0, 50 );
				
			screen_manager->texture_apply( (int)position.x, (int)position.y, width, height, keys[0], 0, 255 );
				
			previous_x = (int)position.x;
			previous_y = (int)position.y;
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
			keys[i] = screen_manager->texture_load(filenames,1,0,255,0);
			screen_manager->texture_reference(keys[i]);
		}
		
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}
