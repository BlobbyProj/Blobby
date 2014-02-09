#ifndef SURFACE_H
#define SURFACE_H

#include "SDL2/SDL.h"
#include <string>
#include <vector>
#include "globals.h"

class Texture {
	private:
		std::vector<SDL_Texture*>* frames;
		std::vector<std::string>* filenames;
		unsigned int num_references;
		
	public:
		Texture();
		~Texture();
		
		void add(SDL_Texture *texture) { frames->push_back(texture); }
		void add(std::string filename) { filenames->push_back(filename); }
		unsigned int size() { return frames->size(); }
		
		const char *get_filename(unsigned int val) { return (*filenames)[val].c_str(); }
		
		int referenced() { return num_references; }
		void operator++(int) { num_references++; };
		void operator--(int) { num_references--; }
		
		SDL_Texture *operator[](unsigned int val) { return (*frames)[val]; }
		const SDL_Texture *operator[](unsigned int val) const { return (*frames)[val]; }
};

#endif
