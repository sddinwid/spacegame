#include "cargohold.h"

Cargohold::Cargohold(QString name, QString type, int health, int capacity, bool destruct, int quantity) : Inventorycontainer(name, type, health, capacity, destruct, quantity)
{
    this->setName(name);
    this->setType(type);
    this->setHealth(10);
    this->setCapacity(capacity);
    this->setDestruct(destruct);
    this->setQuantity(quantity);
    this->setValue(capacity*12.5);
}
Cargohold::Cargohold()
{

}

QHash<QString, Ingameitem> *Cargohold::GetAllCargo()
{
    return &cargo;
}

int Cargohold::getAvailableCapacity()
{
    int cap = this->getCapacity();
    int count = 0;
    int avail = 0;
    QHash<QString, Ingameitem> ci = this->cargo;
    QHash<QString, Ingameitem>::iterator i;

    for(i = ci.begin(); i != ci.end(); ++i)
    {
        count += i.value().getQuantity();
    }

    avail = cap - count;
    return avail;
}

QStringList Cargohold::ViewAllCargo()
{
    QStringList list;
    QHash<QString, Ingameitem> ch = this->cargo;
    QHash<QString, Ingameitem>::iterator ci;

    for(ci = ch.begin(); ci != ch.end(); ++ci)
    {
        list << ci.key();
    }
    return list;
}

void Cargohold::AddSingleItem(Ingameitem item)
{
    this->cargo.insert(item.getName(), item);
}

void Cargohold::RemoveSingleItem(QString name)
{
    cargo.remove(name);
}

void Cargohold::operator=(const Ingameitem &item)
{
    Ingameitem i = item;
    this->setCapacity(i.getCapacity());
    this->setDescription(i.getDescription());
    this->setDestruct(i.getDestruct());
    this->setHealth(i.getHealth());
    this->setName(i.getName());
    this->setQuantity(i.getQuantity());
    this->setType(i.getType());
    this->setValue(i.getValue());
}
