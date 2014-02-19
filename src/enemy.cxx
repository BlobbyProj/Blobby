#include "enemy.h"

Enemy::Enemy(double X, double Y, int W, int H, std::string filename)
<<<<<<< HEAD
{
	position.x = X;
	position.y = Y;
    width = W;
    height = H;
	
	filenames = new std::string[1];
=======
{	
	position.x = X;
	position.y = Y;
	previous_x = (int)X;
	previous_y = (int)Y;
	
    width = W;
    height = H;
    
	filenames = new std::string;
>>>>>>> 666cf241a082cc9e5df60c32025d8cb959ff2a4b
	filenames[0] = filename;
	
	num_keys = 1;
	keys = new unsigned int[num_keys];
<<<<<<< HEAD
=======
	
	xvel = 0;
	yvel = 0;
	vel = 0;

	solid = 1;
>>>>>>> 666cf241a082cc9e5df60c32025d8cb959ff2a4b
}

Enemy::~Enemy()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}
<<<<<<< HEAD
    
	delete[] filenames;
	delete keys;
=======

	delete filenames;
	delete[] keys;
}

void Enemy::events(SDL_Event *event)
{
	//events code?
}



void Enemy::step()
{
	//~ if(position.x > 300 || position.x < 40){
	if(position.x >= 500){
		xvel = -80;
	}else if(position.x <= 300){
		xvel = 80;
	}
	
	position.x +=  xvel*global_timestep;
	//~ position.x = position.x + vel*global_timestep;
	//~ position.y = position.y + vel*global_timestep;
	
	//~ position.x = position.x + xvel*global_timestep;
	//~ position.y = position.y + yvel*global_timestep;
	
	//~ if (position.y < 460-height)
	//~ {
		//~ yvel += global_gravity*global_timestep;
	//~ }
	//~ else
	//~ {
		//~ if (yvel > 0)
			//~ yvel = 0;
		//~ position.y = 460-height;
	//~ }
>>>>>>> 666cf241a082cc9e5df60c32025d8cb959ff2a4b
}

void Enemy::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->texture_exist(keys[0]))
<<<<<<< HEAD
		{
			screen_manager->texture_apply( (int)position.x, (int)position.y, width, height, keys[0], 0);
		}
		else
		{
            ERROR("Image " << keys[0] << " failed to load")
=======
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
>>>>>>> 666cf241a082cc9e5df60c32025d8cb959ff2a4b
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
<<<<<<< HEAD
			keys[i] = screen_manager->texture_load(filenames,1);
=======
			keys[i] = screen_manager->texture_load(filenames,1,0,255,0);
>>>>>>> 666cf241a082cc9e5df60c32025d8cb959ff2a4b
			screen_manager->texture_reference(keys[i]);
		}
		
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}
<<<<<<< HEAD

void Enemy::step()
{
        while (visible == 1 && loaded == 1)
        {
            position.x += 20;
            position.x -= 20;
        }
            
}

void Enemy::attack()
{
    //implement attack after collisions?
}
=======
>>>>>>> 666cf241a082cc9e5df60c32025d8cb959ff2a4b
