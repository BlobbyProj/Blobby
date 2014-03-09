#include "powerup.h"
#include "objectmanager.h"

Powerup::Powerup(double X, double Y, int W, int H, std::string fname, double time, int flags)
{
	apply_flags(flags);
	type = 8;
    
	filename = fname;
    
	position.x = X;
	position.y = Y;
    width = W;
    height = H;
    
    solid = 1;
    
    this->time = time;
    collected_time = 0;
    collected = false;
    p = NULL;
}

Powerup::~Powerup()
{
	int i;
	for (i = 0; i < num_keys; i++)
	{
		screen_manager->texture_dereference(keys[i]);
	}
    
	delete[] keys;
}

void Powerup::step(){
    if (collected_time > time){
        p->set_powerup(false);
        p = NULL;
        collected_time = 0;
        collected = false;
        trashed = 1;
    }
    if (collected) {
        collected_time += global_timestep;
    }
    else {
        int i;
        std::vector<ObjectManager::Collision>* collisions = object_manager->get_collisions(oid);
        for (i = 0; i < collisions->size(); i++)
        {
            unsigned int key = (*collisions)[i].oid;
            switch(object_manager->objects_type(key))
            {
                case 1: //Player
                    p = (PlayerCharacter *) object_manager->objects_get(key);
                    p->set_powerup(true);
                    collected = true;
                    visible = 0;
                    break;
            }
        }
        delete collisions;
    }
}

void Powerup::draw()
{
	if (visible == 1)
	{
		if (loaded == 1)
		{
			if (screen_manager->texture_exist(keys[0]))
			{
				screen_manager->texture_apply( (int)position.x, (int)position.y, fixed, width, height, keys[0], 0);
			}
			else
			{
				ERROR("Image " << keys[0] << " failed to load")
			}
		}
		else
		{
			load_surfaces();
		}
	}
}