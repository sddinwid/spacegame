#ifndef HARVESTER_H
#define HARVESTER_H

#include "shipitem.h"
#include "resource.h"

class Harvester : public Shipitem, Ingameitem
{
public:
    Harvester(QString name, int power, int bandwidth, QString type, int health, int capacity, bool destruct, int quantity);
    Ingameitem Harvest(Resource *res, int shipOff, int availCapacity);

private:

};

#endif // HARVESTER_H
