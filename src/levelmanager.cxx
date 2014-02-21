#include "levelmanager.h"
#include "objectmanager.h"
#include "screenmanager.h"
#include "playercharacter.h"
#include "button.h"
#include "image.h"
#include "enemy.h"
#include "block.h"

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
                object_manager->objects_add(new Image(0,0, 600, 440, "media/backgrounds/island1.bmp"));
				object_manager->objects_add(new PlayerCharacter(10,10, 32, 32, "media/blobbys/blobby.bmp"));
				object_manager->objects_add(new Enemy(200,335, 32, 32, "media/enemies/torto.bmp"));
				object_manager->objects_add(new Button(580,30, 400, 100, ButtonPause));
                object_manager->objects_add(new Block(500, 360, 100, 100, "media/block1.bmp"));
                level_width = 1000;
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
