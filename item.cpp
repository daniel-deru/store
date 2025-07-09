#include "Item.h"

Item::Item(const QString &name, const QString &type)
    : name(name), type(type) {}

void Item::setName(QString &newName)
{
    name = newName;
}

void Item::setType(QString &newType)
{
    type = newType;
}

const QString &Item::getName() const
{
    return name;
}

const QString &Item::getType() const
{
    return type;
}
