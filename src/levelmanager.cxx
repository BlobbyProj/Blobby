#include "levelmanager.h"

#include <fstream>
#include <sstream>
#include "objectmanager.h"
#include "screenmanager.h"
#include "musicmanager.h"
#include "playercharacter.h"
#include "button.h"
#include "image.h"
#include "enemy.h"
#include "block.h"
#include "flag.h"
#include "gloop.h"
#include "powerup.h"

/***** Do we still need this?? *****/
bool LevelManager::load_level_old(std::string fname)
{
/* Object types:

	0 = Undefined
	1 = PlayerCharacter
	2 = Button
	3 = Image
	4 = Enemy
	5 = Block
	6 = Flag
	7 = Gloop

*/
	int i;
	std::string buff;

	std::fstream file;
	file.open(fname.c_str());

	int obj_num;
	std::getline(file, buff);

	obj_num = atoi(buff.c_str());
	for (i = 0; i < obj_num; i++)
	{
		std::getline(file, buff);
		std::stringstream buffer;
		buffer << buff;

		int obj_type;
		buffer >> obj_type;

		int obj_x, obj_y;
		buffer >> obj_x;
		buffer >> obj_y;

		int obj_width, obj_height;
		buffer >> obj_width;
		buffer >> obj_height;

		std::getline(file, buff);

		switch(obj_type)
		{
			case PLAYERCHARACTER:
				object_manager->objects_add(new PlayerCharacter(obj_x, obj_y, obj_width, obj_height, buff));
				break;
			case IMAGE:
				object_manager->objects_add(new Image(obj_x, obj_y, obj_width, obj_height, buff));
				break;
			case ENEMY:
				object_manager->objects_add(new Enemy(obj_x, obj_y, obj_width, obj_height, buff));
				break;
			case BLOCK:
				object_manager->objects_add(new Block(obj_x, obj_y, obj_width, obj_height, buff));
				break;
			case FLAG:
				object_manager->objects_add(new Flag(obj_x, obj_y, obj_width, obj_height, buff));
				break;
			case GLOOP:
				object_manager->objects_add(new Gloop(obj_x, obj_y, obj_width, obj_height, buff));
				break;
		}
	}
	file.close();
}

bool LevelManager::load_level(std::string fname)
{
/* Object types:

	0 = Undefined
	1 = PlayerCharacter
	2 = Button
	3 = Image
	4 = Enemy
	5 = Block
	6 = Flag
	7 = Gloop

*/
	int i, j;
	std::string buff;

	std::fstream file;
	file.open(fname.c_str());

	std::getline(file, buff);
	int row_num = atoi(buff.c_str());

	std::getline(file, buff);
	int col_num = atoi(buff.c_str());


	for (i = 0; i < row_num; i++)
	{
		std::getline(file, buff);
		std::stringstream buffer;
		buffer << buff;

		for (j = 0; j < col_num; j++)
		{
			int obj_type;
			buffer >> obj_type;

			switch(obj_type)
			{
				case PLAYERCHARACTER:
					object_manager->objects_add(new PlayerCharacter(80*j, 80*i, 80, 80, "media/blobbys/blobby.txt"));
					break;
				case ENEMY:
					object_manager->objects_add(new Enemy(80*j+8, 80*i, 64, 74, "media/enemies/torto.txt"));
					break;
				case BLOCK:
					object_manager->objects_add(new Block(80*j, 80*i, 80, 80, "media/objects/block.txt"));
					break;
				case FLAG:
                    // height is -80(5-i) to compensate for flag's height being HEIGHT
					object_manager->objects_add(new Flag(80*j+20, -80*(5-i), 64, HEIGHT, "media/objects/flag.txt"));
					break;
				case GLOOP:
					object_manager->objects_add(new Gloop(80*j+20, 80*i+20, 40, 40, "media/objects/gloop.txt"));
					break;
                case POWERUP:
					object_manager->objects_add(new Powerup(80*j+20, 80*i+20, 40, 40, "media/objects/powerup.txt", 2));
					break;
			}
		}
	}
	file.close();
}

void LevelManager::set_level_x( double x )
{
	x -= WIDTH/2.0;
	if ( x < 0 )
		level_x = 0;
	else if ( x > level_width-WIDTH )
		level_x = level_width-WIDTH;
	else
		level_x = x;
}

void LevelManager::set_level_y( double y )
{
	y -= HEIGHT/2.0;
	if ( y < 0 )
		level_y = 0;
	else if ( y > level_height-HEIGHT )
		level_y = level_height-HEIGHT;
	else
		level_y = y;
}

