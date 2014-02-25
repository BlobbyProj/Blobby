#include "levelmanager.h"
#include "objectmanager.h"
#include "screenmanager.h"
#include "playercharacter.h"
#include "button.h"
#include "image.h"
#include "enemy.h"
#include "block.h"
#include "flag.h"

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
				object_manager->pause_objects_clear();
				break;
			case 1:
				object_manager->pause_objects_add(new Image(20+level_x ,20+level_y, 600, 440, "media/Menu.bmp"));
				object_manager->pause_objects_add(new Image(0+level_x, 0+level_y, 400, 100, "media/PauseMenu.bmp"));
				object_manager->pause_objects_add(new Button(180,220, 400, 100, ButtonResume));
				object_manager->pause_objects_add(new Button(180,300, 400, 100, ButtonMainMenu));
				break;
		}
		screen_manager->texture_pare();
		object_manager->load_surfaces();
	}
	if (global_gamestate != previous_gamestate)
	{
		object_manager->objects_clear();
		switch(global_gamestate)
		{
			case 0: //Main Menu
                object_manager->objects_add(new Image(0,0, 400, 100, "media/backgrounds/bg.bmp"));
				object_manager->objects_add(new Button(180,220, 200, 80, ButtonPlay));
				object_manager->objects_add(new Button(240,290, 200, 80, ButtonInstructions));
				object_manager->objects_add(new Button(240,355, 400, 100, ButtonQuit));
				level_width = WIDTH;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;
			case 1: //Instructions
				object_manager->objects_add(new Image(0,0,600, 480, "media/instructionsMenu.bmp"));
				object_manager->objects_add(new Button(100,355, 400, 100, ButtonGoBack));
				level_width = WIDTH;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;
			case 2: //Level 1
				std::string *blobby = new std::string[4];
				std::string *flag = new std::string[2];
				blobby[0] = "media/blobbys/blobbyleftSmaller.png";
				blobby[1] = "media/blobbys/blobbyrightSmaller.png";
				blobby[2] = "media/blobbys/life.png";
				blobby[3] = "media/backgrounds/lose.bmp";
				flag[0] = "media/flag.bmp";
				flag[1] = "media/backgrounds/success.bmp";
                object_manager->objects_add(new Image(0,0, 3000, 440, "media/backgrounds/bg1long.bmp"));
                
				object_manager->objects_add(new Block(200, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(300, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(300, HEIGHT-20-128, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(400, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(400, HEIGHT-20-128, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(500, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(500, HEIGHT-20-128, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1000, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1000, HEIGHT-20-128, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1100, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1100, 0, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1100, 64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1100, 128, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1200, 0, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1200, 64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1200, 128, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1200, 192, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1300, 0, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1300, 64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1400, 0, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1400, 64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1500, 0, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1500, 64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1600, 0, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1600, 64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1600, 128, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1600, 192, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1700, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1700, 0, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1700, 64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1700, 128, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1800, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(1800, HEIGHT-20-128, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(1900, HEIGHT-20-64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(2000, HEIGHT-20-64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(2100, HEIGHT-20-64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(2200, HEIGHT-20-64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(2300, HEIGHT-20-64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(2400, HEIGHT-20-64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(2500, HEIGHT-20-64, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(2600, HEIGHT-20-128, 100, 64, "media/block.bmp"));
                object_manager->objects_add(new Block(2600, HEIGHT-20-64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Block(2700, HEIGHT-20-64, 100, 64, "media/block.bmp"));
				object_manager->objects_add(new Enemy(300,200, 64, 78, "media/enemies/torto.png"));
				object_manager->objects_add(new Enemy(2200,0, 64, 78, "media/enemies/torto.png"));
				object_manager->objects_add(new Enemy(1900,0, 64, 78, "media/enemies/goon.png"));
                object_manager->objects_add(new Enemy(500,200, 64, 78, "media/enemies/torto2.bmp"));
                object_manager->objects_add(new Enemy(900,0, 64, 72, "media/enemies/goon.png"));
				object_manager->objects_add(new PlayerCharacter(10,10, 32, 32, blobby));
				object_manager->objects_add(new Flag(2900, HEIGHT-20-128, 64, 128, flag));
                object_manager->objects_add(new Button(580,30, 400, 100, ButtonPause));

                level_width = 3000;
				level_height = HEIGHT;
				level_x = 0;
				level_y = 0;
				break;

		}
		screen_manager->texture_pare();
		object_manager->load_surfaces();
	}
	
	previous_paused = global_paused;
	previous_gamestate = global_gamestate;
}
