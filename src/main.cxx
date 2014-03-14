#include <iostream>
#include <fstream>
#include <ctime>
#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "levelmanager.h"
#include "musicmanager.h"

int main( int argc, char* args[] )
{
	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
	    MARK
	}

    
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        MARK
    }

    if (TTF_Init() != 0){
        std::cout << "error with text" << TTF_GetError() << std::endl;
    }

	//Create screen manager
	screen_manager = new ScreenManager(WIDTH,HEIGHT);

	//Create object manager
	object_manager = new ObjectManager;

	//Create level manager
	level_manager = new LevelManager;
    
    //Create music manager
    music_manager = new MusicManager;

	//std::ofstream cout;
	//cout.open("CON");
	//cout.close();

	int i;
	
	clock_t time;
	time = clock();
	double time_since_last_frame = 0;
	int steps_since_last_frame = 0;
    
    std::ifstream file;
    file.open("media/levels/save.txt");
    std::string buff;
    if (file.is_open()) {
        while (!file.eof()) {
            file >> global_level_progress;
        }
    }
    file.close();
	
	SDL_Event event;
	
    //While the user hasn't quit
    while( global_gamestate != -1 )
    {
		global_timestep = ((double)(clock()-time))/CLOCKS_PER_SEC; //Time is in seconds
		time = clock();
		
		steps_since_last_frame++;
		time_since_last_frame += global_timestep;
		if (time_since_last_frame > 1.0/global_fps) //If it is time to redraw
		{	
			time_since_last_frame = 0;
			steps_since_last_frame = 0;
			if (global_focus != 0)
				object_manager->draw();
		}
		
        //While there's an event to handle
        while( SDL_PollEvent( &event ) )
        {
        	//switch between event types
        	switch(event.type)
            {
				case SDL_WINDOWEVENT:
					switch(event.window.event)
					{
					case SDL_WINDOWEVENT_FOCUS_LOST:
						music_manager->pause();
						global_focus = 0;
						break;
					case SDL_WINDOWEVENT_FOCUS_GAINED:
						music_manager->resume();
						global_focus = event.window.windowID;
						break;
					case SDL_WINDOWEVENT_CLOSE:
						//Quit the program
						global_gamestate = -1;
						break;
					}
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
					case SDLK_p:
						//~ if(global_gamestate!=0 || global_gamestate!=1){
						if(global_gamestate == 0 || global_gamestate == 1 || global_gamestate == 2 || global_gamestate == 3){
							break;
						}
						global_paused = 1;
						break;
					case SDLK_RETURN:
						//if you're in the main menu
						if(global_gamestate == 0){
							global_gamestate = 3;
						}
						//if you are on the pause menu
						if(global_paused == 1){
							global_paused = 0;
							global_gamestate = global_previous_gamestate;							
						}
						//if you are on the scoreboard
						if(global_gamestate == 2)
						{
							if(global_level_failed){
								global_gamestate = global_previous_level;
							}else{
								int next_level = global_previous_level + 1;
								//if there is a next level
								if(global_previous_level == NUM_LEVELS + 3){
									global_gamestate = 0;
								}
								else{
									global_gamestate = next_level;
								}
							}
						}
						break;
					case SDLK_m:
						music_manager->toggle();
						break;
					case SDLK_q:
						global_gamestate = -1;
						break;
					}
					break;
            }
            if (global_focus != 0)
            {
				object_manager->events(&event);
			}

        }
		if (global_focus != 0)
		{
			object_manager->step();
			level_manager->step();
		}
		
    }
	
    //Free the surface and quit SDL
	delete object_manager;
	delete level_manager;
	delete screen_manager;
    delete music_manager;
    
    Mix_Quit();
    IMG_Quit();
	SDL_Quit();
	TTF_Quit();

    return 0;
}
