#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>

template<typename T> class Vertex
{
    std::vector<Vertex*> adjacent;
    T contents;
    //Those functions apply changes only to the current object therefore private

    void addEdge(Vertex *x); //Add edge by pointer
    void addEdge(Vertex &x); //Add edge by reference
    void delEdge(Vertex *x); //Deletes edge
    void delEdge(Vertex &x); //Deletes edge

    //TODO privatize and T = province constructor
public:
    Vertex();
    bool checkEdge(Vertex *x); //Check if there is an edge
    bool checkEdge(const Vertex &x); //Check if there is an edge

    template<typename U>friend bool operator==(const Vertex<U>& x, const Vertex<U>& y);
    template<typename U> friend class Graph;
};

template<typename T> class Graph
{
        public:
    std::vector<Vertex<T>> verticies;
        //public:
    void addVertex(); //Enrich parameters
    void addVertex(Vertex<T> &x); //Copies exactly with deleting all edges
    void addEdge(Vertex<T> *x, Vertex<T> *y); //Add edge by pointer
    void addEdge(Vertex<T> &x, Vertex<T> &y); //Add edge by reference
    void delEdge(Vertex<T> *x, Vertex<T> *y); //Deletes edge
    void delEdge(Vertex<T> &x, Vertex<T> &y); //Deletes edge
    void delVertex(Vertex<T> &x);
    void delVertex(Vertex<T> *x);
};

#endif // GRAPH_H
