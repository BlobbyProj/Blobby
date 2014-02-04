#include "levelmanager.h"
#include "objectmanager.h"
#include "screenmanager.h"
#include "playercharacter.h"
#include "button.h"
#include "image.h"

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
				object_manager->pause_objects_add(new Image(20,20, 600, 440, "images/Menu.bmp"));
				object_manager->pause_objects_add(new Image(120, 50, 400, 100, "images/PauseTitle.bmp"));
				object_manager->pause_objects_add(new Button(120,180, 400, 100, ButtonResume));
				object_manager->pause_objects_add(new Button(120,320, 400, 100, ButtonMainMenu));
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
				object_manager->objects_add(new Image(20,20,600, 440, "images/Menu.bmp"));
				object_manager->objects_add(new Image(120,50, 400, 100, "images/MenuTitle.bmp"));
				object_manager->objects_add(new Button(120,180, 400, 100, ButtonPlay));
				object_manager->objects_add(new Button(120,320, 400, 100, ButtonQuit));
				break;
			case 1: //Level 1
				object_manager->objects_add(new Image(0,460,640, 20, "images/Ground.bmp"));
				object_manager->objects_add(new PlayerCharacter(10,10, 32, 32, "images/Block.bmp"));
				object_manager->objects_add(new Button(580,30, 400, 100, ButtonPause));
				break;
		}
		screen_manager->texture_pare();
		object_manager->load_surfaces();
	}
	
	previous_paused = global_paused;
	previous_gamestate = global_gamestate;
}