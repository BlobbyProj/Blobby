#include "button.h"

void ButtonRed(bool init)
{
	if (init)
	{
	}
	else
	{
		global_background[0] = 255;
		global_background[1] = 0;
		global_background[2] = 0;
	}
}

void ButtonGreen()
{
	if (init)
	{
	}
	else
	{
		global_background[0] = 0;
		global_background[1] = 255;
		global_background[2] = 0;
	}
}

void ButtonBlue()
{
	if (init)
	{
	}
	else
	{
		global_background[0] = 0;
		global_background[1] = 0;
		global_background[2] = 255;
	}
}

Button::Button(double X, double Y, unsigned int IID, unsigned int IID_Pressed, bool Visible, void (*otherFunction)())
{	
	x = X;
	y = Y;
	iid = new unsigned int[2];
	iid[0] = IID;
	iid[1] = IID_Pressed;
	width = screen->surface_width(iid[0]);
	height = screen->surface_height(iid[0]);
	pressed = 0;
	function = otherFunction;
	visible = Visible;
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
	if (visible == 1)
	{
		if (screen->surface_exist(iid[pressed]))
		{
			screen->surface_apply( static_cast<int>(x), static_cast<int>(y), iid[pressed] );
		}
		else
		{
ERROR("Image " << iid[pressed] << " failed to load")
		}
	}
}