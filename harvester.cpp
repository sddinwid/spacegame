#include "harvester.h"

Harvester::Harvester(QString name, int power, int bandwidth, QString type, int health, int capacity, bool destruct, int quantity) : Ingameitem(name, type, health, capacity, destruct, quantity)
{
    this->setName(name);
    this->SetPower(power);
    this->SetBandwidth(bandwidth);
    this->setType(type);
    this->setHealth(health);
    this->setCapacity(capacity);
    this->setDestruct(destruct);
    this->setQuantity(quantity);
}

Ingameitem Harvester::Harvest(Resource *res, int shipOff, int availCapacity)
{
    Ingameitem harvested = Resource(res->getName(), res->getType(), res->getValue(), res->getHealth(), res->getCapacity(), res->getDestruct(), 0);

    int cResQuant = res->getQuantity();

    int cHarvest = this->GetPower() * this->GetBandwidth() * shipOff;

    float multiple = (rand() % 40 + 60) * .01;

    cHarvest = cHarvest * multiple;

    if(cHarvest > cResQuant)
    {
        // Harvest larger than available
        cHarvest = cResQuant;
    }

    if(cHarvest > availCapacity)
    {
        // Harvest larger than available cargo capacity on ship
        cHarvest = availCapacity;
    }
    harvested.setQuantity(cHarvest);

    return harvested;
}
