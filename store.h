#ifndef STORE_H
#define STORE_H

#include <QHash>
#include "inventorycontainer.h"

class Store : public Inventorycontainer
{
public:
    Store();
    Store(QString name, QString type, int health, int capacity, bool destruct, int quantity);
    void viewInventory();
    void viewSoldByPlayer();
    void buyAllInventory();
    void addInventoryItem(Ingameitem item);
    void removeInventoryItem(QString name);
    Ingameitem sellInventoryItem(QString name);
    int buyInventoryItem(Ingameitem item);

private:
    QHash<QString, Ingameitem> inventory;
    QHash<QString, Ingameitem> soldByPlayer;
};

#endif // STORE_H
