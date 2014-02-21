#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

class LevelManager {
	private:
		int previous_gamestate;
		bool previous_paused;

		double level_x;
		double level_y;
		double level_width;
		double level_height;
		
	public:
        // constructor for LevelManager - controls the levels in the game
        // pre-conditions  LeveltManager does not yet exist
        // post-conditions LevelManager exists, variables have default values
		LevelManager() : previous_gamestate(-1), previous_paused(0), level_x(0), level_y(0) {};

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
};

#endif