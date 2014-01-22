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

Button::Button(double x, double y, unsigned int iid, unsigned int iid_pressed, bool visible, void (*otherFunction)())
{	
	X = x;
	Y = y;
	IID = new unsigned int[2];
	IID[0] = iid;
	IID[1] = iid_pressed;
	width = screen->surface_width(iid);
	height = screen->surface_height(iid);
	pressed = 0;
	function = otherFunction;
	Visible = visible;
}

void Button::events(SDL_Event *event)
{
	if ( event->type == SDL_MOUSEBUTTONDOWN )
	{
		if ( pressed == 0 && event->button.button == SDL_BUTTON_LEFT )
		{
			if ( event->button.x >= X && event->button.x <= X+width && event->button.y >= Y && event->button.y <= Y+height)
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
			if ( event->button.x >= X && event->button.x <= X+width && event->button.y >= Y && event->button.y <= Y+height)
			{
				(*function)();
			}
        }        
	}
}

void Button::draw()
{
	if (Visible == 1)
	{
		if (screen->surface_exist(IID[0]))
		{
			screen->surface_apply( static_cast<int>(X), static_cast<int>(Y), IID[pressed] );
		}
		else
		{
ERROR("Image " << IID[pressed] << " failed to load")
		}
	}
}