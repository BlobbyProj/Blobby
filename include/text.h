#ifndef TEXT_H
#define TEXT_H

#include "object.h"

class Text : public Object {
	private:
                std::string textStr;

        public:
        // constructor for Image - creates new instance of Text object
        // param X         x coordinate for location of upper-left corner of Text
        // param Y         y coordinate for location of upper-left corner of Text
        // param width     width of Text in pixels
        // param height    height of Text in pixels
        // param filename  filename of object image
        // pre-conditions  Image does not yet exist
        // post-conditions Image exists
		Text(double X, double Y, std::string text, int flags=0);
		
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