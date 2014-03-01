#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <string>

class LevelManager {
	private:
		int previous_gamestate;
		bool previous_paused;

		double level_x;
		double level_y;
		double level_width;
        double level_height;
    
        double time;
        // determines if time should be added
        bool timer;
		
	public:
        // constructor for LevelManager - controls the levels in the game
        // pre-conditions  LeveltManager does not yet exist
        // post-conditions LevelManager exists, variables have default values
		LevelManager() : previous_gamestate(-1), previous_paused(0), level_x(0), level_y(0), time(0) {};

		// loads level from file fname
		bool load_level(std::string fname);

        // gets level_x
		int get_level_x() { return (int)level_x; }
    
        // gets level_y
		int get_level_y() { return (int)level_y; }
    
        // gets level_width
		int get_level_width() { return (int)level_width; }
    
        // gets level_height
		int get_level_height() { return (int)level_height; }

        // sets level_x
		void set_level_x( double x );
    
        //sets level_y
		void set_level_y( double y );

        // called every time there is an event
        // Checks level status and shows correct objects for the current level
        // post-conditions  correct level or menu is shown
		void step();
    
        // stop the level timer and return the time
        double stop_timer();
    
        // designed for playercharacter to signal end of level
        // stops music and timer, prints out score
        // param score earned
        void level_end(int score);
    
};

#endif