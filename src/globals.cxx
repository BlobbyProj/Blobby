#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "levelmanager.h"

//Initialize screen manager
ScreenManager *screen_manager = new ScreenManager(640,480,32);

//Initialize object manager
ObjectManager *object_manager = new ObjectManager;

//Initialize level manager
LevelManager *level_manager = new LevelManager;

//Initialize global variables
int global_gamestate = 0;
bool global_paused = 0;
char global_background[3] = {(char)0,(char)162,(char)232};
unsigned int global_background_key = 0;

double global_timestep = 0;
double global_gravity = 1000;