#include "levelmanager.h"

#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
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
#include "text.h"
#include "spike.h"

LevelManager::LevelManager(): previous_gamestate(-1), previous_paused(0), level_x(0), level_y(0) {
    std::string temp[7] = {"goon", "goon2", "torto", "torto2", "spikee", "vacuur", "vacuur2"};
    for (int i=0; i<7; i++){
        enemy_list[i] = temp[i];
    }
    button_list.resize(9);
    button_list[0] = ButtonLevel1;
    button_list[1] = ButtonLevel2;
    button_list[2] = ButtonLevel3;
    button_list[3] = ButtonLevel4;
    button_list[4] = ButtonLevel5;
    button_list[5] = ButtonLevel6;
    button_list[6] = ButtonLevel7;
    button_list[7] = ButtonLevel8;
    button_list[8] = ButtonLevel9;
    
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
	8 = Powerup
	9 = Spike

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
                    object_manager->objects_add(new Enemy(80*j+8, 80*i, 64, 74, "media/enemies/"+get_enemy()+".txt"));
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
					object_manager->objects_add(new Powerup(80*j+20, 80*i+20, 40, 40, "media/objects/powerup.txt"));
					break;
                case SPIKE:
					object_manager->objects_add(new Spike(80*j, 80*i, 80, 80, "media/objects/spike.txt"));
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
	std::string sc;
	std::string t;
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
				object_manager->pause_objects_add(new Button(190,150, -1, -1, ButtonResume));
				object_manager->pause_objects_add(new Button(190,220, -1, -1, ButtonReplay));
                object_manager->pause_objects_add(new Button(190,290, -1, -1, ButtonLevelMapPause));
				object_manager->pause_objects_add(new Button(190,360, -1, -1, ButtonMainMenu));

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
                object_manager->objects_add(new Button(590,55, -1, -1, ButtonVolume));
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
	          	sc = "Score = " + std::to_string(score);
	          	t = "Time = " + std::to_string(timeT) + " seconds";
            	object_manager->objects_add(new Image(0,0, 640, 480, "media/menus/scoreboard.txt"));
                //check if last level or player has failed the level
                if (global_previous_gamestate == NUM_LEVELS+3 || global_level_failed == true){
                    object_manager->objects_add(new Button(190,270, -1, -1, ButtonReplay));
                }
                else {
                    object_manager->objects_add(new Button(340,290, -1, -1, ButtonContinue));
                    object_manager->objects_add(new Button(130,290, 180, 45, ButtonReplaySmall));
                }
                object_manager->objects_add(new Button(360,350, -1, -1, ButtonLevelMap));
				object_manager->objects_add(new Button(150,350, -1, -1, ButtonMainMenuSmall));
				object_manager->objects_add(new Text(240, 180, sc));
				object_manager->objects_add(new Text(180, 220, t));
                level_width = WIDTH;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;
                
            case 3: //Level Map
            	object_manager->objects_add(new Image(0,0, 640, 480, "media/menus/levelMap.txt"));
                // display island1 buttons
                if (global_level_progress <= 3 ) {
                    for (int i = 0; i < global_level_progress; i++) {
                        object_manager->objects_add( new Button(200 + 100*i, 80, 40, 40, button_list[i]) );
                    }
                }
                else {
                    for (int i = 0; i < 3; i++) {
                        object_manager->objects_add( new Button(200 + 100*i, 80, 40, 40, button_list[i]) );
                    }
                }
                // display island2 buttons
                if (global_level_progress <= 6 && global_level_progress > 3) {
                    for (int i = 3; i < global_level_progress; i++) {
                        object_manager->objects_add( new Button(200 + 100*(i-3), 225, 40, 40, button_list[i]) );
                    }
                }
                else if (global_level_progress > 6) {
                    for (int i = 3; i < 6; i++) {
                        object_manager->objects_add( new Button(200 + 100*(i-3), 225, 40, 40, button_list[i]) );
                    }
                }
                // display island3 buttons
                if (global_level_progress <= 9 && global_level_progress > 6) {
                    for (int i = 6; i < global_level_progress; i++) {
                        object_manager->objects_add( new Button(200 + 100*(i-6), 375, 40, 40, button_list[i]) );
                    }
                }
                else if (global_level_progress > 9){
                    for (int i = 6; i < 9; i++) {
                        object_manager->objects_add( new Button(200 + 100*(i-6), 375, 40, 40, button_list[i]) );
                    }
                }
                
                object_manager->objects_add(new Button(10,440, -1, -1, ButtonMainMenuSmall));
				level_width = WIDTH;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;
				
            // Island 1 begins
			case 4: //Level 1
                island = 1;
				global_previous_level = global_gamestate;
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;

                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island1.txt"));
                if (global_level_progress == 1) {
                    object_manager->objects_add(new Image(20,175, -1, -1, "media/tutorial/move.txt"));
                    object_manager->objects_add(new Image(160,150, -1, -1, "media/tutorial/jump.txt"));
                    object_manager->objects_add(new Image(480,250, -1, -1, "media/tutorial/life.txt"));
                    object_manager->objects_add(new Image(640,200, -1, -1, "media/tutorial/powerup.txt"));
                    object_manager->objects_add(new Image(840,150, -1, -1, "media/tutorial/avoid.txt"));
                }
                load_level("media/levels/level1.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
            
				break;

            case 5: //Level 2
                island = 1;
   				global_previous_level = global_gamestate;
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island1.txt"));
                load_level("media/levels/level2.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;
                
            case 6: //Level 3
                island = 1;
   				global_previous_level = global_gamestate;
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island1.txt"));
                object_manager->objects_add(new Image(720,150, -1, -1, "media/tutorial/spikes.txt"));
                load_level("media/levels/level3.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;

            // Island 2 begins
            case 7: //Level 4
                island = 2;
   				global_previous_level = global_gamestate;
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island2.txt"));
                load_level("media/levels/level4.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;

            case 8: //Level 5
                island = 2;
   				global_previous_level = global_gamestate;            
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island2.txt"));
                load_level("media/levels/level5.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;

			case 9: //Level 6
                island = 2;
   				global_previous_level = global_gamestate;            
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island2.txt"));
                load_level("media/levels/level6.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));
                
				break;
				
            // Island 3 begins
            case 10: //Level 7
                island = 3;
   				global_previous_level = global_gamestate;            
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island3.txt"));
                load_level("media/levels/level7.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));

                break;

            case 11: //Level 8
                island = 3;
   				global_previous_level = global_gamestate;            
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
                
                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island3.txt"));
                load_level("media/levels/level8.txt");
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));

                break;

            case 12: //Level 9
                island = 3;
   				global_previous_level = global_gamestate;            
				level_width = 2960;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;


                object_manager->objects_add(new Image(0,0, level_width, level_height, "media/backgrounds/island3.txt"));
                load_level("media/levels/level9.txt");
                object_manager->objects_add(new Image(360,25, -1, -1, "media/tutorial/tunnel.txt"));
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
	this->score = score;
	timeT = time;
    music_manager->stop();
    if (!win) {
		global_level_failed = true;
        object_manager->objects_add(new Image(0, 0, WIDTH, HEIGHT, "media/backgrounds/lose.txt", Object::FIXED));
        music_manager->play("media/music/death.wav", 1);
    }
    else {
		global_level_failed = false;
        music_manager->play("media/music/success.wav", 1);
        set_progress();
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
    else if (island == 1 && global_gamestate != 2) {
        music_manager->stop();
        music_manager->fade_in("media/music/island1.wav", 800);
    }
    else if (island == 2 && global_gamestate != 2) {
        music_manager->stop();
        music_manager->fade_in("media/music/island2.wav", 800);
    }
    else if (island == 3 && global_gamestate != 2){
        music_manager->stop();
        music_manager->fade_in("media/music/island3.wav", 800);
    }
    
}

std::string LevelManager::get_enemy() {
    srand ( time(NULL) );
    int randIndex;
    switch (island) {
        case 1:
            randIndex = rand() % 2 + 2;
            return enemy_list[randIndex];
        
        case 2:
            randIndex = rand() % 2;
            return enemy_list[randIndex];
        
        case 3:
            randIndex = rand() % 3 + 4;
            return enemy_list[randIndex];
        default:
            randIndex = rand() % 6;
            return enemy_list[randIndex];
    }
}

void LevelManager::set_progress() {
    int progress = 0;
    if (global_gamestate-2 > global_level_progress)
        progress = global_gamestate - 2;
    if (progress != 0) {
        global_level_progress = progress;
        std::ofstream file;
        file.open("media/levels/save.txt");
        if (!file.is_open()) {
            FLAG;
        }
        file << global_level_progress;
        file.close();
    }
}
