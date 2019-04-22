#ifndef GRAPH_H
#define GRAPH_H

#include "interfaces.h"
#include "node.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include <QDebug>

class Vertex final : VertexInterface, public Node
{
    friend bool operator==(const VertexInterface& x, const VertexInterface& y);
    friend class Graph;


    std::vector<Vertex*> adjacent;
private:
    //Those functions apply changes only to the current object therefore private
    void addEdge(Vertex *x); //Add edge by pointer
    void addEdge(Vertex &x); //Add edge by reference
    void delEdge(Vertex *x); //Deletes edge
    void delEdge(Vertex &x); //Deletes edge


    //DEBUG - enrich parameters. Vertex takes responsibily for VertexG L?
public:
    Vertex();
    bool checkEdge(VertexInterface *x) override; //Check if there is an edge
    bool checkEdge(const VertexInterface &x) override; //Check if there is an edge
    bool checkEdge(Vertex *x); //Check if there is an edge
    bool checkEdge(const Vertex &x); //Check if there is an edge
};

class Graph : GraphInterface
{
    std::vector<Vertex> verticies;
public:
    Vertex& addVertex(); //Enrich parameters
    Vertex& addVertex(Vertex &x); //Copies exactly with deleting all edges
    void addEdge(Vertex *x, Vertex *y); //Add edge by pointer
    void addEdge(Vertex &x, Vertex &y); //Add edge by reference
    void delEdge(Vertex *x, Vertex *y); //Deletes edge
    void delEdge(Vertex &x, Vertex &y); //Deletes edge
    void delVertex(Vertex &x);
    void delVertex(Vertex *x);
};

#endif // GRAPH_H
