#include "ItemRepository.h"

ItemRepository &ItemRepository::instance() {
    static ItemRepository instance;
    return instance;
}

void ItemRepository::addItem(const Item &item) {
    for (const Item &existing : items) {
        if (existing.getName() == item.getName() && existing.getName() == item.getType())
            return; // no duplicates
    }
    items.append(item);
}

QList<Item> ItemRepository::getItems() const {
    return items;
}
