#include <iostream>
#include <fstream>
#include <ctime>
#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "levelmanager.h"
#include "console.h"

int main( int argc, char* args[] )
{
	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
	    FLAG
	}

	//Create console
	//console = new Console(CONSOLE_WIDTH,CONSOLE_HEIGHT);

	//Create screen manager
	screen_manager = new ScreenManager(WIDTH,HEIGHT);

	//Create object manager
	object_manager = new ObjectManager;

	//Create level manager
	level_manager = new LevelManager;

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
			if (global_focus == 1)
				object_manager->draw();
		}
		
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
        	//If the user has Xed out the window
        	if( event.type == SDL_WINDOWEVENT )
            {
            	switch(event.window.event)
            	{
            	case SDL_WINDOWEVENT_FOCUS_LOST:
            		global_focus = 0;
            		break;
            	case SDL_WINDOWEVENT_FOCUS_GAINED:
            		global_focus = event.window.windowID;
            		break;
            	case SDL_WINDOWEVENT_CLOSE:
                	//Quit the program
                	global_gamestate = -1;
                	break;
            	}
            }
            if (global_focus == 1)
            {
				object_manager->events(&event);
			}

        }
		if (global_focus == 1)
		{
			object_manager->step();
			level_manager->step();
		}
		
    }
	
    //Free the surface and quit SDL
    //delete console;
	delete object_manager;
	delete level_manager;
	delete screen_manager;
	SDL_Quit();

    return 0;
}
