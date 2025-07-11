#include "ItemDialog.h"
#include "ItemRepository.h"
#include "Item.h"
#include "BackupManager.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QMessageBox>

ItemDialog::ItemDialog(QWidget *parent)
    : QDialog(parent, Qt::Dialog)
{
    setWindowTitle("Shop");
    setupUi();
}

void ItemDialog::setupUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *instruction = new QLabel("Complete the required data", this);
    mainLayout->addWidget(instruction);

    // --- Item Type ---
    QHBoxLayout *typeLayout = new QHBoxLayout;
    QLabel *typeLabel = new QLabel("Item type:", this);
    itemTypeBox = new QComboBox(this);
    itemTypeBox->addItems({"Book", "Magazine"});
    typeLayout->addWidget(typeLabel);
    typeLayout->addWidget(itemTypeBox);
    mainLayout->addLayout(typeLayout);

    // --- Item Name ---
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QLabel *nameLabel = new QLabel("Name of item:", this);
    itemNameEdit = new QLineEdit(this);
    itemNameEdit->setFocus();
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(itemNameEdit);
    mainLayout->addLayout(nameLayout);

    // --- Price ---
    QHBoxLayout *priceLayout = new QHBoxLayout;
    QLabel *priceLabel = new QLabel("Price:", this);
    priceSpin = new QDoubleSpinBox(this);
    priceSpin->setRange(0.0, 10000.0);
    priceSpin->setPrefix("R ");
    priceSpin->setDecimals(2);
    priceLayout->addWidget(priceLabel);
    priceLayout->addWidget(priceSpin);
    mainLayout->addLayout(priceLayout);

    // --- Available Quantity ---
    QHBoxLayout *stockLayout = new QHBoxLayout;
    QLabel *availableLabel = new QLabel("Quantity available:", this);
    availableSpin = new QSpinBox(this);
    availableSpin->setRange(0, 1000);
    stockLayout->addWidget(availableLabel);
    stockLayout->addWidget(availableSpin);
    mainLayout->addLayout(stockLayout);

    // --- Add Button ---
    addItemButton = new QPushButton("Add item", this);
    addItemButton->setEnabled(false);
    mainLayout->addWidget(addItemButton);

    // --- Connections ---
    connect(itemNameEdit, &QLineEdit::textChanged, this, &ItemDialog::onInputChanged);
    connect(addItemButton, &QPushButton::clicked, this, &ItemDialog::onAddItemClicked);
}


void ItemDialog::onInputChanged() {
    addItemButton->setEnabled(!itemNameEdit->text().isEmpty());
}

void ItemDialog::onAddItemClicked() {
    QString name = itemNameEdit->text();
    QString type = itemTypeBox->currentText().startsWith("B") ? "B" : "M";
    int price = priceSpin->value();
    int available = availableSpin->value();

    if(price <= 0)
    {
        QMessageBox::warning(this, "Price Is Zero", "Price cannot be zero");
        return;
    }

    if(available <= 0)
    {
        QMessageBox::warning(this, "Available Is Zero", "Available stock cannot be zero");
        return;
    }

    Item item(name, type, price, available);

    ItemRepository::instance().addItem(item);
    BackupManager::backupItem(item);

    itemNameEdit->clear();
    itemNameEdit->setFocus();
    addItemButton->setEnabled(false);

    priceSpin->setValue(0);
    availableSpin->setValue(0);

    itemTypeBox->setCurrentIndex(0);
}
