#include "playercharacter.h"

PlayerCharacter::PlayerCharacter(double X, double Y, int W, int H, std::string *fnames)
{	
	type = 1;
	
	position.x = X;
	position.y = Y;
	previous_x = (int)X;
	previous_y = (int)Y;
	
    width = W;
    height = H;
    
    filenames = fnames;
	
	num_keys = 1;
	keys = new unsigned int[num_keys];
    
	xvel = 0;
	yvel = 0;
	vel = 300;
	dir = 1;

	solid = 1;
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
            if (yvel == 0)
                yvel = -vel*2;
            	break;
			case SDLK_LEFT:
			    dir = 0;
                // ensure it doesn't get going to fast (300 is max speed)
                if (xvel > -300 )
                    xvel -= vel;
                break;
			case SDLK_RIGHT:
				dir = 1;
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
	int i;

	bool blocked[4] = {0,0,0,0};
	std::vector<ObjectManager::Collision>* collisions = object_manager->get_collisions(oid);
	for (i = 0; i < collisions->size(); i++)
	{
		unsigned int key = (*collisions)[i].oid;
		switch(object_manager->objects_type(key))
		{
			case 4: //Enemy
				object_manager->objects_delete(key);
				break;
			case 5: //Block
				blocked[(*collisions)[i].type] = 1;
				break;
		}
	}
	delete collisions;

	//Apply gravity
	if (position.y < 460-height)
	{
		yvel += global_gravity*global_timestep;
	}
/*	else
	{
		if (yvel > 0)
			yvel = 0;
		position.y = 460-height;
	}*/

	//Apply movement
	if ((xvel*global_timestep > 0 && blocked[2] == 0) || (xvel*global_timestep < 0 && blocked[0] == 0))
		position.x = position.x + xvel*global_timestep;

	if ((yvel*global_timestep > 0 && blocked[3] == 0) || (yvel*global_timestep < 0 && blocked[1] == 0))
		position.y = position.y + yvel*global_timestep;
	if ((yvel*global_timestep > 0 && blocked[3] == 1) || (yvel*global_timestep < 0 && blocked[1] == 1))
		yvel = 0;

	//Contain blobby
	if (position.x < 0)
		position.x = 0;
	if (position.x > level_manager->get_level_width()-width)
		position.x = level_manager->get_level_width()-width;
	if (position.y > level_manager->get_level_height()-20-height)
	{
		position.y = level_manager->get_level_height()-20-height;
		yvel = 0;
	}

	
	//Move screen
	level_manager->set_level_x( position.x );
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
                // this affects blur
				screen_manager->texture_apply( averaged_x, averaged_y, fixed, width, height, keys[0], dir, 50 );
				
			screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], dir, 255 );
				
			previous_x = (int)position.x;
			previous_y = (int)position.y;
		}
		else
		{
ERROR("Image " << keys[dir] << " failed to load")
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
			keys[i] = screen_manager->texture_load(filenames,2,0,255,0);
			screen_manager->texture_reference(keys[i]);
		}
		
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}