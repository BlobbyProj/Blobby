#ifndef MAIN_H
#define MAIN_H

//g++ main.cxx screen.cxx objectmanager.cxx bug.cxx -o main -lmingw32 -lSDLmain -lSDL -static-libgcc -static-libstdc++
#define DEBUG

#define WIDTH 640
#define HEIGHT 480
#define CONSOLE_WIDTH 200
#define CONSOLE_HEIGHT 400

class ScreenManager;
extern ScreenManager *screen_manager;

class ObjectManager;
extern ObjectManager *object_manager;

class LevelManager;
extern LevelManager *level_manager;

class Console;
extern Console *console;


//Global settings
extern int global_gamestate;
extern int global_focus;
extern bool global_paused;
extern char global_background[3];
extern unsigned int global_background_key;

extern double global_gravity;
extern double global_timestep;
const int global_fps = 60;

#ifdef DEBUG
#include <iostream>
#define FLAG std::cerr<<__LINE__<<": Flagged"<<std::endl;
#define ERROR(a) std::cerr<<__LINE__<<": "<<a<<std::endl;
#define PRINT(a) std::cout<<a<<std::endl;
#define EQUAL(a,b) std::cerr<<(#a)<<(a==b?"==":"=/=")<<(#b)<<std::endl;
#else
#define FLAG 
#define ERROR(a) 
#define PRINT(a)
#define EQUAL(a,b)
#endif

#endif