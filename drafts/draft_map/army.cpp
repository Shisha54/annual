#include "army.h"

void Army::reset()
{
    available = strength;
}

void Army::mov(int amount)
{
    moving += amount;
    strength -= amount;
    available -= amount;
}

void Army::add(int amount)
{
    strength += amount;
}

void Army::ret(int amount)
{
    moving -= amount;
    strength += amount;
}
