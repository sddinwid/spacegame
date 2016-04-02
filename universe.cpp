#include "QTextStream"
#include <QDebug>
#include <QLocale>
#include "game.h"
#include "universe.h"
#include "planet.h"
#include "player.h"
#include "commandwords.h"

Universe::Universe()
{
    this->size = 1000;
    qDebug() << "Creating Universe....";

    GenerateUniverse();

    qDebug() << "Creating Spaceways....";

    CreateSpaceways();

    qDebug() << "Done.";
}
void Universe::GenerateUniverse()
{

    // Loop through size creating planets.
    for(int i = 0; i < this->size; i++)
    {
        this->planets.insert(i, new Planet(i));
    }

}
void Universe::CreateSpaceways()
{
    // define variables
    int cSector; // current sector
    int nSector; // next sector


    for(int i = 0; i < this->size; i++)
    {
        // start at sector 0
        cSector = i;

        // randomize between 2 and 4 connections
        int count = rand() % 2 + 2;

        int currlen = this->planets.find(cSector).value()->getLinkedSectors().length();

        if(currlen >= 2)
        {
            continue;
        }

        if(currlen > count)
        {
            // current length is greater than randomized count
            continue;
        }
        else if(currlen != count)
        {
            // current length less than count
            // reduce count by current length
            count = count - currlen;
        }

        for(int j = 0; j < count; j++)
        {

            //randomize next sector
            nSector = rand() % 999 + 1;

            while(nSector==cSector)
            {
                nSector = rand() % 999 + 1;
            }

            this->planets.find(cSector).value()->addLinkedSector(QString::number(nSector));

            this->planets.find(nSector).value()->addLinkedSector(QString::number(cSector));


            qDebug().nospace() << "Linked Sector " << nSector << " to Sector " << cSector << ".";

        }

    }
}

Player *Universe::CreatePlayer()
{
    QTextStream cin(stdin);

    QString userName, charName, word1, word2;

    qDebug() << "Enter your name: ";
    userName = cin.readLine();

    qDebug() << "Enter your character name: ";
    charName = cin.readLine();

    Player * p = this->player = new Player();

    p->setPlayerName(userName);
    p->setCharacterName(charName);
    p->setCurrency(10000);
    int size = this->size;
    srand(0);
    int randsect = rand() % size + 1;
    p->getPlayerShip()->setCurrentSector(randsect);

    return p;
}

