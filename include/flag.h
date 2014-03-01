#ifndef FLAG_H
#define FLAG_H

#include "object.h"

class Flag : public Object {
private:
	double timed;

public:

	// constructor for Flag - creates new instance of Flag object
	// param X         x coordinate for location of upper-left corner of Flag
	// param Y         y coordinate for location of upper-left corner of Flag
	// param width     width of Flag in pixels
	// param height    height of Flag in pixels
	// param filename  filename of Flag object image
	// pre-conditions  Flag does not yet exist
	// post-conditions Flag exists
    Flag(double X, double Y, int width, int height, std::string fname);

	// destructor for PlayerCharacter - deletes instance of PlayerCharacter object
	// pre-conditions  PlayerCharacter exists
	// post-conditions PlayerCharacter no longer exists
    ~Flag();

	// called every iteration of the game loop; inherited from Object
	// if the flag has been hit, it waits two seconds and returns to the main menu
	// post-conditions Flag results in the end of the level and return to the main menu
    void step();
	// called every time there is an event; inherited from Object
	// Flag events method does nothing because once the Flag is loaded, no event affects it
    void events(SDL_Event *event) {};
	// calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height
	// pre-conditions  flag object is visible and loaded
	// post-conditions flag object appears on texture
    void draw();
};

#endif
