#include "button.h"

#include "globals.h"
#include "screenmanager.h"
#include "musicmanager.h"

void ButtonPlay(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/play.txt";
		return;
	}

	global_gamestate = 2;
}

void ButtonQuit(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/quit.txt";
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
		*filename = "media/buttons/resume.txt";
		return;
	}
	
	global_paused = 0;
}

void ButtonMainMenu(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/menu.txt";
		return;
	}
	
	global_paused = 0;
	global_gamestate = 0;
}
void ButtonGoBack(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/back.txt";
		return;
	}
	
	global_gamestate = 0;
}

void ButtonInstructions(bool init, std::string *filename)
{
	if (init == 1)
	{
		*filename = "media/buttons/instructions.txt";
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
	if ( event->type == SDL_MOUSEBUTTONDOWN )
	{
		if ( pressed == 0 && event->button.button == SDL_BUTTON_LEFT )
		{
			if ( event->button.x >= position.x && event->button.x <= position.x+width && event->button.y >= position.y && event->button.y <= position.y+height)
			{
				pressed = 1;
			}
		}
	}
	else if( event->type == SDL_MOUSEBUTTONUP )
    {
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
