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
		
        // called every iteration of the game loop; inherited from Object
        // Image does nothing because it does not change with each iteration
		void step() {};
    
        // called every time there is an event; inherited from Object
        // Image does nothing because once loaded no event affects it
		void events(SDL_Event *event) {};
    
        // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height
        // pre-conditions  object is visible and loaded
        // post-conditions object appears on texture
		void draw();
    
        // instructs screenmanager to load the images for the Image
        // pre-conditions  Image's filename is valid
        // post-conditions Image is ready to be shown
		void load_surfaces();
};

#endif