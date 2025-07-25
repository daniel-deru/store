#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include <QDialog>

class QLineEdit;
class QComboBox;
class QPushButton;
class QDialog;
class QWidget;
class QSpinBox;
class QDoubleSpinBox;

class ItemDialog : public QDialog {
    Q_OBJECT

public:
    explicit ItemDialog(QWidget *parent = nullptr);

private slots:
    void onInputChanged();
    void onAddItemClicked();

private:
    QLineEdit *itemNameEdit;
    QComboBox *itemTypeBox;
    QPushButton *addItemButton;
    QDoubleSpinBox *priceSpin;
    QSpinBox *availableSpin;

    void setupUi();
};

#endif // ITEMDIALOG_H
