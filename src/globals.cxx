#include "globals.h"

//Initialize screen manager
class ScreenManager;
ScreenManager *screen_manager = 0;

//Initialize object manager
class ObjectManager;
ObjectManager *object_manager = 0;

//Initialize level manager
class LevelManager;
LevelManager *level_manager = 0;

//Initialize music manager
class MusicManager;
MusicManager *music_manager = 0;

//Initialize console
Console *console = 0;

//Initialize global variables
int global_gamestate = 0;
int global_focus = 0;
bool global_paused = 0;
char global_background[3] = {(char)170,(char)204,(char)255};
unsigned int global_background_key = 0;
int global_previous_gamestate = -1;

double global_timestep = 0;
double global_gravity = 1000;

bool muted = false;
