#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "SDL2/SDL.h"
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
		// constructor for ScreenManager - sets up new screen and renderer
		// param Width  width of screen in pixels
		// param Height height of screen in pixels
		// returns new screen
		// pre-conditions  screen does not yet exist
		// post-conditions screen exists
		ScreenManager(int Width, int Height);

		// destructor for ScreenManager - destroys screen and all images and objects in it
		// pre-conditions  screen exists
		// post-conditions screen no longer exists
		~ScreenManager();
		
		// getter for width of screen
		// returns width of screen in pixels
		// pre-conditions  screen exists
		int get_width() { return width; }

		// getter for height of screen
		// returns height of screen in pixels
		// pre-conditions  screen exists
		int get_height() { return height; }
    
		// clears entire screen at full opacity with set color
		// param R         Red value in pixels
		// param G         Green value in pixels
		// param B         Blue value in pixels
		// returns         0 if clear is successful, negative otherwise
		// pre-conditions  screen exists
		// post-conditions screen is cleared with set fill color
		bool clear(int R, int G, int B);

		// shows contents of screen
		// pre-conditions  screen exists
		// post-conditions screen in current state is shown
        void show();
		
		// loads images to screen if images are not yet loaded
		// param *filenames  vector of filenames of images
		// param num_files   number of files to load
		// returns key produced by hash of first filename in vector
		// pre-conditions  vector of filenames exists
		// post-conditions images appear in texture
		unsigned int texture_load( std::string *filenames, unsigned int num_files );
		
		// loads images to screen if images are not yet loaded
		// param *filenames  vector of filenames of images
		// param num_files   number of files to load
		// param R           Red value in pixels
		// param G           Green value in pixels
		// param B           Blue value in pixels
		// returns key produced by hash of first filename in vector
		// pre-conditions  vector of filenames exists
		// post-conditions images appear in texture
		unsigned int texture_load( std::string *filenames, unsigned int num_files, int R, int G, int B);
		
		// deletes all images in texture
		// param key  key used to specify texture
		// returns 0 if successful, -1 otherwise
		// pre-conditions  texture exists
		// post-conditions texture is clear
		bool texture_delete( unsigned int key );

		// loads specified texture to renderer at specified frame at specified point with indicated height, width, and position
		// param x      x coordinate of upper-left corner of texture
		// param y      y coordinate of upper-left corner of texture
		// param fixed  whether or not the texture is fixed to one place
		// param width  width of texture in pixels
		// param height height of texture in pixels
		// param key    key of texture being applied
		// param frame  frame of texture being applied
		// returns 0 for success, negative otherwise
		// pre-conditions  texture exists
		// post-conditions texture appears on screen
		bool texture_apply( int x, int y, bool fixed, int width, int height, unsigned int key, unsigned int frame);
		
		// loads specified texture to renderer at specified frame at specified point with indicated height, width, position, and opacity
		// param x      x coordinate of upper-left corner of texture
		// param y      y coordinate of upper-left corner of texture
		// param fixed  whether or not the texture is fixed to one place
		// param width  width of texture in pixels
		// param height height of texture in pixels
		// param key    key of texture being applied
		// param frame  frame of texture being applied
		// param alpha  opacity of texture
		// returns 0 for success, negative otherwise
		// pre-conditions  texture exists
		// post-conditions texture appears on screen
		bool texture_apply( int x, int y, bool fixed, int width, int height, unsigned int key, unsigned int frame, char alpha);
		
		// returns 1 if specified texture exists, 0 otherwise
		// param key  key of specific texture
		bool texture_exist( unsigned int key );
		
		// if texture exists returns width of specified frame in specified texture in pixels, else returns -1
		// param key   key of specified texture
		// param frame specified frame in texture
		// pre-conditions  texture exists
		int texture_width( unsigned int key, unsigned int frame );
		
		// if texture exists returns height of specified frame in specified texture in pixels, else returns -1
		// param key   key of specified texture
		// param frame specified frame in texture
		// pre-conditions  texture exists
		int texture_height( unsigned int key, unsigned int frame );
		
		// 
		void texture_reference( unsigned int key ) { (*(*images)[key])++; }
		void texture_dereference( unsigned int key ) { (*(*images)[key])--; }
		void texture_pare();
		
		// prints filenames of all images in texture
		// pre-conditions  texture exists
		void print();
};

#endif