int Universe::processCommand(Command command)
{
    if(command.isUnknown())
    {
        qDebug() << "Command unknown. Please try again.";
        return false;
    }

    QString cmd = command.getCommandWord();
    if(!command.getSecondWord().isEmpty())
    {
        QString second;
        second = command.getSecondWord();
        Planet * p = this->GetPlanet(this->player->getShip()->getCurrentSector());
        QStringList ls = p->getLinkedSectors();
        QString sect = QString::number(this->player->getShip()->getCurrentSector());
        ls << sect;
        if(!ls.contains(second))
        {
            if(cmd.toLower().toStdString()=="scan")
            {
                qDebug() << "";
                qDebug() << "Can only scan adjacent sectors.";
                qDebug() << "No long range sensors yet.";
                qDebug() << "";
                return false;
            }
            if(cmd.toLower().toStdString()=="move")
            {
                qDebug() << "";
                qDebug() << "Can only move to adjacent sectors.";
                qDebug() << "No quantum drives yet.";
                qDebug() << "";
                return false;
            }
        }
    }
    if(cmd.toLower().toStdString()=="move")
    {
        if(this->player->isDocked())
        {
            qDebug() << "";
            qDebug() << "Must Undock before trying to move.";
            qDebug() << "";
            return 1;
        }
        qDebug() << "";
        qDebug() << "Move";
        QString second;
        if(!command.getSecondWord().isEmpty())
        {
            second = command.getSecondWord();
            if(second.toInt())
            {
                this->player->getShip()->setCurrentSector(second.toInt());
            }
        }
        qDebug() << "";
        return 1;
    }
    else if(cmd.toLower().toStdString()=="sell")
    {
        if (!this->player->isDocked())
        {
            qDebug() << "Must be docked to interact with a store.";
            return 1;
        }
        qDebug() << "";
        QString second;
        if(command.getSecondWord().isEmpty())
        {
            second = "ORE";
        }
        else
        {
            second = command.getSecondWord().toUpper();
        }

        if(second.contains("CARGOHOLD"))
        {
            QStringList qt = second.split("-");

            QString f = qt.at(0);

            QRegExp re("\\d*");
            QString s = qt.at(1);
            QString q;
            if(re.exactMatch(s))
            {
                q = qt.at(1);
            }

            second = "Cargohold-" + q;
        }
        else if(second.contains("HARVESTER"))
        {
            QStringList qt = second.split("-");

            QString f = qt.at(0);

            QRegExp re("\\d*");
            QString s = qt.at(1);
            QString q;
            if(re.exactMatch(s))
            {
                q = qt.at(1);
            }

            second = "Harvester" + q;
        }

        Planet * p = this->GetPlanet(this->player->getShip()->getCurrentSector());
        int currcurr = this->player->getCurrency();
        this->player->incrementCurrency(p->getStarbase()->getStore()->buyInventoryItem(this->player->sellItem(second)));
        QLocale us(QLocale::English, QLocale::UnitedStates);
        qDebug() << "";
        qDebug().noquote().nospace() << "Added " << us.toString(this->player->getCurrency()-currcurr) << " coins.";
        qDebug().noquote().nospace() << "Currency now at: " << us.toString(this->player->getCurrency())<< " coins.";
        qDebug() << "";
        return 1;
    }
    else if(cmd.toLower().toStdString()=="buy")
    {
        if (!this->player->isDocked())
        {
            qDebug() << "Must be docked to interact with a store.";
            return 1;
        }
        qDebug() << "";
        QString second;
        if(command.getSecondWord().isEmpty())
        {
            second = "ORE";
        }
        else
        {
            second = command.getSecondWord().toUpper();
        }


        if(second.contains("CARGOHOLD"))
        {
            QStringList qt = second.split("-");

            QString f = qt.at(0);

            QRegExp re("\\d*");
            QString s = qt.at(1);
            QString q;
            if(re.exactMatch(s))
            {
                q = qt.at(1);
            }

            second = "Cargohold-" + q;
        }

        Planet * p = this->GetPlanet(this->player->getShip()->getCurrentSector());
        int currcurr = this->player->getCurrency();
        this->player->buyItem(p->getStarbase()->getStore()->sellInventoryItem(second));
        QLocale us(QLocale::English, QLocale::UnitedStates);
        qDebug() << "";
        qDebug().noquote().nospace() << "Subtracted " << us.toString(this->player->getCurrency()-currcurr) << " coins.";
        qDebug().noquote().nospace() << "Currency now at: " << us.toString(this->player->getCurrency())<< " coins.";
        qDebug() << "";
        return 1;
    }
    else if(cmd.toLower().toStdString()=="equip")
    {

        qDebug() << "";
        QString second;
        if(command.getSecondWord().isEmpty())
        {
            qDebug() << "";
            qDebug() << "Must provide name of item to equip.";
            qDebug() << "";
            return 1;
        }
        else
        {
            second = command.getSecondWord().toUpper();
        }

        if(second.contains("CARGOHOLD"))
        {
            QStringList qt = second.split("-");

            QString f = qt.at(0);

            QRegExp re("\\d*");
            QString s = qt.at(1);
            QString q;
            if(re.exactMatch(s))
            {
                q = qt.at(1);
            }

            second = "Cargohold-" + q;
        }
        else if(second.contains("HARVESTER"))
        {
            QStringList qt = second.split("-");

            QString f = qt.at(0);

            QRegExp re("\\d*");
            QString s = qt.at(1);
            QString q;
            if(re.exactMatch(s))
            {
                q = qt.at(1);
            }

            second = "Harvester" + q;
        }

        Planet * p = this->GetPlanet(this->player->getShip()->getCurrentSector());

        if(this->player->getShip()->getCargoHold()->GetAllCargo()->find(second).value().getName() == second)
        {
            // found
            Cargohold item;
            item = this->player->getShip()->getCargoHold()->GetAllCargo()->take(second);

            if(item.getType()=="cargohold")
            {
                Cargohold c = this->player->getShip()->detachCargoHold();
                this->player->getShip()->attachCargoHold(new Cargohold(item.getName(), item.getType(), item.getHealth(), item.getCapacity(), item.getDestruct(), item.getQuantity()));
                this->player->getShip()->getCargoHold()->AddSingleItem(c);
            }
            else if(item.getType()=="harvester")
            {

            }

        }
        else
        {
            // not found
            qDebug() << "";
            qDebug() << second << " not found.";
            qDebug() << "";
        }
        return 1;
    }
    else if(cmd.toLower().toStdString()=="view")
    {
        qDebug() << "";
        QString second;
        if(command.getSecondWord().isEmpty())
        {
            second = "cargo";
        }
        else
        {
            second = command.getSecondWord();
        }

        if(second=="cargo")
        {
            QHash<QString, Ingameitem> *r = this->player->getShip()->getCargoHold()->GetAllCargo();
            QHash<QString, Ingameitem>::iterator it;
            qDebug() << "Cargo:";
            qDebug() << "Name\t\tQuantity\tValue";
            for(it = r->begin(); it != r->end(); ++it)
            {
                Ingameitem res = it.value();
                QString type = it.key();
                while(type.toStdString().length()<8)
                {
                    type += " ";
                }
                qDebug().noquote().nospace() << type << "\t" << res.getQuantity() << "\t\t" << res.getValue();
            }
        }
        else if (this->player->isDocked())
        {
            Planet * p = this->GetPlanet(this->player->getShip()->getCurrentSector());
            Starbase * sb = p->getStarbase();
            if(second == "store")
            {// starbase store
                sb->getStore()->viewInventory();
            }else if(second=="shipyard")
            {// starbase shipyard
                sb->getShipyard()->ViewShips();
            }else if(second=="soldbyplayer")
            {// starbase soldbyplayer
                sb->getStore()->viewSoldByPlayer();
            }
        }

        qDebug() << "";
        return 1;
    }
    else if(cmd.toLower().toStdString()=="scan")
    {
        if(this->player->isDocked())
        {
            qDebug() << "";
            qDebug() << "Must Undock before trying to scan.";
            qDebug() << "";
            return 1;
        }
        qDebug() << "";
        int second;
        if(command.getSecondWord().isEmpty())
        {
            second = player->Sector();
        }
        else
        {
            second = command.getSecondWord().toInt();
        }

        Planet * p = this->GetPlanet(second);

        qDebug().nospace().noquote() << "Scanning Sector " << second << "...";

        qDebug() << "";
        if(p->hasStarbase())
        {
            qDebug().nospace() << "Starbase FOUND in Sector " << second << "!";
            qDebug() << "";
        }
        QHash<QString, Resource> *r = p->getSectorResources();
        QHash<QString, Resource>::iterator it;
        qDebug() << "Resources:";
        qDebug() << "Type\t\tQuantity\tValue";
        for(it = r->begin(); it != r->end(); ++it)
        {
            Resource res = it.value();
            QString type = it.key();
            while(type.toStdString().length() < 8)
            {
                type += " ";
            }
            qDebug().nospace().noquote() << type << "\t" << res.getQuantity() << "\t\t" << res.getValue();
        }

        qDebug() << "";
        return 1;
    }
    else if(cmd.toLower().toStdString()=="harvest")
    {
        if(this->player->getShip()->getCargoHold()->getAvailableCapacity() <= 0)
        {
            qDebug() << "";
            qDebug().noquote().nospace() << "Cargohold is full. Sell current cargo at a starbase to free space.";
            qDebug() << "";
            return 1;
        }
        qDebug() << "";
        int sector = player->Sector();
        QString second;
        if(command.getSecondWord().isEmpty())
        {
            second = "ORE";
        }
        else
        {
            if(command.getSecondWord().toInt())
            {
                qDebug() << "Harvest usage:";
                qDebug() << "harvest <type>";
                qDebug() << "Harvest ore";
                return 1;
            }
            second = command.getSecondWord().toUpper();
        }

        Planet * p = this->GetPlanet(sector);

        qDebug().nospace().noquote() << "Locking on to Sector " << sector << " " << second << ".";
        QHash<QString, Resource> *r = p->getSectorResources();
        QHash<QString, Resource>::iterator it = r->find(second);
        Resource source = it.value();
        Ingameitem harvested = this->player->getShip()->harvest(&source);
        p->getResource(harvested.getName())->setQuantity(source.getQuantity()-harvested.getQuantity());
        QHash<QString, Ingameitem> *cargo = this->player->getShip()->getCargoHold()->GetAllCargo();
        QHash<QString, Ingameitem>::iterator i = cargo->begin();
        bool found = false;
        while (i != cargo->end()) {
            QHash<QString, Ingameitem>::iterator prev = i;
            ++i;
            if (prev.key().toLower()==harvested.getName().toLower())
            {
                int curr = prev.value().getQuantity();
                int newval = curr + harvested.getQuantity();

                prev.value().setQuantity(newval);
                found =true;
            }
        }
        if(!found)
        {
            cargo->insert(harvested.getName(), harvested);
        }

        qDebug() << "";
        return 1;
    }
    else if(cmd.toLower().toStdString()=="dock")
    {
        Planet * p = this->GetPlanet(this->player->Sector());
        if(!p->hasStarbase())
        {
            qDebug() << "";
            qDebug() << "Sector" << this->player->Sector() << "doesn't have a Starbase to dock at.";
            qDebug() << "";
            return 1;
        }
        if(!this->player->isDocked())
        {
            // handle docking at starbase
            qDebug() << "";
            qDebug() << "Docking at Starbase" << this->player->Sector() << "...";
            this->player->setDocked(true);
            qDebug() << "Docked. Sensors and propulsion inactive.";
            qDebug() << "";
        }
        else
        {
            qDebug() << "";
            qDebug() << "You are already docked at Starbase" << this->player->Sector() << "...";
            qDebug() << "Sensors and propulsion inactive.";
            qDebug() << "";
        }

        return 1;
    }
    else if(cmd.toLower().toStdString()=="undock")
    {
        if(!this->player->isDocked())
        {
            qDebug() << "";
            qDebug() << "You aren't currently docked at a Starbase.";
            qDebug() << "";
            return 1;
        }
        // handle undocking from starbase
        qDebug() << "";
        qDebug() << "Undocking from Starbase" << this->player->Sector() << "...";
        this->player->setDocked(false);
        qDebug() << "Undocked. Sensors and propulsion active.";
        qDebug() << "";

        return 1;
    }
    else if(cmd.toLower().toStdString()=="help")
    {
        this->parse->showCommands();
        return 1;
    }
    else if(cmd.toLower().toStdString()=="quit")
    {
        qDebug() << "";
        return 9;
    }
    return false;
}

Planet *Universe::GetPlanet(int sector)
{
    return this->planets[sector];
}
