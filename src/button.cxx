#include "button.h"

void ButtonPlay(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "media/buttons/playBtn.bmp";
		filenames[1] = "media/buttons/playClick.bmp";
		return;
	}

	global_gamestate = 2;
}

void ButtonQuit(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "media/buttons/quitBtn.bmp";
		filenames[1] = "media/buttons/quitClick.bmp";

		return;
	}
	
	global_gamestate = -1;
}

void ButtonPause(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "media/buttons/PauseUnpressed.bmp";
		filenames[1] = "media/buttons/PausePressed.bmp";
		return;
	}
	
	global_paused = 1;
}

void ButtonResume(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "media/buttons/resumeBtn.bmp";
		filenames[1] = "media/buttons/resumeClick.bmp";
		return;
	}
	
	global_paused = 0;
}

void ButtonMainMenu(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "media/buttons/mainMenuBtn.bmp";
		filenames[1] = "media/buttons/mainMenuClick.bmp";
		return;
	}
	
	global_paused = 0;
	global_gamestate = 0;
}
void ButtonGoBack(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "media/buttons/backBtn.bmp";
		filenames[1] = "media/buttons/backClick.bmp";
		return;
	}
	
	global_gamestate = 0;
}

void ButtonInstructions(bool init, std::string *filenames)
{
	if (init == 1)
	{
		filenames[0] = "media/buttons/instructionsBtn.bmp";
		filenames[1] = "media/buttons/instructionsClick.bmp";
		return;
	}

	global_gamestate = 1;
}


Button::Button(double X, double Y, int W, int H, void (*otherFunction)(bool,std::string*))
{	
	type = 2;
	
	position.x = X;
	position.y = Y;
    width = W;
    height = H;
	
	function = otherFunction;
	
	filenames = new std::string[2];
	(*function)(1,filenames);
	
	num_keys = 1;
	keys = new unsigned int[num_keys];
	
	pressed = 0;
	fixed = 1;
}

Button::~Button()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
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
        }        
	}
}

void Button::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen_manager->texture_exist(keys[0]))
		{
			screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], pressed );
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
			keys[i] = screen_manager->texture_load(filenames,2,255,255,255);
			screen_manager->texture_reference(keys[i]);
		}
	
		width = screen_manager->texture_width(keys[0],0);
		height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}
