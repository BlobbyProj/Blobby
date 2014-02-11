#include "console.h"

Console::Console(int Width, int Height)
{
	width = Width;
	height = Height;
	
    //Set up the screen and renderer
    screen = SDL_CreateWindow("Console", 20, SDL_WINDOWPOS_CENTERED, Width, Height, 0);
    renderer = SDL_CreateRenderer(screen, -1, 0);
	
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        FLAG
    }
}

Console::~Console()
{    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
}

bool Console::clear(int R, int G, int B)
{
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    return SDL_RenderClear(renderer);
}

void Console::show()
{
    SDL_RenderPresent(renderer);
    return;
}