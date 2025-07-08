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

    // Type
    QHBoxLayout *typeLayout = new QHBoxLayout;
    QLabel *typeLabel = new QLabel("Item type:", this);
    itemTypeBox = new QComboBox(this);
    itemTypeBox->addItems({"Book", "Magazine"});
    typeLayout->addWidget(typeLabel);
    typeLayout->addWidget(itemTypeBox);
    mainLayout->addLayout(typeLayout);

    // Name
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QLabel *nameLabel = new QLabel("Name of item:", this);
    itemNameEdit = new QLineEdit(this);
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(itemNameEdit);
    mainLayout->addLayout(nameLayout);

    // Add button
    addItemButton = new QPushButton("Add item", this);
    addItemButton->setEnabled(false);
    mainLayout->addWidget(addItemButton);

    connect(itemNameEdit, &QLineEdit::textChanged, this, &ItemDialog::onInputChanged);
    connect(addItemButton, &QPushButton::clicked, this, &ItemDialog::onAddItemClicked);
}

void ItemDialog::onInputChanged() {
    addItemButton->setEnabled(!itemNameEdit->text().isEmpty());
}

void ItemDialog::onAddItemClicked() {
    QString name = itemNameEdit->text();
    QString type = itemTypeBox->currentText().startsWith("B") ? "B" : "M";

    ItemRepository::instance().addItem(Item(name, type));
    BackupManager::backup();

    itemNameEdit->clear();
    itemNameEdit->setFocus();
    addItemButton->setEnabled(false);
}
