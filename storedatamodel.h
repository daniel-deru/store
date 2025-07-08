#ifndef STOREDATAMODEL_H
#define STOREDATAMODEL_H

#include "Customer.h"
#include "Transaction.h"
#include <QObject>
#include <QList>
#include <QString>

class StoreDataModel : public QObject {
    Q_OBJECT

public:
    static StoreDataModel &instance();

    void addCustomer(const QString &name);
    void addTransaction(const QString &customerName, const Transaction &t);
    QList<Customer> getCustomers() const;
    QString toXml() const;

private:
    StoreDataModel() = default;
    QList<Customer> customers;
};

#endif // STOREDATAMODEL_H
