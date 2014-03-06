#ifndef FALLINGOBJ_H
#define FALLINGOBJ_H

#include "object.h"

class FallingObj : public Object {
    private:
        double yvel;
        bool init;
        double orig_y;
        bool playercharacter;
    public:
        // constructor for FallingObj; sets variables to default values
        // pre-conditions  FallingObj does not yet exist
        // post-conditions FallingObj exists
        FallingObj() : yvel(0), init(true), playercharacter(false) {};
    
        // called every iteration of the game loop; inherited from Object
        // moves the FallingObj up and then has it fall off the screen
        // pre-conditions  the FallingObj is supposed to die
        // post-conditions the FallingObj is off the screen and deleted
        void step();
};

#endif