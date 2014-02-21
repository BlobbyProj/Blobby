#ifndef BLOCK_H
#define BLOCK_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class Block : public Object {
public:
    
	// constructor for Block - creates new instance of Block object
	// param X         x coordinate for location of upper-left corner of Block
	// param Y         y coordinate for location of upper-left corner of Block
	// param width     width of Block in pixels
	// param height    height of Block in pixels
	// param filename  filename of object image (???)
	// pre-conditions  Block does not yet exist
	// post-conditions Block exists
    Block(double X, double Y, int width, int height, std::string filename);
    
    // destructor for Block - deletes instance of Block object
    // pre-conditions  Block exists
    // post-conditions Block no longer exists
    ~Block();
    
    // (???)
    void step() {};
    
    // (???)
    void events(SDL_Event *event) {};
    
    // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height
    // pre-conditions  object is visible and loaded
    // post-conditions object appears on texture
    void draw();

    //
    void load_surfaces();
};

#endif