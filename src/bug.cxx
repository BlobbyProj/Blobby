#include "bug.h"

Bug::Bug(double X, double Y, unsigned int IID, bool Visible)
{	
	x = X;
	y = Y;
	iid = new unsigned int;
	iid[0] = IID;
	vel = 0.5;
	visible = Visible;
}

Bug::~Bug()
{
	delete iid;
}

void Bug::events(SDL_Event *event)
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

void Bug::step()
{
	x = x + xvel;
	y = y + yvel;
}

void Bug::draw()
{
	if (visible == 1)
	{
		if (screen->surface_exist(iid[0]))
		{
			screen->surface_apply( static_cast<int>(x), static_cast<int>(y), iid[0] );
		}
		else
		{
ERROR("Image " << iid[0] << " failed to load")
		}
	}
}