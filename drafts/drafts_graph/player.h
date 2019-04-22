#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QColor>
#include <vector>

namespace Player {

    class Player
    {
        QString name;
        QColor color;
    };

    class PlayerList
    {
        std::vector<Player> players;
    public:

    };

}

#endif // PLAYER_H
