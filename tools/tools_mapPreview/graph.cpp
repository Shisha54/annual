#include "graph.h"

GraphVertice::GraphVertice(const Coordinates& c)
{
    this->coordinates = c;
}

void GraphVertice::addLink(GraphVertice* ptrVertice)
{
    adjacent.push_back(ptrVertice);
}

std::istream & operator>>(std::istream & in, Coordinates & A)
{
    return (in >> A.x >> A.y);
}

void GraphVertice::_print()
{
    std::cout << coordinates.x << " " << coordinates.y << " | " << adjacent.size() << "\n";
}

void Graph::_print()
{
    for(auto i = graphVertice.begin(); i != graphVertice.end(); i++)
        i->_print();
}

Graph::Graph(std::string pathToGraph)
{
    //ТОДО Проверка на корректность пути!
    std::ifstream readStream(pathToGraph, std::ios_base::in);
    int graphVertices;
    readStream >> graphVertices;
    Coordinates c;
    for(int i = 0; i < graphVertices; i++)
    {
        readStream >> c;
        graphVertice.push_back(GraphVertice(c));
    }
    int graphLinks;
    readStream >> graphLinks;
    for(int i = 0; i < graphLinks; i++)
    {
        int v1, v2;
        readStream >> v1 >> v2;
        graphVertice[v1].addLink(&graphVertice[v2]);
        graphVertice[v2].addLink(&graphVertice[v1]);
    }
    readStream.close();
}
