#ifndef RESOURCE_H
#define RESOURCE_H

#include <QObject>
#include <QString>
#include "ingameitem.h"

class Resource : public Ingameitem
{
public:
    Resource();
    Resource(QString name, QString type, int value, int health, int capacity, bool destruct, int quantity);
    static Resource CreateResource(QString rName, int weight, int size);
private:
};

#endif // RESOURCE_H
