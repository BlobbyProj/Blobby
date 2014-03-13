#include "fallingobj.h"

#include "playercharacter.h"

void FallingObj::step() {
    if (init){
        orig_y = position.y;
        yvel = -500;
        position.y = position.y + yvel*global_timestep;
        init = false;
        // check if this is a PlayerCharacter
        PlayerCharacter* p = dynamic_cast<PlayerCharacter*>(this);
        if (p != 0)
            playercharacter = true;
    }else{
        yvel += global_gravity*global_timestep;
        position.y = position.y + yvel*global_timestep;
    }
    if (position.y > HEIGHT) {
        trashed = 1;
        if(playercharacter) {
            global_gamestate = 0;
        }
    }
    return;
}