#include "texture.h"

#include "globals.h"

Texture::Texture()
{
	num_references = 0;
	frames = new std::vector<SDL_Texture*>;
	filenames = new std::vector<std::string>;
}

Texture::~Texture()
{
	int i;
	for (i = 0; i < frames->size(); i++)
		SDL_DestroyTexture((*frames)[i]);
	delete frames;
	delete filenames;
}
