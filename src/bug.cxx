#include "bug.h"

Bug::Bug(double x, double y, unsigned int iid, bool visible)
{	
	X = x;
	Y = y;
	IID = new unsigned int;
	IID[0] = iid;
	vel = 0.5;
	Visible = visible;
}

Bug::~Bug()
{
	delete IID;
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
	X = X + xvel;
	Y = Y + yvel;
}

void Bug::draw()
{
	if (Visible == 1)
	{
		if (screen->surface_exist(IID[0]))
		{
			screen->surface_apply( static_cast<int>(X), static_cast<int>(Y), IID[0] );
		}
		else
		{
ERROR("Image " << IID[0] << " failed to load")
		}
	}
}