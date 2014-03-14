#include "screenmanager.h"

#include <vector>
#include <functional>
#include "globals.h"
#include "levelmanager.h"

#include <ciso646>
#if defined( _LIBCPP_VERSION )
using std::hash;
#else
#include <tr1/unordered_map>
using std::tr1::hash;
#endif

ScreenManager::ScreenManager(int Width, int Height)
{
	images = new std::map<unsigned int,Texture*>;

	width = Width;
	height = Height;
	
    //Set up the screen and renderer
    screen = SDL_CreateWindow("Blobby", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, 0);
    renderer = SDL_CreateRenderer(screen, -1, 0);
	
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        MARK
    }
}

ScreenManager::~ScreenManager()
{
	std::map<unsigned int,Texture*>::iterator it;
	for (it = images->begin(); it != images->end(); ++it)
	{
		delete it->second;
	}
	delete images;
	
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
}
		
bool ScreenManager::clear(int R, int G, int B)
{
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
	return SDL_RenderClear(renderer);
}

void ScreenManager::show() {
    SDL_RenderPresent(renderer);
    return;
}

unsigned int ScreenManager::texture_load( std::string *filenames, unsigned int num_files )
{
	//Hash filename for use as key
	hash<std::string> str_hash;
	unsigned int key = str_hash(filenames[0]);
	
	//Check if image already loaded
	if (texture_exist(key))
		return key;

	Texture *image = new Texture;
	int i;
	for ( i = 0; i < num_files; i++ )
	{
		SDL_Texture *texture = texture_load(filenames[i]);
		image->add(texture);
		image->add(filenames[i]);
	}
	
	//Save the optimized image
    images->insert(std::pair<unsigned int,Texture*>(key,image));
	
	return key;
}

unsigned int ScreenManager::texture_load( std::string *filenames, unsigned int num_files, int R, int G, int B)
{
	//Hash filename for use as key
	hash<std::string> str_hash;
	unsigned int key = str_hash(filenames[0]);
	
	//Check if image already loaded
	if (texture_exist(key))
		return key;

	Texture *image = new Texture;
	int i;
	for ( i = 0; i < num_files; i++ )
	{
		SDL_Texture *texture = texture_load(filenames[i],R,G,B);
		image->add(texture);
		image->add(filenames[i]);
	}
	
	//Save the optimized image
    images->insert(std::pair<unsigned int,Texture*>(key,image));
	
	return key;
}

SDL_Texture *ScreenManager::texture_load( std::string filename )
{
    //Texture to hold image
    SDL_Texture* loadedImage = NULL;
    
    // Load image (using img framework)
    loadedImage = IMG_LoadTexture(renderer, filename.c_str());
    if( loadedImage == NULL )
    {
        std::cout << SDL_GetError() << std::endl;
        FLAG;
    }
    
	return loadedImage;
}

SDL_Texture *ScreenManager::texture_load( std::string filename, int R, int G, int B)
{
	//Temporary storage for the image that's loaded
    SDL_Surface* loadedSurface = NULL;
    
    //The texture that will hold the image
    SDL_Texture* loadedImage = NULL;
    
	//Load the image
    loadedSurface = IMG_Load(filename.c_str());
    
    // Check if surface loaded properly
    if (loadedSurface == NULL) {
        std::cout << SDL_GetError() << std::endl;
        FLAG;
    }
    
    //Map color key
	Uint32 colorkey = SDL_MapRGB( loadedSurface->format, R, G, B );
	
	//Set all pixels that color to be transparent
	SDL_SetColorKey( loadedSurface, SDL_TRUE, colorkey );

    // convert the surface into a texture
    loadedImage = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    
    //Check if something went wrong in loading the image
    if( loadedImage == NULL )
    {
        std::cout << SDL_GetError() << std::endl;
        FLAG;
    }
    
    //Free the old surface
    SDL_FreeSurface( loadedSurface );
	
	return loadedImage;
}

bool ScreenManager::texture_delete( unsigned int key )
{
	if (texture_exist(key))
	{
		int i;
		delete (*images)[key];
		images->erase(key);
		return 0;
	}
	return -1;
}

bool ScreenManager::texture_apply( int x, int y, bool fixed, int w, int h, unsigned int key, unsigned int frame)
{
	if (texture_exist(key))
	{
		//Temporary rectangle to hold the offsets
		SDL_Rect offset;

		//Get the offsets
		offset.x = x-(level_manager->get_level_x()*(1-fixed));
		offset.y = y-(level_manager->get_level_y()*(1-fixed));
        offset.w = w;
        offset.h = h;
        
		//Load texture onto renderer
		return SDL_RenderCopy( renderer, (*(*images)[key])[frame], NULL, &offset );
	}
	return -1;
}

bool ScreenManager::texture_apply( int x, int y, bool fixed, int w, int h, unsigned int key, unsigned int frame, char alpha)
{
	if (texture_exist(key))
	{
		//Temporary rectangle to hold the offsets
		SDL_Rect offset;

		//Get the offsets
		offset.x = x-(level_manager->get_level_x()*(1-fixed));
		offset.y = y-(level_manager->get_level_y()*(1-fixed));
        offset.w = w;
        offset.h = h;

		//Load texture onto renderer
		
		SDL_Texture *tex = (*(*images)[key])[frame];
        Uint32 old_alpha;
        SDL_QueryTexture(tex, &old_alpha, NULL, NULL, NULL);
        old_alpha = (char) old_alpha;;
		SDL_SetTextureAlphaMod(tex, alpha);
        
		int return_value = SDL_RenderCopy( renderer, (*(*images)[key])[frame], NULL, &offset );
		SDL_SetTextureAlphaMod(tex, old_alpha);
		
		return return_value;
	}
	return -1;
}

bool ScreenManager::texture_exist( unsigned int key )
{
	if (images->find(key) != images->end())
		return 1;
	else
		return 0;
}

int ScreenManager::texture_width( unsigned int key, unsigned int frame )
{
	if (texture_exist(key)){
        int w;
		SDL_QueryTexture((*(*images)[key])[frame], NULL, NULL, &w, NULL);
        return w;
    }
	else
		return -1;
}

int ScreenManager::texture_height( unsigned int key, unsigned int frame )
{
	if (texture_exist(key)){
        int h;
		SDL_QueryTexture((*(*images)[key])[frame], NULL, NULL, NULL, &h);
        return h;
    }
	else
		return -1;
}

void ScreenManager::texture_pare()
{
	std::map<unsigned int,Texture*>::iterator it;
	it = images->begin();
	std::map<unsigned int,Texture*>::iterator it_next;
	while(it != images->end())
	{
		it_next = it;
		it_next++;
		if (it->second->referenced() == 0)
		{
			texture_delete(it->first);
		}
		it = it_next;
	}
}

void ScreenManager::print()
{
	std::map<unsigned int,Texture*>::iterator it;
	for (it = images->begin(); it != images->end(); ++it)
	{
		int i;
		PRINT(it->first<<" : "<<it->second->size()<<" : "<<it->second->referenced())
		for (i = 0; i < it->second->size(); i++)
			PRINT("   "<<it->second->get_filename(i))
	}
}

void ScreenManager::text_apply(double x, double y, std::string text, TTF_Font* font)
{
	SDL_Color color = { 0, 0, 0 };
	if (font == NULL) {
		std::cout << "error with font: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* surf = TTF_RenderText_Blended( font, text.c_str(), color );
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_FreeSurface(surf);
}
