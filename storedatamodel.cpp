#include "StoreDataModel.h"

StoreDataModel &StoreDataModel::instance() {
    static StoreDataModel instance;
    return instance;
}

void StoreDataModel::addCustomer(const QString &name) {
    for (Customer &c : customers)
        if (c.name == name) return;
    customers.append(Customer{name});
}

void StoreDataModel::addTransaction(const QString &customerName, const Transaction &t) {
    for (Customer &c : customers) {
        if (c.name == customerName) {
            c.transactions.append(t);
            return;
        }
    }
    Customer newCustomer{customerName};
    newCustomer.transactions.append(t);
    customers.append(newCustomer);
}

QList<Customer> StoreDataModel::getCustomers() const {
    return customers;
}

QString StoreDataModel::toXml() const {
    QString xml = "<transactions>";
    for (const Customer &c : customers) {
        xml += "<customer name=\"" + c.name + "\">";
        for (const Transaction &t : c.transactions) {
            xml += "<transaction time=\"" + t.timestamp.toString(Qt::ISODate) + "\">";
            for (const TransactionItem &ti : t.items) {
                xml += "<item name=\"" + ti.name +
                       "\" type=\"" + ti.type +
                       "\" quantity=\"" + QString::number(ti.quantity) + "\"/>";
            }
            xml += "</transaction>";
        }
        xml += "</customer>";
    }
    xml += "</transactions>";
    return xml;
}
