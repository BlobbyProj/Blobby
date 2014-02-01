#ifndef SURFACE_H
#define SURFACE_H

#include "SDL/SDL.h"
#include <string>
#include <vector>
#include "globals.h"

class Surface {
	private:
		std::vector<SDL_Surface*>* frames;
		std::vector<std::string>* filenames;
		unsigned int num_references;
		
	public:
		Surface();
		~Surface();
		
		void add(SDL_Surface *surface) { frames->push_back(surface); }
		void add(std::string filename) { filenames->push_back(filename); }
		unsigned int size() { return frames->size(); }
		
		const char *get_filename(unsigned int val) { return (*filenames)[val].c_str(); }
		
		int referenced() { return num_references; }
		void operator++(int) { num_references++; };
		void operator--(int) { num_references--; }
		
		SDL_Surface *operator[](unsigned int val) { return (*frames)[val]; }
		const SDL_Surface *operator[](unsigned int val) const { return (*frames)[val]; }
};

#endif