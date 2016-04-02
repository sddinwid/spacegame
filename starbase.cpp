#include "starbase.h"

Starbase::Starbase()
{
    this->setType("starbase");
    this->shipyard = Shipyard();
    this->itemstore = Store();
}

Shipyard *Starbase::getShipyard()
{
    return &shipyard;
}

Store *Starbase::getStore()
{
    return &itemstore;
}
