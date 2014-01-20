#include <iostream>
#include "main.h"
#include "screen.h"
#include "objectmanager.h"
#include "bug.h"

int main( int argc, char* args[] )
{
    bool quit = false;
	int i;

    //Initialize
	Screen screen(1000,800,32);
	ObjectManager objmgr;
	SDL_Event event;
	
	objmgr.add(new Bug(10,10,screen.surface_load("images/block.bmp"),1));
	
    //While the user hasn't quit
    while( quit == false )
    {
		objmgr.draw(&screen);
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
			objmgr.events(&event);
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
		objmgr.step();
    }

    //Free the surface and quit SDL
    SDL_Quit();

    return 0;
}
