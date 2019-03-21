#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#ifndef GRAPH_H
#define GRAPH_H

class Coordinates
{
public:
    int x, y;
    friend std::istream & operator>>(std::istream & in, Coordinates & A);
};

class GraphVertice
{
    std::vector<GraphVertice*> adjacent;
    Coordinates coordinates;
public:
    GraphVertice(const Coordinates& c);
    void addLink(GraphVertice* ptrVertice);
    void _print();
};

class Graph
{
    std::vector<GraphVertice> graphVertice;
public:
    Graph(std::string pathToGraph);
    void _print();
};

#endif // GRAPH_H
