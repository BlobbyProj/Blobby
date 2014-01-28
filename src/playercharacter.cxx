#include "playercharacter.h"

PlayerCharacter::PlayerCharacter(double X, double Y, std::string filename)
{	
	x = X;
	y = Y;
	
	filenames = new std::string;
	filenames[0] = filename;
	
	num_keys = 1;
	keys = new unsigned int[num_keys];
	
	vel = 0.5;
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
			case SDLK_UP: yvel -= vel; break;
			case SDLK_DOWN: yvel += vel; break;
			case SDLK_LEFT: xvel -= vel; break;
			case SDLK_RIGHT: xvel += vel; break;
		}
	}
	else if( event->type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event->key.keysym.sym )
        {
            case SDLK_UP: yvel += vel; break;
            case SDLK_DOWN: yvel -= vel; break;
            case SDLK_LEFT: xvel += vel; break;
            case SDLK_RIGHT: xvel -= vel; break;   
        }        
	}
}

void PlayerCharacter::step()
{
	x = x + xvel;
	y = y + yvel;
}

void PlayerCharacter::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->surface_exist(keys[0]))
		{
			screen_manager->surface_apply( static_cast<int>(x), static_cast<int>(y), keys[0], 0 );
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
		loaded = 1;
	}
}