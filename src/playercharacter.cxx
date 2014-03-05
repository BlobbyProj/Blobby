#include "playercharacter.h"

#include "globals.h"
#include "image.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "musicmanager.h"

PlayerCharacter::PlayerCharacter(double X, double Y, int W, int H, std::string fname, int flags)
{
	apply_flags(flags);
	type = 1;
	
    filename = fname;

	position.x = X;
	position.y = Y;
	previous_x = (int)X;
	previous_y = (int)Y;
	
    width = W;
    height = H;
     
	xvel = 0;
	yvel = 0;
	vel = 300;
	dir = 1;
	blocked[0] = blocked[1] = blocked[2] = blocked[3] = 0;
	pressed[0] = pressed[1] = pressed[2] = 0;
	lives = 1;
    score = 0;

	solid = 1;
    
    music_manager->add_track("media/music/success_short.wav");
    music_manager->add_track("media/music/death.wav");
}

PlayerCharacter::~PlayerCharacter()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}

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
		    	pressed[1] = 1;
            	break;
            case SDLK_LEFT:
                pressed[0] = 1;
                break;
            case SDLK_RIGHT:
                pressed[2] = 1;
                break;
		}
	}
    else if (event->type == SDL_KEYUP)
    {
        switch( event->key.keysym.sym )
        {
			case SDLK_UP:
		    	pressed[1] = 0;
            	break;
            case SDLK_LEFT:
                pressed[0] = 0;
                break;
            case SDLK_RIGHT:
                pressed[2] = 0;
                break;
        }
    }
}

void PlayerCharacter::step()
{
	if (lives < 1) //If dead
	{
		yvel += global_gravity*global_timestep;
		position.y = position.y + yvel*global_timestep;
		if (position.y > HEIGHT) {
			//trashed = 1;
			global_gamestate = 0;
        }
		return;
	}

	//If not dead
	int i;
	blocked[0] = blocked[1] = blocked[2] = blocked[3] = 0;
	std::vector<ObjectManager::Collision>* collisions = object_manager->get_collisions(oid);
	for (i = 0; i < collisions->size(); i++)
	{
		unsigned int key = (*collisions)[i].oid;
		switch(object_manager->objects_type(key))
		{
			case 4: //Enemy
                if (lives < 4) // smaller than enemy
                {
                    lives--;
                    score -= 5;
                }
                else //larger than enemy
                {
                    score += 5;
                }
                if (lives < 1)
                {
                    if (score < 0)
                        score = 0;
                    level_manager->level_end(score);
                    music_manager->play("media/music/death.wav");
                    object_manager->objects_add(new Image(0, 0, WIDTH, HEIGHT, "media/backgrounds/lose.txt", Object::FIXED));
                }
				object_manager->objects_get(key)->set_solid(0);
				break;
			case 5: //Block
				blocked[(*collisions)[i].type] = 1;
				break;
			case 6: //Flag
                time = level_manager->stop_timer();
                score += 60-time;
                level_manager->level_end(score);
                music_manager->play("media/music/success_short.wav");
				object_manager->objects_get(key)->set_solid(0);
				break;
			case 7: //Gloop
				lives += 1;
				position.y -= 16;
				object_manager->objects_get(key)->set_solid(0);
                score += 10;
				//make the score on the screen change!
				//make Blobby grow in size--> blobbyRight and blobbyLeft
				//~ Change left image to :"media/blobbys/blobbyleft.png";
				//~ Change right image to :"media/blobbys/blobbyright.png";

				break;
		}
	}
	delete collisions;
	//Apply gravity
	if (position.y < 460-height)
	{
		yvel += global_gravity*global_timestep;
	}
	else
	{
		blocked[3] = 1;
	}

	//Apply velocity
	if (pressed[1] == 1)
		if (blocked[3] == 1)
			yvel = -vel*2;
	xvel = (pressed[2]*300)-(pressed[0]*300);

	//Apply direction
	if (xvel > 0)
		dir = 1;
	if (xvel < 0)
		dir = 0;

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

	if (lives == 0)
	{
		//object_manager->objects_add(new Image(level_manager->get_level_x(),0, WIDTH, HEIGHT, "media/backgrounds/lose.bmp"));
		yvel = -500;
	}

	//Move screen
	level_manager->set_level_x( position.x );

	width = 16+16*lives;
	height = 16+16*lives;
}

void PlayerCharacter::draw()
{
	if (visible == 1)
	{
		if (loaded == 1)
		{
			//Draw lives
			if (screen_manager->texture_exist(keys[1]))
			{
				int i;
				for (i = 0; i < lives; i++)
					screen_manager->texture_apply( 10+(64*i), 10, 1, 32, 32, keys[1], 0, 255 );
			}
			else
			{
				ERROR("Image " << keys[1] << " failed to load")
			}

			//Draw Blobby
			if (screen_manager->texture_exist(keys[0]))
			{	
				int averaged_x = (previous_x+(int)position.x)/2;
				int averaged_y = (previous_y+(int)position.y)/2;
				
				//If moved add blur
				if (averaged_x != (int)position.x || averaged_y != (int)position.y)
					screen_manager->texture_apply( averaged_x, averaged_y, fixed, width, height, keys[0], dir, 50 );
					
				screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], dir, 255 );

				previous_x = (int)position.x;
				previous_y = (int)position.y;
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