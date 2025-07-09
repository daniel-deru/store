
#include "Transaction.h"

#include <QString>

TransactionItem::TransactionItem(const QString &name, const QString &type, const int &quantity): name(name), type(type), quantity(quantity) {}

const QString &TransactionItem::getName() const
{
    return name;
}

const QString &TransactionItem::getType() const
{
    return type;
}

const int &TransactionItem::getQuantity() const
{
    return quantity;
}

const QDateTime &Transaction::getTimestamp() const
{
    return timestamp;
}

const QList<TransactionItem> &Transaction::getItems() const
{
    return items;
}

void Transaction::setTimestamp(const QDateTime &dateTime)
{
    timestamp = dateTime;
}

void Transaction::addItem(const TransactionItem &item)
{
    items.append(item);
}
