#include "character.h"
#include "player.h"
#include "ship.h"

Player::Player()
{
    Ship * s = new Ship();
    this->setShip(s);
}
Ship *Player::getPlayerShip()
{
    return this->Character::getShip();
}

void Player::setPlayerShip(Ship *ship)
{
    this->Character::setShip(ship);
}

QString Player::getPlayerName()
{
    return this->name;
}

void Player::setPlayerName(QString name)
{
    this->name = name;
}

QString Player::getCharacterName()
{
    return this->cname;
}

void Player::setCharacterName(QString name)
{
    this->cname = name;
}

bool Player::isDocked()
{
    return this->docked;
}

void Player::toggleDocked()
{
    this->docked = !this->docked;
}

void Player::setDocked(bool d)
{
    this->docked = d;
}
