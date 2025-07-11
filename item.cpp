#include "Item.h"

Item::Item(const QString &name, const QString &type, double price, int available)
    : name(name), type(type), price(price), available(available) {}

QString Item::getName() const
{
    return name;
}
QString Item::getType() const
{
    return type;
}
double Item::getPrice() const
{
    return price;
}
int Item::getAvailable() const
{
    return available;
}

void Item::setName(const QString &name)
{
    this->name = name;
}
void Item::setType(const QString &type)
{
    this->type = type;
}
void Item::setPrice(double price)
{
    this->price = price;
}
void Item::setAvailable(int available)
{
    this->available = available;
}
