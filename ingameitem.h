#ifndef INGAMEITEM_H
#define INGAMEITEM_H

#include "item.h"

class Ingameitem : public Item
{
public:
    Ingameitem();
    Ingameitem(QString name, QString type, int health, int capacity, bool destruct, int quantity);
    int getHealth();
    void setHealth(int amount);
    void increaseHealth(int amount);
    void decreaseHealth(int amount);
    bool getDestruct();
    void setDestruct(bool d);
    void toggleDestruct();
    int getCapacity();
    void setCapacity(int size);
    bool hasCapacity();
    int getValue();
    int getQuantity();
    void setValue(int value);
    void setQuantity(int quant);
    bool isResource();
    void setType(QString type);
    QString getType();
    int GetPower();
    int GetBandwidth();
    void SetPower(int power);
    void SetBandwidth(int bandwidth);

private:
    QString type;
    int health;
    bool destruct;
    int capacity;
    int value;
    int quantity;
    int power;
    int bandwidth;
};

#endif // INGAMEITEM_H
