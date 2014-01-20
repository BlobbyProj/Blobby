#ifndef MAIN_H
#define MAIN_H

//g++ main.cxx screen.cxx objectmanager.cxx bug.cxx -o main -lmingw32 -lSDLmain -lSDL -static-libgcc -static-libstdc++
#define DEBUG

#ifdef DEBUG
#include <iostream>
#define FLAG std::cerr<<__LINE__<<": Flagged"<<std::endl;
#define ERROR(a) std::cerr<<__LINE__<<": "<<a<<std::endl;
#define EQUAL(a,b) std::cerr<<(#a)<<(a==b?"==":"=/=")<<(#b)<<std::endl;
#else
#define FLAG 
#define ERROR(a) 
#define EQUAL(a,b)
#endif

#endif