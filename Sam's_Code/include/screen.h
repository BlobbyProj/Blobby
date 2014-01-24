#ifndef SCREEN_H
#define SCREEN_H

#include "SDL/SDL.h"
#include <string>
#include <vector>
#include "globals.h"


// What is this for?
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    const int rmask = 0xff000000;
    const int gmask = 0x00ff0000;
    const int bmask = 0x0000ff00;
    const int amask = 0x000000ff;
#else
    const int rmask = 0x000000ff;
    const int gmask = 0x0000ff00;
    const int bmask = 0x00ff0000;
    const int amask = 0xff000000;
#endif

// What is BPP?
class Screen {
	private:
		SDL_Surface *screen;
		std::vector<SDL_Surface*> images;
		int Width;
		int Height;
		int BPP;
		
	public:
		Screen(int width, int height, int bpp);
		~Screen();
		
        // change getters to getWidth(), etc. It makes it more clear.
		int width() { return Width; }
		int height() { return Height; }
		int bpp() { return BPP; }
		
        // clear sets color of whole screen?
		bool clear(int R, int G, int B);
		bool flip();
		
		unsigned int surface_load( std::string filename );
		unsigned int surface_load( std::string filename, int R, int G, int B);
		bool surface_delete( unsigned int IID );
		bool surface_apply( int x, int y, unsigned int IID);
		bool surface_exist( unsigned int IID );
		
        // Getters?
		int surface_width( unsigned int IID );
		int surface_height( unsigned int IID );
};

#endif