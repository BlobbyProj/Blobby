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
<<<<<<< HEAD
				//~ object_manager->pause_objects_add(new Image(20,20,"media/bg2.png"));
				object_manager->pause_objects_add(new Image(20,20,"images/Menu.bmp"));
				object_manager->pause_objects_add(new Image(120,50,"images/PauseTitle.bmp"));
				object_manager->pause_objects_add(new Button(120,180,ButtonResume));
				object_manager->pause_objects_add(new Button(120,320,ButtonMainMenu));
=======
				object_manager->pause_objects_add(new Image(20,20, 600, 440, "images/Menu.bmp"));
				object_manager->pause_objects_add(new Image(0, 0, 400, 100, "images/PauseMenu.bmp"));
				object_manager->pause_objects_add(new Button(180,220, 400, 100, ButtonResume));
				object_manager->pause_objects_add(new Button(180,300, 400, 100, ButtonMainMenu));
>>>>>>> 9fb90ad67163df1b04f318cfaf38d1c7db8a2374
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
<<<<<<< HEAD
				//~ object_manager->objects_add(new Image(20,20,"images/Menu.bmp"));
				//~ object_manager->objects_add(new Image(140,50,"media/blobbyAttempt.png"));
				object_manager->objects_add(new Image(120,50,"images/MenuTitle.bmp"));
				object_manager->objects_add(new Button(120,190,ButtonPlay));
				object_manager->objects_add(new Button(170,280,ButtonInstructions));
				object_manager->objects_add(new Button(215,350,ButtonQuit));
=======
				//TODO: only works if inside images folder? why?
				object_manager->objects_add(new Image(0,0, 400, 100, "images/bg2edit.bmp"));
				object_manager->objects_add(new Button(180,220, 200, 80, ButtonPlay));
				object_manager->objects_add(new Button(240,290, 200, 80, ButtonInstructions));
				object_manager->objects_add(new Button(240,355, 400, 100, ButtonQuit));
>>>>>>> 9fb90ad67163df1b04f318cfaf38d1c7db8a2374
				break;
			case 1: //Level 1
				object_manager->objects_add(new Image(0,460,640, 20, "images/Ground.bmp"));
				//~ object_manager->objects_add(new PlayerCharacter(10,10, 32, 32, "images/Block.bmp"));
				object_manager->objects_add(new PlayerCharacter(10,10, 32, 32, "media/blobbyAttempt.png"));
				object_manager->objects_add(new Button(580,30, 400, 100, ButtonPause));
				break;
		}
		screen_manager->texture_pare();
		object_manager->load_surfaces();
	}
	
	previous_paused = global_paused;
	previous_gamestate = global_gamestate;
}
