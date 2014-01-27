#ifndef BUTTON_H
#define BUTTON_H

#include "globals.h"
#include "screen.h"
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
		Button(double X, double Y, unsigned int IID, unsigned int IID_Pressed, bool Visible, void (*otherFunction)());
		
		void step() {};
		void events(SDL_Event *event);
		void draw();
};

#endif