#ifndef ORDERS_H
#define ORDERS_H

#include "graph.h"
#include "army.h"
#include "buildings.h"

template<typename T> class ArmyOrder
{
    Vertex<T> * destination;
    Vertex<T> * origin;
    int initative;
    int amount;
public:
    void init(Vertex<T> origin);
    void move();
    void fin();
    ArmyOrder(Vertex<T> * destination, int amount); // MAYBE ENRICH
};

class BuildOrder
{

};

#endif // ORDERS_H
