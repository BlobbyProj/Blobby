#include "globals.h"
#include "screen.h"
#include "objectmanager.h"

//Initialize screen manager
Screen *screen = new Screen(1000,800,32);

//Initialize object manager
ObjectManager *objmgr = new ObjectManager;

//Initialize global variables
int global_gamestate = 0;
char global_background[3] = {255,255,255};