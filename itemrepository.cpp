#include "ItemRepository.h"

ItemRepository &ItemRepository::instance() {
    static ItemRepository instance;
    return instance;
}

void ItemRepository::addItem(const Item &item) {
    for (const Item &existing : items) {
        if (existing.name == item.name && existing.type == item.type)
            return; // no duplicates
    }
    items.append(item);
}

QList<Item> ItemRepository::getItems() const {
    return items;
}
