#include <iostream>
#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "playercharacter.h"
#include "button.h"

int main( int argc, char* args[] )
{
    bool quit = false;
	int i;
	
	SDL_Event event;
	unsigned int pc = objmgr->add(new PlayerCharacter(10,10,"images/block.bmp",1));
	
	objmgr->add(new Button(50,50,"images/ButtonRedUnpressed.bmp","images/ButtonRedPressed.bmp",1,ButtonRed));
	objmgr->add(new Button(50,150,"images/ButtonGreenUnpressed.bmp","images/ButtonGreenPressed.bmp",1,ButtonGreen));
	objmgr->add(new Button(50,250,"images/ButtonBlueUnpressed.bmp","images/ButtonBluePressed.bmp",1,ButtonBlue));
	
	objmgr->load_surfaces();
	
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

    return 0;
}
