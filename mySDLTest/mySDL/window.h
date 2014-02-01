/* class to control the SDL window */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    /*constructor to open window
       see SDL_CreateWindow for params
    */
    Window(const char* title, int x, int y, int w, int h, Uint32 flags);
    
    // destructor to close window
    ~Vec();

    // draw image (texture) to screen
    

    // make an image into a texture

private:

};
#endif
