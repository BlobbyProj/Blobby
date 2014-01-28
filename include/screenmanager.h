#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "SDL/SDL.h"
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "globals.h"
#include "surface.h"

class ScreenManager {
	private:
		SDL_Surface *screen;
		std::map<unsigned int,Surface*> *images;
		int width;
		int height;
		int bpp;
		
	public:
		ScreenManager(int Width, int Height, int BPP);
		~ScreenManager();
		
		int get_width() { return width; }
		int get_height() { return height; }
		int get_bpp() { return bpp; }
		
		bool clear(int R, int G, int B);
		bool flip();
		
		unsigned int surface_load( std::string *filenames, unsigned int num_files );
		unsigned int surface_load( std::string *filenames, unsigned int num_files, int R, int G, int B);
		SDL_Surface *surface_load( std::string filename );
		SDL_Surface *surface_load( std::string filename, int R, int G, int B);
		bool surface_delete( unsigned int key );
		bool surface_apply( int x, int y, unsigned int key, unsigned int frame);
		bool surface_exist( unsigned int key );
		
		int surface_width( unsigned int key, unsigned int frame );
		int surface_height( unsigned int key, unsigned int frame );
		
		void surface_reference( unsigned int key ) { (*(*images)[key])++; }
		void surface_dereference( unsigned int key ) { (*(*images)[key])--; }
		void surface_pare();
		
		void print();
};

#endif