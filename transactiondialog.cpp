#include "TransactionDialog.h"
#include "StoreDataModel.h"
#include "ItemRepository.h"
#include "Transaction.h"
#include "BackupManager.h"
#include "newcustomerdialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QDateTime>

TransactionDialog::TransactionDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Shop");
    setupUi();
}

void TransactionDialog::setupUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Complete the required data"));

    QList<Customer> customers = StoreDataModel::instance().getCustomers();

    customerBox = new QComboBox();
    customerBox->setParent(this);
    for (const Customer &c : StoreDataModel::instance().getCustomers())
        customerBox->addItem(c.getName());

    customerLabel = new QLabel("Select the customer:");

    mainLayout->addWidget(customerLabel);
    mainLayout->addWidget(customerBox);

    if(customers.length() <= 0) {
        customerBox->hide();
        customerLabel->hide();
    }

    newCustomerButton = new QPushButton("New Customer", this);
    mainLayout->addWidget(newCustomerButton);


    // Item selection
    itemBox = new QComboBox(this);
    for (const Item &i : ItemRepository::instance().getItems())
        itemBox->addItem(i.getName());
    mainLayout->addWidget(new QLabel("Select the item:"));
    mainLayout->addWidget(itemBox);

    // Quantity input
    quantitySpin = new QSpinBox(this);
    quantitySpin->setRange(0, 100);
    mainLayout->addWidget(new QLabel("Item quantity:"));
    mainLayout->addWidget(quantitySpin);

    // Add item button
    addItemButton = new QPushButton("Add item", this);
    addItemButton->setEnabled(false);
    mainLayout->addWidget(addItemButton);

    // Transaction list display
    transactionList = new QListWidget(this);
    mainLayout->addWidget(transactionList);

    // Done button
    doneButton = new QPushButton("Done", this);
    mainLayout->addWidget(doneButton);



    // Connect logic
    connect(newCustomerButton, &QPushButton::clicked, this, &TransactionDialog::openNewCustomerDialog);
    connect(addItemButton, &QPushButton::clicked, this, &TransactionDialog::onAddItem);
    connect(doneButton, &QPushButton::clicked, this, &TransactionDialog::onDone);
    connect(quantitySpin, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value) {
        addItemButton->setEnabled(value > 0);
    });
}


void TransactionDialog::openNewCustomerDialog() {
    NewCustomerDialog *dialog = new NewCustomerDialog();
    connect(dialog, &NewCustomerDialog::customerAdded, this, &TransactionDialog::handleCustomerAdded);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void TransactionDialog::handleCustomerAdded(const QString &name)
{
    customerBox->clear();
    customerBox->show();
    customerLabel->show();

    const QList<Customer> &customers = StoreDataModel::instance().getCustomers();

    for(const Customer &cus : customers) {
        customerBox->addItem(cus.getName());
    }

    int index = customerBox->findText(name);
    if(index >= 0) {
        customerBox->setCurrentIndex(index);
    }

}

void TransactionDialog::onAddItem() {
    QString itemName = itemBox->currentText();
    int quantity = quantitySpin->value();
    QString itemType;

    if(quantity <= 0)
    {
        return;
    }

    for (const Item &i : ItemRepository::instance().getItems()) {
        if (i.getName() == itemName) {
            itemType = i.getType();
            break;
        }
    }


    QString entry = QString("%1 (%2) x %3").arg(itemName).arg(itemType).arg(quantity);
    transactionList->addItem(entry);

    quantitySpin->setValue(0);
}

void TransactionDialog::onDone() {

    if(transactionList->count() <= 0)
    {
        close();
        return;
    }

    Transaction t;
    t.setTimestamp(QDateTime::currentDateTime());

    for (int i = 0; i < transactionList->count(); ++i) {
        QString entry = transactionList->item(i)->text();
        // Format: "Name (B) x 3"
        int idx1 = entry.indexOf(" (");
        int idx2 = entry.indexOf(") x ");
        QString name = entry.left(idx1);
        QString type = entry.mid(idx1 + 2, 1);
        int quantity = entry.mid(idx2 + 4).toInt();

        t.addItem(TransactionItem{name, type, quantity});
    }

    QString customerName = customerBox->currentText();
    StoreDataModel::instance().addTransaction(customerName, t);
    Customer backupCustomer = StoreDataModel::instance().findCustomer(customerName);
    BackupManager::backupCustomer(backupCustomer);
    emit transactionCompleted();
    close();
}
