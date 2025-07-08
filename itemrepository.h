#ifndef ITEMREPOSITORY_H
#define ITEMREPOSITORY_H

#include "Item.h"
#include <QList>

class ItemRepository {
public:
    static ItemRepository &instance();

    void addItem(const Item &item);
    QList<Item> getItems() const;

private:
    ItemRepository() = default;
    QList<Item> items;
};

#endif // ITEMREPOSITORY_H
