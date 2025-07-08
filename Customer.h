#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QList>
#include "Transaction.h"

class Customer {
public:
    QString name;
    QList<Transaction> transactions;

    Customer(const QString &name = "") : name(name) {}
};

#endif // CUSTOMER_H