void LevelManager::step()
{
	if (global_paused != previous_paused)
	{
		switch(global_paused)
		{
			case 0:
                music_manager->resume();
				object_manager->pause_objects_clear();
				break;
			case 1:
                music_manager->pause();
				object_manager->pause_objects_add(new Image(0+level_x, 0+level_y, 640, 480, "media/menus/pause.txt"));
				object_manager->pause_objects_add(new Button(180,200, -1, -1, ButtonResume));
				object_manager->pause_objects_add(new Button(180,280, -1, -1, ButtonMainMenu));
				object_manager->pause_objects_add(new Button(200,358, -1, -1, ButtonReplay));
                object_manager->pause_objects_add(new Button(530,55, -1, -1, ButtonVolume));
				break;
		}
		screen_manager->texture_pare();
		object_manager->load_surfaces();
	}
	if (global_gamestate != global_previous_gamestate)
	{
		object_manager->objects_clear();
		global_invalid_level = false;
		    
		switch(global_gamestate)
		{
			case 0: //Main Menu
                object_manager->objects_add(new Image(0,0, 640, 480, "media/menus/main.txt"));
				object_manager->objects_add(new Button(180,220, -1, -1, ButtonPlay));
				object_manager->objects_add(new Button(240,290, -1, -1, ButtonInstructions));
				object_manager->objects_add(new Button(240,355, -1, -1, ButtonQuit));
                object_manager->objects_add(new Button(530,55, -1, -1, ButtonVolume));
				level_width = WIDTH;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;

			case 1: //Instructions
				object_manager->objects_add(new Image(0 , 0, 640, 480, "media/menus/instructions.txt"));
				object_manager->objects_add(new Button(100,355, -1, -1, ButtonGoBack));
				level_width = WIDTH;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;
                
            case 2: //Scoreboard
            	object_manager->objects_add(new Image(0,0, 640, 480, "media/menus/scoreboard.txt"));
                if (global_previous_gamestate != NUM_LEVELS+3){ // don't show continue if completed last level
                    object_manager->objects_add(new Button(340,290, -1, -1, ButtonContinue));
                    object_manager->objects_add(new Button(130,290, -1, -1, ButtonReplay));
                }
                else {
                    object_manager->objects_add(new Button(235,290, -1, -1, ButtonReplay));
                }
				object_manager->objects_add(new Button(240,400, -1, -1, ButtonQuit));
                object_manager->objects_add(new Button(340,350, -1, -1, ButtonLevelMap));
				object_manager->objects_add(new Button(130,350, -1, -1, ButtonMainMenuSmall));
				level_width = WIDTH;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;
                
            case 3: //Level Map
            	object_manager->objects_add(new Image(0,0, 640, 480, "media/menus/levelMap.txt"));
				object_manager->objects_add(new Button(50,150, -1, -1, ButtonIsland1));
				object_manager->objects_add(new Button(410,160, -1, -1, ButtonIsland3));
				object_manager->objects_add(new Button(230,280, -1, -1, ButtonIsland2));
				level_width = WIDTH;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;
				
            // Island 1 begins
			case 4: //Level 1
				global_previous_level = global_gamestate;
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;

                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island1.txt"));;
                load_level("media/levels/level1.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
				break;

            case 5: //Level 2
   				global_previous_level = global_gamestate;
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island1.txt"));
                load_level("media/levels/level2.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;

            // Island 2 begins
            case 6: //Level 3
   				global_previous_level = global_gamestate;
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island2.txt"));
                load_level("media/levels/level3.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;

            case 7: //Level 4
   				global_previous_level = global_gamestate;            
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island2.txt"));
                load_level("media/levels/level4.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;
                
            // Island 3 begins
            case 8: //Level 5
   				global_previous_level = global_gamestate;            
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island3.txt"));
                load_level("media/levels/level5.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));

                break;

             default:
				//if the gamestate doesn't exist
				global_invalid_level = true;
				break;

		}
		screen_manager->texture_pare();
		object_manager->load_surfaces();
        play_music();
	}
		previous_paused = global_paused;
		global_previous_gamestate = global_gamestate;
}

void LevelManager::level_end(int score, double time, int win)
{
    std::cout << "time = " << time << std::endl;
    std::cout << "score = " << score << std::endl;
    music_manager->stop();
    if (!win) {
        object_manager->objects_add(new Image(0, 0, WIDTH, HEIGHT, "media/backgrounds/lose.txt", Object::FIXED));
        music_manager->play("media/music/death.wav", 1);
    }
    else {
        music_manager->play("media/music/success_short.wav", 1);
    }
}

void LevelManager::play_music()
{
    if (global_gamestate == 0 || global_gamestate == 1 || global_gamestate == 3) { // if displaying a menu
        if (global_previous_gamestate != 0 && global_previous_gamestate != 1 && global_previous_gamestate != 3) { // if it wasn't on a menu before
            music_manager->stop();
            music_manager->fade_in("media/music/menu.wav", 800);
        }
    }
    else if (global_gamestate >=4 && global_gamestate <=5) { // island1
        music_manager->stop();
        music_manager->fade_in("media/music/island1.wav", 800);
    }
    else if (global_gamestate >=6 && global_gamestate <=7) { // island 2
        music_manager->stop();
        music_manager->fade_in("media/music/island2.wav", 800);
    }
    else if (global_gamestate >=8 && global_gamestate <=8){ // island 3
        music_manager->stop();
        music_manager->fade_in("media/music/island3.wav", 800);
    }
    
}
