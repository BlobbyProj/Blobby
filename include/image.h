#ifndef IMAGE_H
#define IMAGE_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class Image : public Object {
	public:
		// constructor for Image - creates new instance of Image object
		// param X         x coordinate for location of upper-left corner of Image
		// param Y         y coordinate for location of upper-left corner of Image
		// param width     width of Image in pixels
		// param height    height of Image in pixels
		// param filename  filename of object image (???)
		// pre-conditions  Image does not yet exist
		// post-conditions Image exists
		Image(double X, double Y, int width, int height, std::string filename);
		
		// destructor for Image - deletes instance of Image object
    	// pre-conditions  Image exists
   		// post-conditions Image no longer exists
		~Image();
		
		void step() {};
		void events(SDL_Event *event) {};
		void draw();
		void load_surfaces();
};

#endif