#include "graph.h"

namespace Map
{

Vertex::Vertex()
{
    //TODO отнаследовать или выполнить конструкторы по умолчанию VertexG S
}

bool operator==(const Vertex& x, const Vertex& y)
{
    return (&x == &y);
}

bool Vertex::checkEdge(Vertex *x) //Check if there is an edge
{
    if(*x==*this)
        return 0;
    for(auto i = adjacent.begin(); i != adjacent.end(); ++i)
        if(*x==(**i))
            return 1;
    return 0;
}

bool Vertex::checkEdge(const Vertex &x) //Check if there is an edge
{
    if(x==*this)
        return 0;
    for(auto i = adjacent.begin(); i != adjacent.end(); ++i)
        if(x==(**i))
            return 1;
    return 0;
}

void Vertex::addEdge(Vertex *x) //Add existing edge by pointer
{
    if(this==x)
        return;
    if(!checkEdge(x))
        adjacent.push_back(x);
}

void Vertex::addEdge(Vertex& x) //Add existing edge by reference
{
    if(*this==x)
        return;
    if(!checkEdge(x))
        adjacent.push_back(&x);
}

void Vertex::delEdge(Vertex *x) //Deletes edge
{
    adjacent.erase(std::remove(adjacent.begin(), adjacent.end(), x), adjacent.end());
}

void Vertex::delEdge(Vertex &x) //Deletes edge
{
    adjacent.erase(std::remove(adjacent.begin(), adjacent.end(), &x), adjacent.end());
}

}

