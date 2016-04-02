#include "resourcegenerator.h"
#include "resourcetypes.h"
#include "resource.h"
#include <QHash>
#include <qDebug>

ResourceGenerator::ResourceGenerator()
{

}
QHash<QString, Resource> ResourceGenerator::generatePlanetResource(int weight, int size)
{
    // weight is a calculated valuation of each planet
    //     used to assist in deciding how much is
    //      generated in terms of quantity and quality

    QHash<QString, Resource> resourceTable;
    ResourceTypes *rt = new ResourceTypes();
    QStringList types = rt->getTypes();
    int resourceCount = 0;
    int resourceQuantity = 0;
    int resourceStart = 0;

    /*
     *  Using weight, generate how many resources
     */
    switch(weight) {
        case 10:
        case 9:
        case 8:
        case 7:
        case 6:
        case 5:
        case 4:
        case 3:
            resourceCount = 3;
            break;
        case 2:
            resourceCount = 2;
            break;
        case 1:
        case 0:
            resourceCount = 1;
            break;
    }
    //qDebug() << "resourcecount=" << resourceCount;
    for(int i = 0; i < resourceCount; i++) {

        QString name = types[i];

        //qDebug() << i << name;

        resourceTable.insert(name, Resource::CreateResource(name, weight, size));
        /*
        if(types[i]=="ORGANICS")
        {
            qDebug() << "Organics";
        }
        else if(types[i]=="CRYSTALS")
        {
            qDebug() << "Crystals";
        }
        else if(types[i]=="MINERALS")
        {
            qDebug() << "Minerals";
        }
        */
    }

    return resourceTable;
}
