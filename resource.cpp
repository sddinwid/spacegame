#include "resource.h"

Resource::Resource() : Ingameitem()
{

}

Resource::Resource(QString name, QString type, int value, int health, int capacity, bool destruct, int quantity) : Ingameitem(name, type, health, capacity, destruct, quantity)
{
    this->setValue(value);
    this->setCapacity(200);
}

Resource Resource::CreateResource(QString rName, int weight, int size)
{
    /*
     * planet size  =  40 - 100
     */
    int s = size;
     /* weight = density = 0.5-3 */
    float w = weight;
    if(w==0) w=0.5; // 0 weight planet gets half quantity

     /* ore should be 2000 quantity base 10 value base
     * crystals 1000 quantity base 50 value base
     * organics 500 quantity base 100 value base
     */

    int quantity;
    int value;
    if(rName=="ORE"){
        quantity = 2000;
        value = 10;
    }
    else if(rName=="CRYSTALS"){
        quantity = 1000;
        value = 50;
    }
    else if(rName=="ORGANICS"){
        quantity = 500;
        value = 100;
    }

    quantity = quantity * w * (.01 * s);
    value = value * (w * s * .01);
    if(value< 5) value = 5;

    Resource r = Resource(rName, "resource", value, 10,0, false, quantity);
    return r;
}
