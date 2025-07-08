#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDateTime>
#include <QList>

class TransactionItem {
public:
    QString name;
    QString type; // "B" or "M"
    int quantity;
};

class Transaction {
public:
    QDateTime timestamp;
    QList<TransactionItem> items;
};

#endif // TRANSACTION_H
