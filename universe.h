#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "planet.h"
#include "ship.h"
#include "game.h"
#include "command.h"
#include "parser.h"
#include "player.h"

class Universe
{

public:
    explicit Universe();
    void GenerateUniverse();
    void CreateSpaceways();
    Player *CreatePlayer();
    Planet *GetPlanet(int sector);
    Parser * parse;
    Player * player;
    int processCommand(Command command);


private:
    int ID;
    int size;
    QHash<int, Planet*> planets;
    QHash<int, Ship*> ships;


};

#endif // UNIVERSE_H
