#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

class LevelManager {
	private:
		int previous_gamestate;
		bool previous_paused;
		
	public:
		LevelManager() : previous_gamestate(-1), previous_paused(0) {};
	
		void step();
};

#endif