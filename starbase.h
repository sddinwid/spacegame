#ifndef STARBASE_H
#define STARBASE_H

#include "shipyard.h"

class Starbase : public Ingameitem
{
public:
    Starbase();
    Shipyard *getShipyard();
    Store *getStore();

private:
    Shipyard shipyard;
    Store itemstore;
};

#endif // STARBASE_H
