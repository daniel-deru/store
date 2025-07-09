#include <QString>

#include "Customer.h"

Customer::Customer(const QString &name) : name(name) {}

const QString Customer::getName() const
{
    return name;
}

void Customer::setName(const QString &newName)
{
    name = newName;
}

void Customer::addTransaction(const Transaction &transaction)
{
    transactions.append(transaction);
}

const QList<Transaction> &Customer::getTransactions() const
{
    return transactions;
}
