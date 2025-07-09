#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
public:
    Item(const QString &name = "", const QString &type = "");
    void setName(QString &newName);
    void setType(QString &newType);

    const QString &getName() const;
    const QString &getType() const;


private:
    QString name;
    QString type; // "B" = Book, "M" = Magazine
};

#endif // ITEM_H
