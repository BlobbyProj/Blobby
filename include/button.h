#ifndef BUTTON_H
#define BUTTON_H

#include "object.h"

// param init        represents whether or not the method has been run before
// param *filenames  holds strings specifying names of the Button image files
// pre-conditions    Button is available on screen for user

// controls Button to begin playing game; fetches image files if not initially available
// post-conditions  standard game play begins, global_gamestate does not equal 0
void ButtonPlay(bool init,std::string *filename);

// controls Button to quit game; fetches image files if not initially available
// post-conditions  game is closed, global_gamestate equals -1
void ButtonQuit(bool init,std::string *filename);

// controls Button to pause game; fetches image files if not initially available
// post-conditions  game is paused, global_paused equals 1
void ButtonPause(bool init,std::string *filename);

// controls Button to resume game; fetches image files if not initially available
// post-conditions  game is resumed, global_paused equals 0
void ButtonResume(bool init,std::string *filename);

// controls Button to redirect to main menu; fetches image files if not initially available
// post-conditions  global_paused equals 0 and global_gamestate equals 0
void ButtonMainMenu(bool init,std::string *filename);

// controls Button to redirect to intructions; fetches image files if not initially available
// post-conditions  global_gamestate equals 1
void ButtonInstructions(bool init,std::string *filename);

// controls Button to go back to previous screen; fetches image files if not initially available
// post-conditions  global_gamestate equals 0
void ButtonGoBack(bool init,std::string *filename);

// toggles volume
void ButtonVolume(bool init, std::string *filename);

class Button : public Object {
	private:
		bool pressed;
        int toggle;
		void (*function)(bool,std::string*);
		
	public:
        // constructor for Button - creates new instance of Button ob;ject
        // param X         x coordinate for location of upper-left corner of Button
        // param Y         y coordinate for location of upper-left corner of Button
        // param width     width of Button in pixels
        // param height    height of Button in pixels
        // param (*otherFunction)(bool,std::string*) pointer to the function which contains Button information
        // pre-conditions  Button does not yet exist
        // post-conditions Button exists
		Button(double X, double Y, int width, int height, void (*otherFunction)(bool,std::string*));
    
        // destructor for Button - deletes instance of Button object
        // pre-conditions  Button exists
        // post-conditions Button no longer exists
		~Button();
		
    
        // called every iteration of the game loop; inherited from Object
        // Button does nothing because it does not change with each iteration
		void step() {};
    
        // called every time there is an event; inherited from Object
        // determines whether the button was pressed
        // post-conditions  button image is correct based on if pressed
		void events(SDL_Event *event);
    
        // calls screenmanager->texture_apply to add object to texture at specified (x,y) position and with specified width, height
        // pre-conditions  object is visible and loaded
        // post-conditions object appears on texture
		void draw();
};

#endif
