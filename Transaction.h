#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDateTime>
#include <QList>

class TransactionItem {
public:
    TransactionItem(const QString &name, const QString &type, const int &quantity);
    const QString &getName() const;
    const QString &getType() const;
    const int &getQuantity() const;

private:
    QString name;
    QString type; // "B" or "M"
    int quantity;
};

class Transaction {
public:
    const QDateTime &getTimestamp() const;
    const QList<TransactionItem> &getItems() const;
    void setTimestamp(const QDateTime &dateTime);
    void addItem(const TransactionItem &item);

private:
    QDateTime timestamp;
    QList<TransactionItem> items;
};

#endif // TRANSACTION_H
