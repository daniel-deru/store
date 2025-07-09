#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QList>
#include "Transaction.h"

class Customer {
public:
    Customer(const QString &name = "");

    const QString getName() const;
    void setName(const QString &newName);
    void addTransaction(const Transaction &transaction);
    const QList<Transaction> &getTransactions() const;

private:
    QString name;
    QList<Transaction> transactions;
};

#endif // CUSTOMER_H
