#ifndef ECONOMICS_H
#define ECONOMICS_H

#include "interfaces.h"

class Road
{
    int bandwidth;
};

class Province
{
    int population;
    bool city;
public:
    bool isCity();
};

#endif // ECONOMICS_H
