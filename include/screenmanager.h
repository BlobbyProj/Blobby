#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "SDL2/SDL.h"
#ifdef LINUX
#include <SDL2/SDL_image.h>
#else
#include <SDL2_image/SDL_image.h>
#endif
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "globals.h"
#include "texture.h"

class ScreenManager {
	private:
		SDL_Window *screen;
        SDL_Renderer *renderer;
		std::map<unsigned int,Texture*> *images;
		int width;
		int height;
		
		SDL_Texture *texture_load( std::string filename );
		SDL_Texture *texture_load( std::string filename, int R, int G, int B);
		
	public:
		ScreenManager(int Width, int Height);
		~ScreenManager();
		
		int get_width() { return width; }
		int get_height() { return height; }
    
		bool clear(int R, int G, int B);
        void show();
		
		unsigned int texture_load( std::string *filenames, unsigned int num_files );
		unsigned int texture_load( std::string *filenames, unsigned int num_files, int R, int G, int B);
		bool texture_delete( unsigned int key );
		bool texture_apply( int x, int y, int width, int height, unsigned int key, unsigned int frame);
		bool texture_apply( int x, int y, int width, int height, unsigned int key, unsigned int frame, char alpha);
		bool texture_exist( unsigned int key );
		
		int texture_width( unsigned int key, unsigned int frame );
		int texture_height( unsigned int key, unsigned int frame );
		
		void texture_reference( unsigned int key ) { (*(*images)[key])++; }
		void texture_dereference( unsigned int key ) { (*(*images)[key])--; }
		void texture_pare();
		
		void print();
};

#endif
