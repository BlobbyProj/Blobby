#include <iostream>
#include "globals.h"
#include "screen.h"
#include "objectmanager.h"
#include "bug.h"
#include "button.h"

int main( int argc, char* args[] )
{
    bool quit = false;
	int i;
	
	SDL_Event event;
	objmgr->add(new Bug(10,10,screen->surface_load("images/block.bmp"),1));
	
	objmgr->add(new Button(50,50,screen->surface_load("images/ButtonRedUnpressed.bmp"),screen->surface_load("images/ButtonRedPressed.bmp"),1,ButtonRed));
	objmgr->add(new Button(50,150,screen->surface_load("images/ButtonGreenUnpressed.bmp"),screen->surface_load("images/ButtonGreenPressed.bmp"),1,ButtonGreen));
	objmgr->add(new Button(50,250,screen->surface_load("images/ButtonBlueUnpressed.bmp"),screen->surface_load("images/ButtonBluePressed.bmp"),1,ButtonBlue));
	
    //While the user hasn't quit
    while( quit == false )
    {
	
		objmgr->draw();
		
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
			objmgr->events(&event);
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
		
		objmgr->step();
		
    }

    //Free the surface and quit SDL
	delete objmgr;
	delete screen;
    SDL_Quit();

    return 0;
}
