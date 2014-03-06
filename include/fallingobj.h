#ifndef FALLINGOBJ_H
#define FALLINGOBJ_H

#include "object.h"

class FallingObj : public Object {
    private:
        double yvel;
        double time;
        bool init;
        double orig_y;
    public:
        FallingObj() : yvel(0), init(true) {};
        void step();
};

#endif