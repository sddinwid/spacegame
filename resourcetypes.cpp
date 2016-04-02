#include <QStringList>
#include "resourcetypes.h"

ResourceTypes::ResourceTypes()
{

}
QStringList ResourceTypes::getTypes()
{
    QStringList types;

    types.append("ORE");
    types.append("CRYSTALS");
    types.append("ORGANICS");

    this->length = types.length();

    return types;
}
