#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
public:
    Item(const QString &name = "", const QString &type = "", double price = 0.0, int available = 0);

    QString getName() const;
    QString getType() const;
    double getPrice() const;
    int getAvailable() const;

    void setName(const QString &name);
    void setType(const QString &type);
    void setPrice(double price);
    void setAvailable(int available);

private:
    QString name;
    QString type;
    double price;
    int available;
};

#endif // ITEM_H
