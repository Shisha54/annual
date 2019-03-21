#include "graph.h"
#include <QGraphicsScene>
#include <QObject>

#ifndef MAP_H
#define MAP_H

#define PATH_GRAPH "\\graph.txt"
#define PATH_IMAGE "\\map.jpg"

class Map : public Graph
{
    std::string path;
public:
    Map(std::string path);
    QGraphicsScene * generateScene();
};

#endif // MAP_H
