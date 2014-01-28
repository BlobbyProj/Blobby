#include <iostream>
#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "levelmanager.h"

int main( int argc, char* args[] )
{
	int i;
	
	SDL_Event event;
	
	//object_manager->objects_add(new PlayerCharacter(10,10,"images/block.bmp"));
	
	

	//object_manager->load_surfaces();
	
	
    //While the user hasn't quit
    while( global_gamestate != -1 )
    {
	
		object_manager->draw();
		
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
