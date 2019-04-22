#ifndef GRAPH_H
#define GRAPH_H

#define PATH_GRAPH "\\graph.txt"
#define PATH_IMAGE "\\map.jpg"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QDebug>

class Point
{
    int x, y;
public:
    Point(int x, int y);
    int getX();
    int getY();
    Point(std::istream & x);
    friend std::istream & operator>>(std::istream & in, Point & A);
    friend std::ostream & operator<<(std::ostream & out, const Point & A);
    friend bool operator==(const Point & a, const Point & b);
};

class Edge
{
    int x, y;
public:
    Edge(int x, int y);
    Edge(std::istream & x);
    friend std::istream & operator>>(std::istream & in, Edge & A);
    friend std::ostream & operator<<(std::ostream & out, const Edge & A);
    friend bool operator==(const Edge & a, const Edge & b);
    friend bool operator==(const Edge & a, int x);
};

class Graph
{
    std::vector<Point> points;
    std::vector<Edge> edges;
public:
    Graph(std::istream & x);
    Graph(); // Not used but without it wouldn't work(((
    friend std::istream & operator>>(std::istream & in, Graph & A);
    friend std::ostream & operator<<(std::ostream & out, const Graph & A);
    void delPoint(int index);
    void delEdge(int x, int y);
    void addPoint(int x, int y);
    void addEdge(int x, int y);
    friend class Map;
};

class Map
{
    QPixmap picture;
    int picW, picH; //Hint resolution of the picture for verticies to be aligned to
public:
    Graph graph;
    Map(std::string path);
    bool saveGraphTxt(std::string path);
    QGraphicsScene *generateScene(); //OBSOLETE!!!!!
};

#endif // GRAPH_H
