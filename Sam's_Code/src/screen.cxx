#include "screen.h"

Screen::Screen(int width, int height, int bpp)
{
	Width = width;
	Height = height;
	BPP = bpp;

    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        FLAG
    }
	
    //Set up the screen
    screen = SDL_SetVideoMode( Width, Height, BPP, SDL_SWSURFACE );
	
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        FLAG
    }
	
    //Set the window caption
    SDL_WM_SetCaption( "Caption", NULL );
}

Screen::~Screen()
{
	int i;
	for (i = 0; i < images.size(); i++)
		SDL_FreeSurface( images[i] );
}
		
bool Screen::clear(int R, int G, int B)
{
	return SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, R, G, B));
}

bool Screen::flip()
{
	return SDL_Flip( screen );
}

unsigned int Screen::surface_load( std::string filename )
{
	//Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
	
	//Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );
	
	//If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
	
	//Save the optimized image
    images.push_back(optimizedImage);
	
	return images.size()-1;
}

unsigned int Screen::surface_load( std::string filename, int R, int G, int B)
{
	//Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
	
	//Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );
	
	//If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
	
	//Map color key
	Uint32 colorkey = SDL_MapRGB( optimizedImage->format, R, G, B );
	
	//Set all pixels that color to be transparent
	SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
	
	//Save the optimized image
    images.push_back(optimizedImage);
	
	return images.size()-1;
}

bool Screen::surface_delete( unsigned int IID )
{
	if (IID < images.size())
	{
		SDL_FreeSurface(images[IID]);
		images.erase(images.begin()+IID);
		return 0;
	}
	return -1;
}

bool Screen::surface_apply( int x, int y, unsigned int IID)
{
	//Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
	if (surface_exist(IID))
		return SDL_BlitSurface( images[IID], NULL, screen, &offset );
	else
		return -1;
}

bool Screen::surface_exist( unsigned int IID )
{
	if (IID >= 0 && IID < images.size())
		return 1;
}

int Screen::surface_width( unsigned int IID )
{
	if (surface_exist(IID))
		return images[IID]->w;
	else
		return -1;
}

int Screen::surface_height( unsigned int IID )
{
	if (surface_exist(IID))
		return images[IID]->h;
	else
		return -1;
}


