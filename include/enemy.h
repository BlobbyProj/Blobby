#ifndef ENEMY_H
#define ENEMY_H

#include "globals.h"
#include "screenmanager.h"
#include "object.h"

class Enemy : public Object {
<<<<<<< HEAD
public:
    Enemy(double X, double Y, int width, int height, std::string filename);
    ~Enemy();
    
    void step() {};
    void events(SDL_Event *event) {};
    void draw();
    void load_surfaces();
    void attack() {};
};


#endif
=======
	private:
		int previous_x;
		int previous_y;
		double vel;
		double xvel;
		double yvel;
		
	public:
		Enemy(double X, double Y, int width, int height, std::string filename);
		~Enemy();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();
};

#endif
>>>>>>> 666cf241a082cc9e5df60c32025d8cb959ff2a4b
