#ifndef BACKUPMANAGER_H
#define BACKUPMANAGER_H

#include "Customer.h"
#include "item.h"
#include <QList>

class BackupManager {
public:
    static void backupCustomer(const Customer customer);
    static void restoreCustomers();
    static void backupItem(const Item item);
    static void restoreItems();

private:
    static QList<Customer> backupCustomers;
    static QList<Item> backupItems;
};

#endif // BACKUPMANAGER_H
