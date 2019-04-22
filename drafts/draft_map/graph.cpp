#include "graph.h"

template<typename T> Vertex<T>::Vertex()
{
    //TODO отнаследовать или выполнить конструкторы по умолчанию VertexG S
}

template<typename T> bool operator==(const Vertex<T>& x, const Vertex<T>& y)
{
    return (&x == &y);
}

template<typename T> bool Vertex<T>::checkEdge(Vertex *x) //Check if there is an edge
{
    if(*x==*this)
        return 0;
    for(auto i = adjacent.begin(); i != adjacent.end(); ++i)
        if(*x==(**i))
            return 1;
    return 0;
}

template<typename T> bool Vertex<T>::checkEdge(const Vertex &x) //Check if there is an edge
{
    if(x==*this)
        return 0;
    for(auto i = adjacent.begin(); i != adjacent.end(); ++i)
        if(x==(**i))
            return 1;
    return 0;
}

template<typename T> void Vertex<T>::addEdge(Vertex *x) //Add existing edge by pointer
{
    if(this==x)
        return;
    if(!checkEdge(x))
        adjacent.push_back(x);
}

template<typename T> void Vertex<T>::addEdge(Vertex& x) //Add existing edge by reference
{
    if(*this==x)
        return;
    if(!checkEdge(x))
        adjacent.push_back(&x);
}

template<typename T> void Vertex<T>::delEdge(Vertex *x) //Deletes edge
{
    adjacent.erase(std::remove(adjacent.begin(), adjacent.end(), x), adjacent.end());
}

template<typename T> void Vertex<T>::delEdge(Vertex &x) //Deletes edge
{
    adjacent.erase(std::remove(adjacent.begin(), adjacent.end(), &x), adjacent.end());
}

template<typename T> void Graph<T>::addVertex(Vertex<T> &x) //Copies exactly with deleting all edges
{
    verticies.push_back(x);
    verticies.back().adjacent.clear();
}

template<typename T> void Graph<T>::addVertex()
{
    verticies.emplace_back(Vertex<T>()); // EMPLACE - for optimization - no copying or moving!
}

template<typename T> void Graph<T>::delEdge(Vertex<T> *x, Vertex<T> *y) //Deletes edge
{
    x->delEdge(y);
    y->delEdge(x);
}

template<typename T> void Graph<T>::delEdge(Vertex<T> &x, Vertex<T> &y) //Deletes edge
{
    x.delEdge(y);
    y.delEdge(x);
}

template<typename T> void Graph<T>::delVertex(Vertex<T> &x)
{
    for(auto i = x.adjacent.begin(); i != x.adjacent.end(); ++i)
        (*i)->delEdge(x);
    verticies.erase(std::remove(verticies.begin(), verticies.end(), x), verticies.end());
}

template<typename T> void Graph<T>::delVertex(Vertex<T> *x)
{
    for(auto i = x->adjacent.begin(); i != x->adjacent.end(); ++i)
        (*i)->delEdge(x);
    verticies.erase(std::remove(verticies.begin(), verticies.end(), *x), verticies.end());
}

template<typename T> void Graph<T>::addEdge(Vertex<T> *x, Vertex<T> *y) //Add edge by pointer
{
    x->addEdge(y);
    y->addEdge(x);
}

template<typename T> void Graph<T>::addEdge(Vertex<T> &x, Vertex<T> &y) //Add edge by reference
{
    x.addEdge(y);
    y.addEdge(x);
}
