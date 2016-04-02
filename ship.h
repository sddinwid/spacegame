#ifndef SHIP_H
#define SHIP_H

#include "cargohold.h"
#include "harvester.h"

class Ship : public Ingameitem
{

public:
    explicit Ship();
    int getID();
    int getHealth();
    void setHealth(int amount);
    int reduceHealthBy(int amount);
    int increaseHealthBy(int amount);
    int getOffense();
    void setOffense(int amount);
    int getDefense();
    void setDefense(int amount);
    int getRange();
    void setRange(int amount);
    int getCurrentSector();
    void setCurrentSector(int newSector);
    Cargohold *getCargoHold();
    void attachCargoHold(Cargohold *cgh);
    Harvester *getHarvester();
    Ingameitem harvest(Resource *res);
    void attachHarvester(Harvester *hrv);
    Cargohold& detachCargoHold();
    Harvester& detachHarvester();

private:
    int ID;
    int health;
    int offense;
    int defense;
    int range;
    int sector;
    Cargohold * cargohold;
    Harvester * harvester;

};

#endif // SHIP_H
