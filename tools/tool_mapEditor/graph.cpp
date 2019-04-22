#include "graph.h"

std::istream & operator>>(std::istream & in, Point & A)
{
    return (in >> A.x >> A.y);
}

std::ostream & operator<<(std::ostream & out, const Point & A)
{
    return (out << A.x << " " << A.y << " ");
}

std::istream & operator>>(std::istream & in, Edge & A)
{
    return (in >> A.x >> A.y);
}

std::ostream & operator<<(std::ostream & out, const Edge & A)
{
    return (out << A.x << " " <<  A.y << " ");
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

Point::Point(std::istream & x)
{
    x >> *this;
}

Edge::Edge(int x, int y)
{
    this->x = x;
    this->y = y;
}

Edge::Edge(std::istream & x)
{
    x >> *this;
}

bool operator==(const Edge & a, int x)
{
    return (a.x == x || a.y == x );
}

bool operator==(const Point & a, const Point & b)
{
    return (a.x == b.x && a.y == b.y);
}

bool operator==(const Edge & a, const Edge & b)
{
    return (a.x == b.x && a.y == b.y);
}

std::istream & operator>>(std::istream & in, Graph & A)
{
    unsigned long long len;
    in >> len;
    for(unsigned long long i = 0; i < len; i++)
        A.points.emplace_back(in);
    in >> len;
    for(unsigned long long i = 0; i < len; i++)
        A.edges.emplace_back(in);
    return in;
}

std::ostream & operator<<(std::ostream & out, const Graph & A)
{
    out << A.points.size() << "\n";
    for(unsigned long long i = 0; i < A.points.size(); i++)
        out << A.points[i];
    out << "\n" << A.edges.size() << "\n";
    for(unsigned long long i = 0; i < A.edges.size(); i++)
        out << A.edges[i];
    return out;
}

Graph::Graph(std::istream & x)
{
    x >> *this;
}

void Graph::delPoint(int index)
{
    edges.erase(std::remove(edges.begin(), edges.end(), index),edges.end());
    points.erase(points.begin() + index);
}

void Graph::delEdge(int x, int y)
{
    edges.erase(std::remove(edges.begin(), edges.end(), Edge(x,y)),edges.end());
}

void Graph::addPoint(int x, int y)
{
    points.emplace_back(x,y);
}

void Graph::addEdge(int x, int y)
{
    edges.emplace_back(x,y);
}

Graph::Graph()
{
// Not used but without it wouldn't work(((
}

Map::Map(std::string path)
{

    std::ifstream input;
    try {
        input.open (path + PATH_GRAPH, std::ios::in);
        picture = QPixmap(QString::fromStdString(path + PATH_IMAGE));
    } catch (...) {
        qDebug() << "Unable to open files at \"" << QString::fromStdString(path) << "\"";
        exit(-1);
    }
    input >> picW >> picH;
    graph = Graph(input);
    input.close();
}

bool Map::saveGraphTxt(std::string path)
{
    std::ofstream output;
    try {
        output.open (path, std::ios::out);
    } catch (...) {
        qDebug() << "Unable to open file at \"" << QString::fromStdString(path) << "\"";
        return 0;
    }
    output << picW << " " << picH << "\n" << graph;
    return 1;
}

QGraphicsScene *Map::generateScene() //OBSOLETE!!!!!
{
    QGraphicsScene * scene = new QGraphicsScene();
    scene->addPixmap(picture);
    for(auto i = graph.points.begin(); i != graph.points.end(); i++)
    {
        scene->addRect(i->getX(),i->getY(),20,20,QPen(Qt::red),QBrush(Qt::black));
    }
    return scene;
}
