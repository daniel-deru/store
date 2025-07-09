#include "BackupManager.h"
#include "StoreDataModel.h"

// Static backup copy
QList<Customer> BackupManager::backupData;

void BackupManager::backup() {
    backupData.clear();
    for (const Customer &c : StoreDataModel::instance().getCustomers()) {
        Customer copy(c.getName());
        for (const Transaction &t : c.getTransactions()) {
            Transaction tCopy;
            tCopy.setTimestamp(t.getTimestamp());
            for (const TransactionItem &ti : t.getItems()) {
                tCopy.addItem({ti.getName(), ti.getType(), ti.getQuantity()});

            }
            copy.addTransaction(tCopy);
        }
        backupData.append(copy);
    }
}

void BackupManager::restore() {
    QList<Customer> customers = StoreDataModel::instance().getCustomers();
    customers = backupData;
}
