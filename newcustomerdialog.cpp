#include "NewCustomerDialog.h"
#include "storedatamodel.h"
#include "newcustomerdialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

NewCustomerDialog::NewCustomerDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Add Customer");
    setupUi();
}

void NewCustomerDialog::setupUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Customer Name:", this);
    nameEdit = new QLineEdit(this);
    addButton = new QPushButton("Add", this);
    addButton->setEnabled(false);

    mainLayout->addWidget(label);
    mainLayout->addWidget(nameEdit);
    mainLayout->addWidget(addButton);

    connect(nameEdit, &QLineEdit::textChanged, this, &NewCustomerDialog::onInputChanged);
    connect(addButton, &QPushButton::clicked, this, &NewCustomerDialog::onAddCustomerClicked);
}

void NewCustomerDialog::onInputChanged() {
    addButton->setEnabled(!nameEdit->text().trimmed().isEmpty());
}

void NewCustomerDialog::onAddCustomerClicked() {
    QString name = nameEdit->text();
    if (!name.isEmpty()) {
        StoreDataModel::instance().addCustomer(name);
        emit customerAdded(name);
        accept(); // close the dialog
    }
}
