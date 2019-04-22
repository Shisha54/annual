#ifndef ARMY_H
#define ARMY_H

#include "interfaces.h"

class Army
{
    int strength;
public:
    void move(VertexInterface& x);
};

#endif // ARMY_H
