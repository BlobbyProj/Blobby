#include "bug.h"

Bug::Bug(double x, double y, int iid, bool visible)
{
	X = x;
	Y = y;
	IID = iid;
	vel = 0.5;
	Visible = visible;
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