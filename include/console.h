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
		Console(int Width, int Height);
		~Console();
		bool clear(int R, int G, int B);
		void show();
};

#endif
