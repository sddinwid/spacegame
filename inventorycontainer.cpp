#include "inventorycontainer.h"

Inventorycontainer::Inventorycontainer(QString name, QString type, int health, int capacity, bool destruct, int quantity) : Ingameitem(name, type, health, capacity, destruct, quantity)
{

}
Inventorycontainer::Inventorycontainer() : Ingameitem()
{

}
