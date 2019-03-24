#include "graph.h"

using namespace Map;

int main()
{
    Graph x;
    x.addVertex();
    x.addVertex();

    qDebug() << x.verticies.at(1).checkEdge(x.verticies.at(0));
    x.addEdge(x.verticies.at(1), x.verticies.at(0));
    qDebug() << x.verticies.at(1).checkEdge(x.verticies.at(0));
    x.delEdge(x.verticies.at(1), x.verticies.at(0));
    qDebug() << x.verticies.at(1).checkEdge(x.verticies.at(0));
    return 0;
}
