#ifndef TEXT_H
#define TEXT_H

#include "object.h"
#ifdef OSX
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_ttf.h>
#endif

class Text : public Object {
	private:
            std::string textStr;
            TTF_Font* font;

    public:
        // constructor for Text - creates new instance of Text object
        // param X         x coordinate for location of upper-left corner of Text
        // param Y         y coordinate for location of upper-left corner of Text
        // param text      text to be displayed
        // pre-conditions  Text does not yet exist
        // post-conditions Text exists
		Text(double X, double Y, std::string text, int flags=0);

        // destructor for Text - deletes instance of Text object
        // pre-conditions  Text exists
        // post-conditions Text no longer exists
        ~Text();
		
        // called every iteration of the game loop; inherited from Object
        // Text does nothing because it does not change with each iteration
		void step() {};
    
        // called every time there is an event; inherited from Object
        // Text does nothing because once loaded no event affects it
		void events(SDL_Event *event) {};
    
        // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height
        // pre-conditions  object is visible and loaded
        // post-conditions object appears on texture
		void draw();
};

#endif