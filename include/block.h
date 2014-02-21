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
	// param filename  filename of object image
	// pre-conditions  Block does not yet exist
	// post-conditions Block exists
    Block(double X, double Y, int width, int height, std::string filename);
    
    // destructor for Block - deletes instance of Block object
    // pre-conditions  Block exists
    // post-conditions Block no longer exists
    ~Block();
    
    // called every iteration of the game loop; inherited from Object
    // Block does nothing because it does not change with each iteration
    void step() {};
    
    // called every time there is an event; inherited from Object
    // Block does nothing because once loaded it just sits there, no event affects it
    void events(SDL_Event *event) {};
    
    // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height
    // pre-conditions  object is visible and loaded
    // post-conditions object appears on texture
    void draw();

    // instructs screenmanager to load the images for the Block
    // pre-conditions  Block's image filename is valid
    // post-conditions Block's image is ready to be shown
    void load_surfaces();
};

#endif