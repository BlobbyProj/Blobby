#include "button.h"

#include "musicmanager.h"

void ButtonPlay(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/main_menu/play.txt";
		return;
	}

	global_gamestate = 3;
}

void ButtonQuit(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/main_menu/quit.txt";
		return;
	}
	
	global_gamestate = -1;
}

void ButtonPause(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/pause.txt";
		return;
	}
	
	global_paused = 1;
}

void ButtonResume(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/pause_menu/resume.txt";
		return;
	}
	
	global_paused = 0;
}
void ButtonReplay(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/pause_menu/replay.txt";
		return;
	}
	
	global_paused = 0;
	
	//to ensure that levelmanager->step() reloads the level
	global_previous_gamestate = -2;
	global_gamestate = global_previous_level;

}

void ButtonMainMenu(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/pause_menu/menu.txt";
		return;
	}
	
	global_paused = 0;
	global_gamestate = 0;
}

void ButtonMainMenuSmall(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/scoreboard/mainSmall.txt";
		return;
	}
	
	global_paused = 0;
	global_gamestate = 0;
}

void ButtonGoBack(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/instructions/back.txt";
		return;
	}
	
	global_gamestate = 0;
}

void ButtonInstructions(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/main_menu/instructions.txt";
		return;
	}

	global_gamestate = 1;
}


void ButtonVolume(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/volume.txt";
		return;
	}
    music_manager->toggle();
}

void ButtonIsland1(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/levelmap/island1.txt";
		return;
	}
	global_gamestate = 4;
}

void ButtonIsland2(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/levelmap/island2.txt";
		return;
	}
	global_gamestate = 6;
}

void ButtonIsland3(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/levelmap/island3.txt";
		return;
	}
	global_gamestate = 8;
}

void ButtonContinue(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/scoreboard/continue.txt";
		return;
	}
	int next_level = global_previous_level + 1;
	//if there is a next level
	if(!global_invalid_level){
		global_gamestate = next_level;
	}else{
		global_gamestate = 0;
	}

}

void ButtonLevelMap(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/scoreboard/levelMap.txt";
		return;
	}
	global_gamestate = 3;
}

void ButtonLevelMapPause(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/pause_menu/levelMap.txt";
		return;
	}
    global_paused = 0;
	global_gamestate = 3;
}

Button::Button(double X, double Y, int W, int H, void (*otherFunction)(bool,std::string*), int flags)
{
	apply_flags(flags);
    type = 2;

    position.x = X;
    position.y = Y;
    width = W;
    height = H;

    function = otherFunction;
    (*function)(1,&filename);

    pressed = 0;
    fixed = 1;
    if (function == ButtonVolume){
        if (muted)
            toggle = 1;
        else
            toggle = 0;
    }
    else
        toggle = -1;
}

Button::~Button()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}

	delete[] keys;
}

void Button::events(SDL_Event *event)
{
	switch(event->type){
		case SDL_MOUSEBUTTONDOWN:
			if ( pressed == 0 && event->button.button == SDL_BUTTON_LEFT )
			{
				if ( event->button.x >= position.x && event->button.x <= position.x+width && event->button.y >= position.y && event->button.y <= position.y+height)
				{
					pressed = 1;
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if( pressed == 1 && event->button.button == SDL_BUTTON_LEFT )
			{
				pressed = 0;
				if ( event->button.x >= position.x && event->button.x <= position.x+width && event->button.y >= position.y && event->button.y <= position.y+height)
				{
					(*function)(0,0);
				}
				if (toggle != -1)
					toggle = !toggle;
			}
			break;
		//In order to deal with the mute button getting toggled upon "m" getting pressed
		case SDL_KEYDOWN:
			if(event->key.keysym.sym ==SDLK_m){
				if ( event->button.x >= position.x && event->button.x <= position.x+width && event->button.y >= position.y && event->button.y <= position.y+height)
				{
					(*function)(0,0);
				}
				if (toggle != -1)
					toggle = !toggle;
			}
	}
}

void Button::draw()
{
	if (visible == 1)
	{
		if (loaded == 1)
		{
			if (screen_manager->texture_exist(keys[0]))
			{
	            if (toggle == -1)
	                screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], pressed );
	            else {
	                screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], toggle );
	            }
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
