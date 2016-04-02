#include "character.h"
#include "npc.h"

NPC::NPC() : Character()
{

}
Ship *NPC::getNPCShip()
{
    return this->Character::getShip();
}

void NPC::setNPCShip(Ship *ship)
{
    this->Character::setShip(ship);
}
