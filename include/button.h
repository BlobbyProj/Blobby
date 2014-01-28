#ifndef BUTTON_H
#define BUTTON_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

void ButtonRed();
void ButtonGreen();
void ButtonBlue();

class Button : public Object {
	private:
		bool pressed;
		int width;
		int height;
		void (*function)();
		
	public:
		Button(double X, double Y, std::string filename_unpressed, std::string filename_pressed, bool Visible, void (*otherFunction)());
		~Button();
		
		void step() {};
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif