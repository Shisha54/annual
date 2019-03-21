#include "graph.h"
#include "map.h"
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Map map("E:\\kds\\Projects\\Qt\\annual\\tools\\tools_mapPreview\\map\\");
    QGraphicsView view(map.generateScene());
    view.show();
    return a.exec();
}