#include "button.h"

void ButtonRed()
{
	global_background[0] = 255;
	global_background[1] = 0;
	global_background[2] = 0;
}

void ButtonGreen()
{
	global_background[0] = 0;
	global_background[1] = 255;
	global_background[2] = 0;
}

void ButtonBlue()
{
	global_background[0] = 0;
	global_background[1] = 0;
	global_background[2] = 255;
}

Button::Button(double X, double Y, std::string filename_unpressed, std::string filename_pressed, bool Visible, void (*otherFunction)())
{	
	x = X;
	y = Y;
	
	filenames = new std::string[2];
	filenames[0] = filename_unpressed;
	filenames[1] = filename_pressed;
	
	num_keys = 1;
	keys = new unsigned int[num_keys];

	loaded = 0;
	
	width = 0;
	height = 0;
	
	pressed = 0;
	function = otherFunction;
	visible = Visible;
}

Button::~Button()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen->surface_dereference(keys[i]);
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
				(*function)();
			}
        }        
	}
}

void Button::draw()
{
	if (visible == 1 && loaded == 1)
	{
		if (screen->surface_exist(keys[0]))
		{
			screen->surface_apply( static_cast<int>(x), static_cast<int>(y), keys[0], pressed );
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
			keys[i] = screen->surface_load(filenames,2);
			screen->surface_reference(keys[i]);
		}
	
		width = screen->surface_width(keys[0],1);
		height = screen->surface_height(keys[0],1);
		
		loaded = 1;
	}
}