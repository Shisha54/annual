#include "map.h"
#include <QDebug>
#include <QString>
#include <QPixmap>

Map::Map(std::string path) : Graph (path + PATH_GRAPH)
{
    this->path = path;
    qDebug() << "OK!";
}

QGraphicsScene *Map::generateScene()
{
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsPixmapItem * x = scene->addPixmap(QPixmap(QString::fromStdString(path + PATH_IMAGE)));
    for(auto i = graphVertice.begin(); i != graphVertice.end(); i++)
    {
        scene->addRect(i->coordinates.x,i->coordinates.y,20,20,QPen(Qt::red),QBrush(Qt::black));
    }
    return scene;
}
