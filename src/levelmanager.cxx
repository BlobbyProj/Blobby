#include "levelmanager.h"
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
        music_manager->pause();
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
                //object_manager->objects_add(new Button(100,355, 400, 100, ButtonVolume));
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

                object_manager->objects_add(new Image(0,0, 3000, 480, "media/backgrounds/level1.txt"));
                object_manager->objects_add(new Block(200, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(300, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(300, HEIGHT-20-128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(400, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(400, HEIGHT-20-128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(500, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(500, HEIGHT-20-128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1000, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1000, HEIGHT-20-128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1100, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1100, 0, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1100, 64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1100, 128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1200, 0, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1200, 64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1200, 128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1200, 192, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1300, 0, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1300, 64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1400, 0, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1400, 64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1500, 0, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1500, 64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1600, 0, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1600, 64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1600, 128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1600, 192, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1700, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1700, 0, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1700, 64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1700, 128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1800, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1800, HEIGHT-20-128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(1900, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2000, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2100, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2200, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2300, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2400, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2500, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2600, HEIGHT-20-128, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2600, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Block(2700, HEIGHT-20-64, -1, -1, "media/objects/block.txt"));
                object_manager->objects_add(new Enemy(300,200, -1, -1, "media/enemies/torto.txt"));
                object_manager->objects_add(new Enemy(2200,0, -1, -1, "media/enemies/torto.txt"));
                object_manager->objects_add(new Enemy(1900,0, -1, -1, "media/enemies/goon.txt"));
                object_manager->objects_add(new Enemy(500,200, -1, -1, "media/enemies/torto2.txt"));
                object_manager->objects_add(new Enemy(900,0, -1, -1, "media/enemies/goon.txt"));
                object_manager->objects_add(new Gloop(700, HEIGHT-20-128, -1, -1, "media/objects/gloop.txt"));
                
				object_manager->objects_add(new PlayerCharacter(10,10, 64, 64, "media/blobbys/blobby.txt"));
				object_manager->objects_add(new Flag(2900, HEIGHT-20-128, -1, -1, "media/objects/flag.txt"));
                object_manager->objects_add(new Button(580,30, -1, -1, ButtonPause));

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
