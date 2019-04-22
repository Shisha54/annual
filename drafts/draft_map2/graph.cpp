#include "graph.h"

Vertex& Graph::addVertex(Vertex &x) //Copies exactly with deleting all edges
{
    verticies.push_back(x);
    verticies.back().adjacent.clear();
    return verticies.back();
}

Vertex& Graph::addVertex()
{
    verticies.emplace_back(Vertex()); // EMPLACE - for optimization - no copying or moving!
    return verticies.back();
}

void Graph::delEdge(Vertex *x, Vertex *y) //Deletes edge
{
    x->delEdge(y);
    y->delEdge(x);
}

void Graph::delEdge(Vertex &x, Vertex &y) //Deletes edge
{
    x.delEdge(y);
    y.delEdge(x);
}

void Graph::delVertex(Vertex &x)
{
    for(auto i = x.adjacent.begin(); i != x.adjacent.end(); ++i)
        (*i)->delEdge(x);
    verticies.erase(std::remove(verticies.begin(), verticies.end(), x), verticies.end());
}

void Graph::delVertex(Vertex *x)
{
    for(auto i = x->adjacent.begin(); i != x->adjacent.end(); ++i)
        (*i)->delEdge(x);
    verticies.erase(std::remove(verticies.begin(), verticies.end(), *x), verticies.end());
}

void Graph::addEdge(Vertex *x, Vertex *y) //Add edge by pointer
{
    x->addEdge(y);
    y->addEdge(x);
}
void Graph::addEdge(Vertex &x, Vertex &y) //Add edge by reference
{
    x.addEdge(y);
    y.addEdge(x);
}

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


bool Vertex::checkEdge(VertexInterface *x) //Check if there is an edge
{
    return checkEdge(static_cast<Vertex*>(x));
}

bool Vertex::checkEdge(const VertexInterface &x) //Check if there is an edge
{
    return checkEdge(static_cast<Vertex const &>(x));
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
