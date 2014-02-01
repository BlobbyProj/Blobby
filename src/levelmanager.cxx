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
				object_manager->pause_objects_add(new Image(20,20,"images/Menu.bmp"));
				object_manager->pause_objects_add(new Image(120,50,"images/PauseTitle.bmp"));
				object_manager->pause_objects_add(new Button(120,180,ButtonResume));
				object_manager->pause_objects_add(new Button(120,320,ButtonMainMenu));
				break;
		}
		screen_manager->surface_pare();
		object_manager->load_surfaces();
	}
	if (global_gamestate != previous_gamestate)
	{
		object_manager->objects_clear();
		switch(global_gamestate)
		{
			case 0: //Main Menu
				object_manager->objects_add(new Image(20,20,"images/Menu.bmp"));
				object_manager->objects_add(new Image(120,50,"images/MenuTitle.bmp"));
				object_manager->objects_add(new Button(120,180,ButtonPlay));
				object_manager->objects_add(new Button(120,320,ButtonQuit));
				break;
			case 1: //Level 1
				object_manager->objects_add(new Image(0,460,"images/Ground.bmp"));
				object_manager->objects_add(new PlayerCharacter(10,10,"images/Block.bmp"));
				object_manager->objects_add(new Button(580,30,ButtonPause));
				break;
		}
		screen_manager->surface_pare();
		object_manager->load_surfaces();
	}
	
	previous_paused = global_paused;
	previous_gamestate = global_gamestate;
}