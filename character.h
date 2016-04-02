#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include "ship.h"

class Character : public Item
{

public:
    explicit Character();
    int getCurrency();
    void setCurrency(int amount);
    void incrementCurrency(int amount);
    void decrementCurrency(int amount);
    Ship* getShip();
    void setShip(Ship * ship);
    void Move(int sector);
    int Sector();
    Ingameitem sellItem(QString name);
    bool buyItem(Ingameitem item);
    void addInventoryItem(Ingameitem item);
    void removeInventoryItem(QString name);

private:
    Ship * ship;
    int currency;
    QHash<QString, Ingameitem> inventory;
};

#endif // CHARACTER_H
