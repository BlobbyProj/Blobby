#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"
#include "levelmanager.h"
#include "console.h"

//Initialize screen manager
ScreenManager *screen_manager = 0;

//Initialize object manager
ObjectManager *object_manager = 0;

//Initialize level manager
LevelManager *level_manager = 0;

//Initialize console
Console *console = 0;

//Initialize global variables
int global_gamestate = 0;
int global_focus = 0;
bool global_paused = 0;
char global_background[3] = {(char)170,(char)204,(char)255};
unsigned int global_background_key = 0;

double global_timestep = 0;
double global_gravity = 1000;