#include "item.h"

Item::Item()
{

}

QString Item::getName()
{
    return this->name;
}
QString Item::getDescription()
{
    return this->description;
}
void Item::setName(QString name)
{
    this->name = name;
}
void Item::setDescription(QString description)
{
    this->description = description;
}
