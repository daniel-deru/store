#include "BackupManager.h"
#include "StoreDataModel.h"

// Static backup copy
QList<Customer> BackupManager::backupData;

void BackupManager::backup() {
    backupData.clear();
    for (const Customer &c : StoreDataModel::instance().getCustomers()) {
        Customer copy(c.name);
        for (const Transaction &t : c.transactions) {
            Transaction tCopy;
            tCopy.timestamp = t.timestamp;
            for (const TransactionItem &ti : t.items) {
                tCopy.items.append({ti.name, ti.type, ti.quantity});
            }
            copy.transactions.append(tCopy);
        }
        backupData.append(copy);
    }
}

void BackupManager::restore() {
    QList<Customer> customers = StoreDataModel::instance().getCustomers();
    customers = backupData;
}
