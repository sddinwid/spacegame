#ifndef RESOURCEGENERATOR_H
#define RESOURCEGENERATOR_H

#include <QObject>
#include <QHash>
#include <QString>
#include "planet.h"
#include "resource.h"

class ResourceGenerator
{

public:
    explicit ResourceGenerator();
    QHash<QString, Resource> generatePlanetResource(int weight, int size);

};

#endif // RESOURCEGENERATOR_H
