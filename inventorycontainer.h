#ifndef INVENTORYCONTAINER_H
#define INVENTORYCONTAINER_H

#include "ingameitem.h"

class Inventorycontainer : public Ingameitem
{
public:
    Inventorycontainer();
    Inventorycontainer(QString name, QString type, int health, int capacity, bool destruct, int quantity);


private:
};

#endif // INVENTORYCONTAINER_H
