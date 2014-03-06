#include "fallingobj.h"
#include "globals.h"

void FallingObj::step() {
    if (init){
        orig_y = position.y;
        yvel = -50;
        init = false;
    }
    
    if (position.y <= 50 || time >= 1000){
        yvel += global_gravity*global_timestep;
    }
    position.y = position.y + yvel*global_timestep;
    if (position.y > HEIGHT) {
        trashed = 1;
    }
    time += global_timestep;
    return;
}