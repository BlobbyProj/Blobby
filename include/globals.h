#ifndef MAIN_H
#define MAIN_H

//g++ main.cxx screen.cxx objectmanager.cxx bug.cxx -o main -lmingw32 -lSDLmain -lSDL -static-libgcc -static-libstdc++
#define DEBUG

class ScreenManager;
extern ScreenManager *screen_manager;

class ObjectManager;
extern ObjectManager *object_manager;

class LevelManager;
extern LevelManager *level_manager;


//Global settings
extern int global_gamestate;
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