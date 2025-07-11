#ifndef TRANSACTIONDIALOG_H
#define TRANSACTIONDIALOG_H

#include <QDialog>

class QComboBox;
class QSpinBox;
class QPushButton;
class QListWidget;
class QLabel;

class TransactionDialog : public QDialog {
    Q_OBJECT

public:
    explicit TransactionDialog(QWidget *parent = nullptr);

signals:
    void transactionCompleted();

private slots:
    void onAddItem();
    void onDone();
    void openNewCustomerDialog();
    void handleCustomerAdded(const QString &name);

private:
    QComboBox *customerBox;
    QComboBox *itemBox;
    QSpinBox *quantitySpin;
    QPushButton *addItemButton;
    QPushButton *doneButton;
    QListWidget *transactionList;
    QPushButton *newCustomerButton;
    QLabel *customerLabel;


    void setupUi();
};

#endif // TRANSACTIONDIALOG_H
