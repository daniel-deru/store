#include "StoreDataModel.h"

StoreDataModel &StoreDataModel::instance() {
    static StoreDataModel instance;
    return instance;
}

void StoreDataModel::addCustomer(const QString &name) {
    for (Customer &c : customers)
        if (c.getName() == name) return;
    customers.append(Customer{name});
}

void StoreDataModel::addTransaction(const QString &customerName, const Transaction &t) {
    for (Customer &c : customers) {
        if (c.getName() == customerName) {
            c.addTransaction(t);
            return;
        }
    }
    Customer newCustomer{customerName};
    newCustomer.addTransaction(t);
    customers.append(newCustomer);
}

QList<Customer> StoreDataModel::getCustomers() const {
    return customers;
}

QString StoreDataModel::toXml() const {
    QString xml = "<transactions>";
    for (const Customer &c : customers) {
        xml += "<customer name=\"" + c.getName() + "\">";
        for (const Transaction &t : c.getTransactions()) {
            xml += "<transaction time=\"" + t.getTimestamp().toString(Qt::ISODate) + "\">";
            for (const TransactionItem &ti : t.getItems()) {
                xml += "<item name=\"" + ti.getName() +
                       "\" type=\"" + ti.getType() +
                       "\" quantity=\"" + QString::number(ti.getQuantity()) + "\"/>";
            }
            xml += "</transaction>";
        }
        xml += "</customer>";
    }
    xml += "</transactions>";
    return xml;
}
