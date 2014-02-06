#include "playercharacter.h"

PlayerCharacter::PlayerCharacter(double X, double Y, int W, int H, std::string filename)
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
	
	vel = 300;
}

PlayerCharacter::~PlayerCharacter()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
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
            if (position.y >= 450-height)
            {
                yvel = -vel*2;
            }
            break;
			case SDLK_LEFT:
                // ensure it doesn't get going to fast (300 is max speed)
                if (xvel > -300 )
                    xvel -= vel;
                break;
			case SDLK_RIGHT:
                if (xvel < 300)
                    xvel += vel;
                break;
		}
	}
    else if (event->type == SDL_KEYUP) {
        switch( event->key.keysym.sym )
        {
            case SDLK_LEFT:
                xvel += vel;
                break;
            case SDLK_RIGHT:
                xvel -= vel;
                break;
        }
    }
}

void PlayerCharacter::step()
{
	position.x = position.x + xvel*global_timestep;
	position.y = position.y + yvel*global_timestep;
	
	if (position.y < 460-height)
	{
		yvel += global_gravity*global_timestep;
	}
	else
	{
		if (yvel > 0)
			yvel = 0;
		position.y = 460-height;
	}
}

void PlayerCharacter::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->texture_exist(keys[0]))
		{	
			int averaged_x = (previous_x+(int)position.x)/2;
			int averaged_y = (previous_y+(int)position.y)/2;
			
			if (averaged_x != (int)position.x || averaged_y != (int)position.y)
				screen_manager->texture_apply( averaged_x, averaged_y, width, height, keys[0], 0, 50 );
				
			screen_manager->texture_apply( (int)position.x, (int)position.y, width, height, keys[0], 0 );
				
			previous_x = (int)position.x;
			previous_y = (int)position.y;
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
			keys[i] = screen_manager->texture_load(filenames,1);
			screen_manager->texture_reference(keys[i]);
		}
		
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}