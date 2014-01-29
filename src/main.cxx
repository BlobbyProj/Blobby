#include <iostream>
#include <ctime>
#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "levelmanager.h"

int main( int argc, char* args[] )
{
	int i;
	
	clock_t time;
	time = clock();
	double time_since_last_frame = 0;
	int steps_since_last_frame = 0;
	
	SDL_Event event;
	
	
    //While the user hasn't quit
    while( global_gamestate != -1 )
    {
		global_timestep = ((double)(clock()-time))/CLOCKS_PER_SEC; //Time is in seconds
		time = clock();
		
		steps_since_last_frame++;
		time_since_last_frame += global_timestep;
		if (time_since_last_frame > 1.0/global_fps) //If it is time to redraw
		{	
			time_since_last_frame = 0;
			steps_since_last_frame = 0;
			object_manager->draw();
		}
		
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
			object_manager->events(&event);
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                global_gamestate = -1;
            }
        }
		
		object_manager->step();
		level_manager->step();
		
    }
	
	
    //Free the surface and quit SDL
	delete object_manager;
	delete level_manager;
	delete screen_manager;

    return 0;
}
