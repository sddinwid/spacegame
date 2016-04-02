#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include "game.h"
#include "universe.h"
#include "parser.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Universe *uni = new Universe();
    Game *game = new Game(uni);
    uni->parse = new Parser();

    Player * p = uni->CreatePlayer();
    p->setDocked(false);

    while(!game->isGameOver())
    {
        if(p->isDocked())
        {
            qDebug().nospace() << "You are currently DOCKED at Sector " << p->getShip()->getCurrentSector() << " Starbase.";
        }else
        {
            qDebug().nospace() << "You are currently in Sector " << p->getShip()->getCurrentSector() << ".";
        }

        qDebug().nospace() << "Adjacent sectors are: " << uni->GetPlanet(p->getShip()->getCurrentSector())->getLinkedSectorsString().trimmed();
        Command command = uni->parse->getCommand();

        // hand command to gameprocessor
        int resp = uni->processCommand(command);
        if(resp==9)
        {
            game->toggleGameOver();
        }
    }
    qDebug() << "Exiting Game";
    return 1;
    //return a.exec();
}
