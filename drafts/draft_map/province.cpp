#ifndef PROVINCE_H
#define PROVINCE_H

#include "player.h"
#include "order.h"
#include "army.h"
#include "buildings.h"

class Province
{
    Army army;
    ArmyOrder armyOrder;
    BuildOrder buildOrder;
};

#endif // PROVINCE_H
