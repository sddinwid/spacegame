#include <QDebug>
#include "store.h"

Store::Store() : Inventorycontainer()
{
    this->setName("");
    this->setType("store");
    this->setHealth(10);
    this->setCapacity(300);
    this->setDestruct(false);
    this->setQuantity(1);

    Ingameitem item = Ingameitem();
    item.setCapacity(100);
    item.setName("Cargohold-100");
    item.setQuantity(1);
    item.setDestruct(false);
    item.setHealth(10);
    item.setType("cargohold");
    item.setValue(5000);

    this->addInventoryItem(item);

}
Store::Store(QString name, QString type, int health, int capacity, bool destruct, int quantity) : Inventorycontainer(name, type, health, capacity, destruct, quantity)
{

}

void Store::viewInventory()
{
    QHash<QString, Ingameitem> *inv = &inventory;
    QHash<QString, Ingameitem>::iterator it;
    qDebug() << "Store Inventory:";
    qDebug() << "Name\t\t\tQuantity\tValue";
    for(it = inv->begin(); it != inv->end(); ++it)
    {
        Ingameitem res = it.value();
        QString type = it.key();
        while(type.toStdString().length()<20)
        {
            type += " ";
        }
        qDebug().noquote().nospace() << type << "\t" << res.getQuantity() << "\t\t" << res.getValue();
    }
}

void Store::viewSoldByPlayer()
{
    QHash<QString, Ingameitem> *inv = &soldByPlayer;
    QHash<QString, Ingameitem>::iterator it;
    qDebug() << "Sold By Player:";
    qDebug() << "Name\t\t\tQuantity\tValue";
    for(it = inv->begin(); it != inv->end(); ++it)
    {
        Ingameitem res = it.value();
        QString type = it.key();
        while(type.toStdString().length()<20)
        {
            type += " ";
        }
        qDebug().noquote().nospace() << type << "\t" << res.getQuantity() << "\t\t" << res.getValue();
    }
}

void Store::buyAllInventory()
{

}

Ingameitem Store::sellInventoryItem(QString name)
{
    Ingameitem item = inventory.find(name).value();

    return item;
}

int Store::buyInventoryItem(Ingameitem item)
{
    int price;
    QHash<QString, Ingameitem>::iterator i = inventory.find(item.getName());
    if(i!=inventory.end())
    {
        if(i.value().getValue() > item.getValue())
        {
            price = i.value().getValue() * item.getQuantity();
        }
        else
        {
            price = item.getValue() * item.getQuantity();
        }
    }
    else
    {
        price = item.getValue() * item.getQuantity();
    }
    addInventoryItem(item);
    return price;
}

void Store::addInventoryItem(Ingameitem item)
{
    QHash<QString, Ingameitem>::iterator i = inventory.find(item.getName());
    if(i!=inventory.end())
    {
        i.value().setQuantity(i.value().getQuantity()+item.getQuantity());
    }
    else
    {
        this->inventory.insert(item.getName(), item);
    }
}

void Store::removeInventoryItem(QString name)
{
    this->inventory.remove(name);
}
