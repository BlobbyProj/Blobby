#include "globals.h"
#include "screenmanager.h"
#include "objectmanager.h"

//Initialize screen manager
ScreenManager *screen = new ScreenManager(1000,800,32);

//Initialize object manager
ObjectManager *objmgr = new ObjectManager;

//Initialize global variables
int global_gamestate = 0;
char global_background[3] = {(char)255,(char)255,(char)255};