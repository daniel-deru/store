#ifndef BACKUPMANAGER_H
#define BACKUPMANAGER_H

#include "Customer.h"
#include <QList>

class BackupManager {
public:
    static void backup();
    static void restore();

private:
    static QList<Customer> backupData;
};

#endif // BACKUPMANAGER_H
