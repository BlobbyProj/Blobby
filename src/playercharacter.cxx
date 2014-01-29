#include "playercharacter.h"

PlayerCharacter::PlayerCharacter(double X, double Y, std::string filename)
{	
	x = X;
	y = Y;
	previous_x = (int)X;
	previous_y = (int)Y;
	
	filenames = new std::string;
	filenames[0] = filename;
	
	num_keys = 1;
	keys = new unsigned int[num_keys];
	
	vel = 300;
}

PlayerCharacter::~PlayerCharacter()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->surface_dereference(keys[i]);
	}

	delete filenames;
	delete[] keys;
}

void PlayerCharacter::events(SDL_Event *event)
{
	if (event->type == SDL_KEYDOWN)
	{
		//Set the proper message surface
		switch( event->key.keysym.sym )
		{
		    case SDLK_UP: 
				if (y >= 450-height)
				{
					FLAG
					yvel = -vel*2; 
				}
				break;
			case SDLK_LEFT: xvel -= vel; break;
			case SDLK_RIGHT: xvel += vel; break;
		}
	}
	else if( event->type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event->key.keysym.sym )
        {
            case SDLK_LEFT: xvel += vel; break;
            case SDLK_RIGHT: xvel -= vel; break;  
        }        
	}
}

void PlayerCharacter::step()
{
	x = x + xvel*global_timestep;
	y = y + yvel*global_timestep;
	
	if (y < 460-height)
	{
		yvel += global_gravity*global_timestep;
	}
	else
	{
		if (yvel > 0)
			yvel = 0;
		y = 460-height;
	}
	
	if (previous_x != (int)x || previous_y != (int)y)
	{
		previous_x = (int)x;
		previous_y = (int)y;
	}
}

void PlayerCharacter::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->surface_exist(keys[0]))
		{
			screen_manager->surface_apply( (int)x, (int)y, keys[0], 0 );
			
			if (previous_x != (int)x || previous_y != (int)y)
				screen_manager->surface_apply( previous_x, previous_y, keys[0], 0 );
				
			previous_x = (int)x;
			previous_y = (int)y;
		}
		else
		{
ERROR("Image " << keys[0] << " failed to load")
		}
	}
}

void PlayerCharacter::load_surfaces()
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