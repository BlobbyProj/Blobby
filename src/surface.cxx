#include "surface.h"

Surface::Surface()
{
	num_references = 0;
	frames = new std::vector<SDL_Surface*>;
	filenames = new std::vector<std::string>;
}

Surface::~Surface()
{
	int i;
	for (i = 0; i < frames->size(); i++)
		SDL_FreeSurface((*frames)[i]);
	delete frames;
	delete filenames;
}