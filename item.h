#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
public:
    Item(const QString &name = "", const QString &type = "");

    QString name;
    QString type; // "B" = Book, "M" = Magazine
};

#endif // ITEM_H
