#include "graph.h"
#include <QDebug>

namespace Map
{

void Graph::addVertex(Vertex &x) //Copies exactly with deleting all edges
{
    verticies.push_back(x);
    verticies.back().adjacent.clear();
}

void Graph::addVertex()
{
    verticies.emplace_back(Vertex()); // EMPLACE - for optimization - no copying or moving!
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

}
