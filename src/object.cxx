#include "object.h"

#include <fstream>

Rectangle Object::get_rectangle()
{
    return Rectangle(position, width, height);
}

void Object::load_surfaces()
{
	if (loaded == 0)
	{

		int i, j;
		int num_frames;
		std::string buff;

		std::fstream file;
		file.open(filename.c_str());

		std::getline(file, buff);
		num_keys = atoi(buff.c_str());
		keys = new unsigned int[num_keys];

		for (i = 0; i < num_keys; i++)
		{
			std::getline(file, buff);
			num_frames = atoi(buff.c_str());

			std::string *filenames = new std::string[num_frames];
			for (j = 0; j < num_frames; j++)
			{
				std::getline(file,filenames[j]);
			}
			keys[i] = screen_manager->texture_load(filenames,num_frames);
			screen_manager->texture_reference(keys[i]);

			delete[] filenames;
		}
		file.close();

		if (width == -1)
			width = screen_manager->texture_width(keys[0],0);

		if (height == -1)
			height = screen_manager->texture_height(keys[0],0);
		
		loaded = 1;
	}
}