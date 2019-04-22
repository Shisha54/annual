#ifndef PROVINCE_H
#define PROVINCE_H

#include "player.h"
#include "order.h"
#include "army.h"
#include "buildings.h"

class Province
{
    Army army;
    ArmyOrder<Province> armyOrder;
    BuildOrder buildOrder;
    int _stateNumberOfPendingPlayers;

    template<typename T> friend class ArmyOrder;
};

#endif // PROVINCE_H
