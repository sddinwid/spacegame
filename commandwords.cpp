#include <QStringList>
#include <QDebug>
#include "commandwords.h"

CommandWords::CommandWords()
{

    validCommands << "move" << "scan" << "view" << "harvest" << "buy" << "sell" << "equip" << "dock" << "undock" << "help" << "quit";

}

bool CommandWords::isCommand(QString text)
{
    if(this->validCommands.contains(text))
    {
        return true;
    }
    return false;
}

void CommandWords::showAll()
{
    QString cmnds;
    for(QString command : this->validCommands)
    {
        cmnds += command + " ";
    }

    qDebug() << "Available commands are:";
    qDebug() << cmnds.trimmed();
    qDebug() << "";
}
