#include <QDebug>
#include "planet.h"
#include "item.h"
#include "resourcegenerator.h"

Planet::Planet(int id)
{
    int w = 0;
    int r = rand() % 100 + 1;
    switch(r)
    {
        case 100:
            //w = 10;
            w = 3;
            break;
        case 99:
            //w = 9;
            w = 3;
            break;
        case 98:
            //w = 8;
            w = 3;
            break;
        case 97:
            //w = 7;
            w = 3;
            break;
        case 96:
            //w = 6;
            w = 3;
            break;
        case 95:
            //w = 5;
            w = 3;
            break;
        case 94:
        case 93:
            //w = 4;
            w = 3;
            break;
        case 92:
        case 91:
            w = 3;
            break;
        case 90:
        case 89:
        case 88:
        case 87:
        case 86:
        case 85:
            w = 2;
            break;
        case 84:
        case 83:
        case 82:
        case 81:
        case 80:
        case 79:
        case 78:
        case 77:
        case 76:
        case 75:
        case 74:
        case 73:
        case 72:
        case 71:
        case 70:
        case 69:
        case 68:
        case 67:
        case 66:
        case 65:
        case 64:
        case 63:
        case 62:
        case 61:
        case 60:
            w = 1;
            break;
        default:
            w = 0;
            break;
    }

    this->ID = id;
    this->size = rand() % 50 + 50;
    this->weight = w;
    this->starbase = new Starbase();
    this->starbase->setType("null");

    ResourceGenerator *rg = new ResourceGenerator();
    this->Resources = rg->generatePlanetResource(this->weight, this->size);

    qDebug().nospace() << "Generated Planet " << id << ", size of '" << this->size << "', weight of '" << this->weight << "'.";

}
void Planet::AddShip(Ship ship)
{
    this->Ships.insert(ship.getID(), ship);
}

void Planet::RemoveShip(Ship ship)
{
    //int key = this->Ships.f
    //this->Ships.remove(key);
}

int Planet::getID()
{
    return this->ID;
}

int Planet::getSize()
{
    return this->size;
}

int Planet::getWeight()
{
    return this->weight;
}

QStringList Planet::getLinkedSectors()
{
    return this->linkedSectors;
}

QString Planet::getLinkedSectorsString()
{
    QStringList ls = this->getLinkedSectors();
    QString sects;
    for(int s = 0; s < ls.length(); s++) {
        sects += ls[s];
        if(s != ls.length() -1)
        {
            sects +=  " ";
        }
    }
    return sects;
}

void Planet::addLinkedSector(QString lSector)
{

    this->linkedSectors.insert(this->linkedSectors.length(), lSector);
    if(this->linkedSectors.length() > 3 && this->starbase->getType()=="null")
    {
        this->starbase = new Starbase();
        CopyPlanetaryResourcesToStarbase();
    }

}

QString Planet::getSectorResourceList()
{
    QHash<QString, Resource> rl = this->Resources;

    QString str;
    QList<QString> list = rl.keys();
    for(int i = 0; i < list.size(); i++){
        str += list[i];
        if(i != list.size()-1)
        {
            str +=  " ";
        }
    }

    return str;
}

QHash<QString, Resource> *Planet::getSectorResources()
{
    //QHash<QString, Resource> * r = this->Resources;
    return &Resources;
}

Resource *Planet::getResource(QString name)
{
    return &(this->Resources.find(name).value());
}

void Planet::CopyPlanetaryResourcesToStarbase()
{
    if(this->hasStarbase())
    {
        QHash<QString, Resource>::iterator i = this->Resources.begin();
        while (i != this->Resources.end()) {
            QHash<QString, Resource>::iterator prev = i;
            ++i;
            this->getStarbase()->getStore()->addInventoryItem(prev.value());
        }
    }
}

bool Planet::hasStarbase()
{
    if(this->starbase->getType()=="starbase")
    {
        return true;
    }
    return false;
}

Starbase *Planet::getStarbase()
{
    return this->starbase;
}
