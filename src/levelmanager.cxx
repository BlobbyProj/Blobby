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
					object_manager->objects_add(new Flag(80*j+20, 80*i, 40, 80, "media/objects/flag.txt"));
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
    music_manager->add_track("media/music/success_short.wav");
    music_manager->add_track("media/music/death.wav");
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
				object_manager->pause_objects_add(new Button(180,220, -1, -1, ButtonResume));
				object_manager->pause_objects_add(new Button(180,300, -1, -1, ButtonMainMenu));
                object_manager->pause_objects_add(new Button(530,55, -1, -1, ButtonVolume));
				break;
		}
		screen_manager->texture_pare();
		object_manager->load_surfaces();
	}
	if (global_gamestate != previous_gamestate)
	{
        music_manager->stop();
		object_manager->objects_clear();
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

			case 2: //Level 1
                music_manager->add_track("media/music/level1.wav");
                music_manager->play("media/music/level1.wav");

				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;

                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/level1.txt"));;
                load_level("media/levels/level1.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;
            case 3: //Level 2
                music_manager->add_track("media/music/level1.wav");
                music_manager->play("media/music/level1.wav");
                
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/level1.txt"));
                load_level("media/levels/level2.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;
            case 4: //Level 3
                music_manager->add_track("media/music/level1.wav");
                music_manager->play("media/music/level1.wav");
                
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/level1.txt"));
                load_level("media/levels/level3.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;
            case 5: //Level 4
                music_manager->add_track("media/music/level1.wav");
                music_manager->play("media/music/level1.wav");
                
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/level1.txt"));
                load_level("media/levels/level4.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;
            case 6: //Level 5
                music_manager->add_track("media/music/level1.wav");
                music_manager->play("media/music/level1.wav");
                
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/level1.txt"));;
                load_level("media/levels/level5.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;
		}
		screen_manager->texture_pare();
		object_manager->load_surfaces();
	}
	previous_paused = global_paused;
	previous_gamestate = global_gamestate;
}

void LevelManager::level_end(int score, double time, int win)
{
    std::cout << "time = " << time << std::endl;
    std::cout << "score = " << score << std::endl;
    music_manager->stop();
    if (!win) {
        object_manager->objects_add(new Image(0, 0, WIDTH, HEIGHT, "media/backgrounds/lose.txt", Object::FIXED));
        music_manager->play("media/music/death.wav");
    }
    else {
        music_manager->play("media/music/success_short.wav");
    }
}
