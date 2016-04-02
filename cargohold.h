#ifndef CARGOHOLD_H
#define CARGOHOLD_H

#include <QHash>
#include <QString>
#include "shipitem.h"

class Cargohold : public Shipitem, public Inventorycontainer
{
public:
    Cargohold(QString name, QString type, int health, int capacity, bool destruct, int quantity);
    Cargohold();
    QHash<QString, Ingameitem> *GetAllCargo();
    QStringList ViewAllCargo();
    int getAvailableCapacity();
    void AddSingleItem(Ingameitem item);
    void RemoveSingleItem(QString name);
    void operator=(const Ingameitem &item);


private:
    QHash<QString, Ingameitem> cargo;
};

#endif // CARGOHOLD_H
