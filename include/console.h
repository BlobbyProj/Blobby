#ifndef CONSOLE_H
#define CONSOLE_H

#include "SDL2/SDL.h"
#include <string>
#include "globals.h"

class Console {
	private:
		SDL_Window *screen;
        SDL_Renderer *renderer;
		int width;
		int height;
		
	public:
		// constructor for Console - uses SDL library to create new Console window; throws error if error in setup
		// param Width     widtch of console in pixels
		// param Height    height of console in pixels
		// pre-conditions  Console does not yet exist
		// post-conditions Console exists
		Console(int Width, int Height);

		// destructor for Console - uses SDL library to destroy Console window
		// pre-conditions  Console exists
		// post-conditions Console no longer exists
		~Console();


		bool clear(int R, int G, int B);
		void show();
};

#endif
