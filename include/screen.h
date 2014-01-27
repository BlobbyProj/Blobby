#ifndef SCREEN_H
#define SCREEN_H

#include "SDL/SDL.h"
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "globals.h"



class Screen {
	private:
		SDL_Surface *screen;
		//std::vector<SDL_Surface*> images;
		std::map<unsigned int,SDL_Surface*> *images;
		int width;
		int height;
		int bpp;
		
	public:
		Screen(int Width, int Height, int BPP);
		~Screen();
		
		int get_width() { return width; }
		int get_height() { return height; }
		int get_bpp() { return bpp; }
		
		bool clear(int R, int G, int B);
		bool flip();
		
		unsigned int surface_load( std::string filename );
		unsigned int surface_load( std::string filename, int R, int G, int B);
		bool surface_delete( unsigned int IID );
		bool surface_apply( int x, int y, unsigned int IID);
		bool surface_exist( unsigned int IID );
		
		int surface_width( unsigned int IID );
		int surface_height( unsigned int IID );
};

#endif