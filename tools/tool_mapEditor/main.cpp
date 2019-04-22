#include "graph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Map map("D:\\kds\\projects\\Qt\\annual\\annual\\tools\\tool_mapEditor\\map");
    map.graph.addPoint(444,555);
    QGraphicsView view(map.generateScene());
    view.show();
    return a.exec();
}
