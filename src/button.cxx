#include "button.h"

void ButtonPlay(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "images/buttons/PlayUnpressed.bmp";
		filenames[1] = "images/buttons/PlayPressed.bmp";
		return;
	}

	global_gamestate = 1;
}

void ButtonQuit(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "images/buttons/QuitUnpressed.bmp";
		filenames[1] = "images/buttons/QuitPressed.bmp";
		return;
	}
	
	global_gamestate = -1;
}

void ButtonPause(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "images/buttons/PauseUnpressed.bmp";
		filenames[1] = "images/buttons/PausePressed.bmp";
		return;
	}
	
	global_paused = 1;
}

void ButtonResume(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "images/buttons/ResumeUnpressed.bmp";
		filenames[1] = "images/buttons/ResumePressed.bmp";
		return;
	}
	
	global_paused = 0;
}

void ButtonMainMenu(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "images/buttons/MainMenuUnpressed.bmp";
		filenames[1] = "images/buttons/MainMenuPressed.bmp";
		return;
	}
	
	global_paused = 0;
	global_gamestate = 0;
}

Button::Button(double X, double Y, void (*otherFunction)(bool,std::string*))
{	
	x = X;
	y = Y;
	
	function = otherFunction;
	
	filenames = new std::string[2];
	(*function)(1,filenames);
	
	num_keys = 1;
	keys = new unsigned int[num_keys];
	
	pressed = 0;
}

Button::~Button()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->surface_dereference(keys[i]);
	}

	delete[] filenames;
	delete keys;
}

void Button::events(SDL_Event *event)
{
	if ( event->type == SDL_MOUSEBUTTONDOWN )
	{
		if ( pressed == 0 && event->button.button == SDL_BUTTON_LEFT )
		{
			if ( event->button.x >= x && event->button.x <= x+width && event->button.y >= y && event->button.y <= y+height)
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
			if ( event->button.x >= x && event->button.x <= x+width && event->button.y >= y && event->button.y <= y+height)
			{
				(*function)(0,0);
			}
        }        
	}
}

void Button::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->surface_exist(keys[0]))
		{
			screen_manager->surface_apply( (int)x, (int)y, keys[0], pressed );
		}
		else
		{
ERROR("Image " << keys[pressed] << " failed to load")
		}
	}
}

void Button::load_surfaces()
{
	if (loaded == 0)
	{
		int i;
		for (i = 0; i < num_keys; i++)
		{	
			keys[i] = screen_manager->surface_load(filenames,2,255,255,255);
			screen_manager->surface_reference(keys[i]);
		}
	
		width = screen_manager->surface_width(keys[0],0);
		height = screen_manager->surface_height(keys[0],0);
		
		loaded = 1;
	}
}