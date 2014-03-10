#ifndef MAIN_H
#define MAIN_H

#define DEBUG

#define WIDTH 640
#define HEIGHT 480
#define CONSOLE_WIDTH 200
#define CONSOLE_HEIGHT 400
#define NUM_LEVELS 5

#define PLAYERCHARACTER 1
#define BUTTON 2
#define IMAGE 3
#define ENEMY 4
#define BLOCK 5
#define FLAG 6
#define GLOOP 7
#define POWERUP 8

//global variables used throughout the rest of the files

class ScreenManager;
extern ScreenManager *screen_manager;

class ObjectManager;
extern ObjectManager *object_manager;

class LevelManager;
extern LevelManager *level_manager;

class MusicManager;
extern MusicManager *music_manager;

class Console;
extern Console *console;


//Global settings
extern int global_gamestate;
extern int global_focus;
extern bool global_paused;
extern char global_background[3];
extern unsigned int global_background_key;
extern int global_previous_gamestate;

extern double global_gravity;
extern double global_timestep;
const int global_fps = 60;

extern bool muted;

#ifdef DEBUG
#include <iostream>
#define MARK std::cerr<<__LINE__<<": Flagged"<<std::endl;
#define ERROR(a) std::cerr<<__LINE__<<": "<<a<<std::endl;
#define PRINT(a) std::cout<<a<<std::endl;
#define EQUAL(a,b) std::cerr<<(#a)<<(a==b?"==":"=/=")<<(#b)<<std::endl;
#else
#define MARK 
#define ERROR(a) 
#define PRINT(a)
#define EQUAL(a,b)
#endif

#endif
