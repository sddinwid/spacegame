#include <QDebug>
#include "ship.h"

Ship::Ship() : Ingameitem()
{
    this->ID = rand() % 1000000 + 1;
    this->setHealth(100);
    this->setOffense(50);
    this->setDefense(50);
    this->setRange(40);
    this->attachCargoHold(new Cargohold("Cargohold-50", "cargohold", 10, 50, false, 1));
    this->attachHarvester(new Harvester("Harvester-2", 2, 2, "harvester", 10, 0, false, 0));
}
int Ship::getID()
{
    return this->ID;
}

int Ship::getHealth()
{
    return this->health;
}

void Ship::setHealth(int amount)
{
    this->health = amount;
}

int Ship::reduceHealthBy(int amount)
{
    return this->health = this->health - amount;
}

int Ship::increaseHealthBy(int amount)
{
    return this->health = this->health - amount;
}

int Ship::getOffense()
{
    return this->offense;
}

void Ship::setOffense(int amount)
{
    this->offense = amount;
}

int Ship::getDefense()
{
    return this->defense;
}

void Ship::setDefense(int amount){
    this->defense = amount;
}

int Ship::getRange(){
    return this->range;
}

void Ship::setRange(int amount)
{
    this->range = amount;
}

int Ship::getCurrentSector()
{
    return this->sector;
}

void Ship::setCurrentSector(int newSector)
{
    this->sector = newSector;
}

Cargohold *Ship::getCargoHold()
{
    return this->cargohold;
}

void Ship::attachCargoHold(Cargohold *cgh)
{
    this->cargohold = cgh;
}

Cargohold& Ship::detachCargoHold()
{
    Cargohold *c = this->cargohold;
    this->cargohold = nullptr;
    return *c;
}

Harvester *Ship::getHarvester()
{
    return this->harvester;
}

Ingameitem Ship::harvest(Resource *res)
{
    int avail = this->getCargoHold()->getAvailableCapacity();

    return this->harvester->Harvest(res, this->getOffense(), avail);
}

void Ship::attachHarvester(Harvester *hrv)
{
    this->harvester = hrv;
}

Harvester& Ship::detachHarvester()
{
    Harvester *h = this->harvester;
    this->harvester = nullptr;
    return *h;
}
