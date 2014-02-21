#ifndef ENEMY_H
#define ENEMY_H

#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "object.h"

class Enemy : public Object {
	private:
		int previous_x;
		int previous_y;
		double vel;
		double xvel;
		double yvel;
		char lives;

	public:
		Enemy(double X, double Y, int width, int height, std::string filename);
		~Enemy();
		
		void step();
		void events(SDL_Event *event) {};
		void draw();
		void load_surfaces();
};

#endif
