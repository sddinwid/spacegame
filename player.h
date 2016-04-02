#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "character.h"
#include "ship.h"

class Player : public Character
{
public:
    Player();
    Ship *getPlayerShip();
    void setPlayerShip(Ship *ship);
    QString getPlayerName();
    void setPlayerName(QString name);
    QString getCharacterName();
    void setCharacterName(QString name);
    bool isDocked();
    void toggleDocked();
    void setDocked(bool d);

private:
    Ship * pship;
    QString name;
    QString cname;
    bool docked;
};

#endif // PLAYER_H
