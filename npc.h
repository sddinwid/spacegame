#ifndef NPC_H
#define NPC_H

#include <QObject>
#include "character.h"
#include "ship.h"

class NPC : public Character
{
public:
    NPC();
    Ship *getNPCShip();
    void setNPCShip(Ship *ship);

};

#endif // NPC_H
