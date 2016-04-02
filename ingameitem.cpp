#include "ingameitem.h"
#include "item.h"

Ingameitem::Ingameitem() : Item()
{

}

Ingameitem::Ingameitem(QString name, QString type, int health, int capacity, bool destruct, int quantity) : Item()
{
    this->setName(name);
    this->setDestruct(destruct);
    this->setHealth(health);
    this->setCapacity(capacity);
    this->setType(type);
    this->setQuantity(quantity);
}

int Ingameitem::getHealth()
{
    return this->health;
}

void Ingameitem::setHealth(int amount)
{
    this->health = amount;
}

void Ingameitem::increaseHealth(int amount)
{
    this->health += amount;
}

void Ingameitem::decreaseHealth(int amount)
{
    this->health -= amount;
}

bool Ingameitem::getDestruct()
{
    return this->destruct;
}

void Ingameitem::setDestruct(bool d)
{
    this->destruct = d;
}

void Ingameitem::toggleDestruct()
{
    this->destruct = !this->destruct;
}

int Ingameitem::getCapacity()
{
    return this->capacity;
}

void Ingameitem::setCapacity(int size)
{
    this->capacity = size;
}

bool Ingameitem::hasCapacity()
{
    if(this->capacity>0)
    {
        return true;
    }
    return false;
}

void Ingameitem::setValue(int value)
{
    this->value = value;
}

void Ingameitem::setQuantity(int quant)
{
    this->quantity = quant;
}

int Ingameitem::getValue()
{
    return this->value;
}

int Ingameitem::getQuantity()
{
    return this->quantity;
}

bool Ingameitem::isResource()
{
    return (this->getType().toLower().trimmed()=="resource");
}

void Ingameitem::setType(QString type)
{
    this->type = type;
}

QString Ingameitem::getType()
{
    return this->type;
}

int Ingameitem::GetPower()
{
    return this->power;
}

int Ingameitem::GetBandwidth()
{
    return this->bandwidth;
}

void Ingameitem::SetPower(int power)
{
    this->power = power;
}

void Ingameitem::SetBandwidth(int bandwidth)
{
    this->bandwidth = bandwidth;
}
