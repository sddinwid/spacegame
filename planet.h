#ifndef PLANET_H
#define PLANET_H

#include <QHash>
#include <QString>
#include <QStringList>
#include "ship.h"
#include "starbase.h"
#include "resource.h"
#include "resourcetypes.h"

class Planet
{

public:

    explicit Planet(int id);
    void AddShip(Ship ship);
    void RemoveShip(Ship ship);
    int getID();
    int getSize();
    int getWeight();
    QString getSectorResourceList();
    QString getLinkedSectorsString();
    QHash<QString, Resource> *getSectorResources();
    Resource *getResource(QString name);
    QStringList getLinkedSectors();
    QStringList linkedSectors;
    void addLinkedSector(QString lSector);
    void CopyPlanetaryResourcesToStarbase();
    bool hasStarbase();
    Starbase *getStarbase();


private:
    int ID;
    float size;
    int weight;
    void setID(int);
    void setSize(float);
    void setWeight(int);
    QHash<int, Ship> Ships;
    QHash<QString, Resource> Resources;
    Starbase *starbase;
};

#endif // PLANET_H
