#ifndef SURFACE_H
#define SURFACE_H

#include "SDL2/SDL.h"
#include <string>
#include <vector>

class Texture {
	private:
		std::vector<SDL_Texture*>* frames;
		std::vector<std::string>* filenames;
		unsigned int num_references;
		
	public:
        // constructor for Texture - creates vector of images and vector of frames for images
        // pre-conditions  Texture does not yet exist
        // post-conditions Texture exists
		Texture();
    
        // destructor for Texture - destroys vector of images and vector of frames for images
        // pre-conditions  Texture exists
        // post-conditions Texture no longer exists
		~Texture();
		
        // adds frame for certain image at end of vector
        // param *texture  pointer to frame
        // pre-conditions  frame exists
        // post-conditions frame appears at end of vector
		void add(SDL_Texture *texture) { frames->push_back(texture); }
    
        // adds image according to filename at end of vector
        // param filename  filename of image to be added
        // pre-conditions  image file exists
        // post-conditions image appears at end of vector
		void add(std::string filename) { filenames->push_back(filename); }
    
        // returns size of vector of frames
        // pre-conditions  vector of frames exists
		unsigned int size() { return frames->size(); }
		
        // getter for filename of image in vector
        // param val  index value in vector
        // returns pointer to filename of image at specified index as a string
        // pre-conditions  filename exists at specified index value
		const char *get_filename(unsigned int val) { return (*filenames)[val].c_str(); }
		
        // returns number of references in Texture
        // pre-conditions  Texture exists
		int referenced() { return num_references; }
    
        // increases number of references by 1
        // pre-conditions  Texture exists
        // post-conditions one more reference in Texture
		void operator++(int) { num_references++; };
    
        // decreases number of references by 1
        // pre-conditions  Texture exists
        // post-conditions one less reference in Texture
		void operator--(int) { num_references--; }
		
        // returns pointer to frame in vector at specified index
        // param val       index value in vector of frames
        // pre-conditions  vector of frames exists
		SDL_Texture *operator[](unsigned int val) { return (*frames)[val]; }

        // returns const pointer to frame in vector at specified index
        // param val       index value in vector of frames
        // pre-conditions  vector of frames exists
		const SDL_Texture *operator[](unsigned int val) const { return (*frames)[val]; }
};

#endif
