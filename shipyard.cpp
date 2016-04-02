#include <QDebug>
#include "shipyard.h"

Shipyard::Shipyard() : Store()
{
    this->setName("Shipyard");
    this->setType("shipyard");
    this->setHealth(10);
    this->setCapacity(50);
    this->setDestruct(false);
    this->setQuantity(1);

}
Shipyard::Shipyard(QString name, QString type, int health, int capacity, bool destruct, int quantity) : Store(name, type, health, capacity, destruct, quantity)
{

}

void Shipyard::ViewShips()
{
    QHash<QString, Ship> *r = &ships;
    QHash<QString, Ship>::iterator it;
    qDebug() << "Ships for sale:";
    qDebug() << "Name\t\Offense\tDefense";
    for(it = r->begin(); it != r->end(); ++it)
    {
        Ship res = it.value();
        QString type = it.key();
        while(type.toStdString().length()<8)
        {
            type += " ";
        }
        qDebug() << res.getName() << "\t" << res.getOffense() << "\t\t" << res.getDefense();
    }
}

Ship Shipyard::SellShip(QString name)
{

}

void Shipyard::BuyShip(Ship ship)
{

}
