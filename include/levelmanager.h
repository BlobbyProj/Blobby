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
		LevelManager() : previous_gamestate(-1), previous_paused(0), level_x(0), level_y(0) {};

		int get_level_x() { return (int)level_x; }
		int get_level_y() { return (int)level_y; }
		int get_level_width() { return (int)level_width; }
		int get_level_height() { return (int)level_height; }

		void set_level_x( double x );
		void set_level_y( double y );

		void step();
};

#endif