#include "screenmanager.h"

ScreenManager::ScreenManager(int Width, int Height, int BPP)
{
	images = new std::map<unsigned int,Surface*>;

	width = Width;
	height = Height;
	bpp = BPP;

    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        FLAG
    }
	
    //Set up the screen
    screen = SDL_SetVideoMode( width, height, bpp, SDL_SWSURFACE );
	
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        FLAG
    }
	
    //Set the window caption
    SDL_WM_SetCaption( "Blobby", NULL );
}

ScreenManager::~ScreenManager()
{
	int i;
	std::map<unsigned int,Surface*>::iterator it;
	for (it = images->begin(); it != images->end(); ++it)
	{
		delete it->second;
	}
	delete images;
	
	SDL_Quit();
}
		
bool ScreenManager::clear(int R, int G, int B)
{
	return SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, R, G, B));
}

bool ScreenManager::flip()
{
	return SDL_Flip( screen );
}

unsigned int ScreenManager::surface_load( std::string *filenames, unsigned int num_files )
{
	//Hash filename for use as key
	std::hash<std::string> str_hash;
	unsigned int key = str_hash(filenames[0]);
	
	//Check if image already loaded
	if (surface_exist(key))
		return key;

	Surface *image = new Surface;
	int i;
	for ( i = 0; i < num_files; i++ )
	{
		SDL_Surface *surface = surface_load(filenames[i]);
		image->add(surface);
		image->add(filenames[i]);
	}
	
	//Save the optimized image
    images->insert(std::pair<unsigned int,Surface*>(key,image));
	
	return key;
}

unsigned int ScreenManager::surface_load( std::string *filenames, unsigned int num_files, int R, int G, int B)
{
	//Hash filename for use as key
	std::hash<std::string> str_hash;
	unsigned int key = str_hash(filenames[0]);
	
	//Check if image already loaded
	if (surface_exist(key))
		return key;

	Surface *image = new Surface;
	int i;
	for ( i = 0; i < num_files; i++ )
	{
		SDL_Surface *surface = surface_load(filenames[i],R,G,B);
		image->add(surface);
		image->add(filenames[i]);
	}
	
	//Save the optimized image
    images->insert(std::pair<unsigned int,Surface*>(key,image));
	
	return key;
}

SDL_Surface *ScreenManager::surface_load( std::string filename )
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
	
	return optimizedImage;
}

SDL_Surface *ScreenManager::surface_load( std::string filename, int R, int G, int B)
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
	
	return optimizedImage;
}

bool ScreenManager::surface_delete( unsigned int key )
{
	if (surface_exist(key))
	{
		int i;
		delete (*images)[key];
		images->erase(key);
		return 0;
	}
	return -1;
}

bool ScreenManager::surface_apply( int x, int y, unsigned int key, unsigned int frame)
{
	if (surface_exist(key))
	{
		//Temporary rectangle to hold the offsets
		SDL_Rect offset;

		//Get the offsets
		offset.x = x;
		offset.y = y;

		//Blit the surface

		return SDL_BlitSurface( (*(*images)[key])[frame], NULL, screen, &offset );
	}
	return -1;
}

bool ScreenManager::surface_exist( unsigned int key )
{
	if (images->find(key) != images->end())
		return 1;
	else
		return 0;
}

int ScreenManager::surface_width( unsigned int key, unsigned int frame )
{
	if (surface_exist(key))
		return (*(*images)[key])[frame]->w;
	else
		return -1;
}

int ScreenManager::surface_height( unsigned int key, unsigned int frame )
{
	if (surface_exist(key))
		return (*(*images)[key])[frame]->h;
	else
		return -1;
}

void ScreenManager::surface_pare()
{
	std::map<unsigned int,Surface*>::iterator it;
	it = images->begin();
	std::map<unsigned int,Surface*>::iterator it_next;
	while(it != images->end())
	{
		it_next = it;
		it_next++;
		if (it->second->referenced() == 0)
		{
			surface_delete(it->first);
		}
		it = it_next;
	}
}

void ScreenManager::print()
{
	std::map<unsigned int,Surface*>::iterator it;
	for (it = images->begin(); it != images->end(); ++it)
	{
		int i;
		PRINT(it->first<<" : "<<it->second->size()<<" : "<<it->second->referenced())
		for (i = 0; i < it->second->size(); i++)
			PRINT("   "<<it->second->get_filename(i))
	}
}
