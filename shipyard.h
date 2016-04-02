#ifndef SHIPYARD_H
#define SHIPYARD_H

#include "store.h"
#include "ship.h"

class Shipyard : public Store
{
public:
    Shipyard();
    Shipyard(QString name, QString type, int health, int capacity, bool destruct, int quantity);
    void ViewShips();
    Ship SellShip(QString name);
    void BuyShip(Ship ship);

private:
    QHash<QString, Ship> ships;
};

#endif // SHIPYARD_H
