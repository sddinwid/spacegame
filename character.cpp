#include "character.h"

Character::Character() : Item()
{
    currency = 0;
}

int Character::getCurrency()
{
    return currency;
}

void Character::setCurrency(int amount)
{
    currency = amount;
    if(currency < 0)
    {
        currency = 0;
    }
}

void Character::incrementCurrency(int amount)
{
    currency += amount;
}

void Character::decrementCurrency(int amount)
{
    currency -= amount;
    if(currency < 0)
    {
        currency = 0;
    }
}

Ship *Character::getShip()
{
    return this->ship;
}

void Character::setShip(Ship *ship)
{
    this->ship = ship;
}

void Character::Move(int sector)
{
    this->ship->setCurrentSector(sector);
}
int Character::Sector()
{
    return this->ship->getCurrentSector();
}

Ingameitem Character::sellItem(QString name)
{
    Ingameitem item = ship->getCargoHold()->GetAllCargo()->take(name);

    return item;
}

bool Character::buyItem(Ingameitem item)
{
    int total = item.getValue() * item.getQuantity();
    if(currency - total < 0)
    {
        return false;
    }
    currency -= total;

    addInventoryItem(item);
    return true;
}

void Character::addInventoryItem(Ingameitem item)
{
    ship->getCargoHold()->GetAllCargo()->insert(item.getName(), item);
}

void Character::removeInventoryItem(QString name)
{
    ship->getCargoHold()->GetAllCargo()->remove(name);
}
