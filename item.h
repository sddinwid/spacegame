#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{

public:
    explicit Item();
    QString getName();
    QString getDescription();
    void setName(QString name);
    void setDescription(QString description);

protected:
    QString name;
    QString description;

};

#endif // ITEM_H
