#include "BackupManager.h"
#include "StoreDataModel.h"
#include "itemrepository.h"
#include "Customer.h"

// Static backup copy
QList<Customer> BackupManager::backupCustomers;
QList<Item> BackupManager::backupItems;

void BackupManager::backupCustomer(const Customer customer) {

    Customer copy(customer.getName());

    for (const Transaction &t : customer.getTransactions()) {
        Transaction tCopy;
        tCopy.setTimestamp(t.getTimestamp());
        for (const TransactionItem &ti : t.getItems()) {
            tCopy.addItem({ti.getName(), ti.getType(), ti.getQuantity()});

        }
        copy.addTransaction(tCopy);
    }

    backupCustomers.append(copy);
}

void BackupManager::restoreCustomers() {
    QList<Customer> customers = StoreDataModel::instance().getCustomers();
    customers = backupCustomers;
}

void BackupManager::backupItem(const Item item) {
    Item copy(item.getName(), item.getType(), item.getPrice(), item.getAvailable());

    backupItems.append(copy);
}

void BackupManager::restoreItems() {
    QList<Item> items = ItemRepository::instance().getItems();
    items = backupItems;
}

