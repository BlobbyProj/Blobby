#ifndef BUTTON_H
#define BUTTON_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

void ButtonPlay(bool init,std::string *filenames);
void ButtonInstructions(bool init,std::string *filenames);
void ButtonQuit(bool init,std::string *filenames);
void ButtonPause(bool init,std::string *filenames);
void ButtonResume(bool init,std::string *filenames);
void ButtonMainMenu(bool init,std::string *filenames);
void ButtonInstructions(bool init,std::string *filenames);

class Button : public Object {
	private:
		bool pressed;
		void (*function)(bool,std::string*);
		
	public:
		Button(double X, double Y, int width, int height, void (*otherFunction)(bool,std::string*));
		~Button();
		
		void step() {};
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif
