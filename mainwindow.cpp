#include "MainWindow.h"
#include "ItemDialog.h"
#include "TransactionDialog.h"
#include "StoreDataModel.h"
#include "itemrepository.h"
#include "UdpBroadcaster.h"
#include "BackupManager.h"
#include "Customer.h"
#include "newcustomerdialog.h"

#include <QTreeView>
#include <QStandardItemModel>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>
#include <QMessageBox>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    treeView(new QTreeView(this)),
    model(new QStandardItemModel(this))
{
    setWindowTitle("Shop");
    resize(800, 600);
    setupMenusAndToolbar();
    setCentralWidget(treeView);
    populateTreeView();
}

void MainWindow::setupMenusAndToolbar() {
    QIcon appIcon(":/icon/greenbag");
    setWindowIcon(appIcon);

    QMenu *fileMenu = menuBar()->addMenu("File");
    QAction *restoreAction = new QAction("Restore", this);
    connect(restoreAction, &QAction::triggered, this, &MainWindow::restoreBackup);
    fileMenu->addAction(restoreAction);

    QAction *broadcastAction = new QAction("Broadcast", this);
    connect(broadcastAction, &QAction::triggered, this, &MainWindow::broadcastXml);
    fileMenu->addAction(broadcastAction);

    QMenu *addMenu = menuBar()->addMenu("Add");
    QAction *addItemAction = new QAction("Item", this);
    QAction *addTransactionAction = new QAction("Transaction", this);
    QAction *addCustomerAction = new QAction("Customer", this);
    connect(addItemAction, &QAction::triggered, this, &MainWindow::showItemDialog);
    connect(addTransactionAction, &QAction::triggered, this, &MainWindow::showTransactionDialog);
    connect(addCustomerAction, &QAction::triggered, this, &MainWindow::showCustomerDialog);
    addMenu->addAction(addItemAction);
    addMenu->addAction(addTransactionAction);
    addMenu->addAction(addCustomerAction);

    QToolBar *toolbar = addToolBar("Main Toolbar");
    toolbar->addAction(addItemAction);
    toolbar->addAction(addTransactionAction);
    toolbar->addAction(restoreAction);
    toolbar->addAction(broadcastAction);

    statusBar()->showMessage("Ready");
}

void MainWindow::showItemDialog() {

    ItemDialog *dialog = new ItemDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::showTransactionDialog() {

    const int items = ItemRepository::instance().getItems().length();

    if(items > 0)
    {
        TransactionDialog *dialog = new TransactionDialog(this);
        connect(dialog, &TransactionDialog::transactionCompleted, this, &MainWindow::populateTreeView);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
    else
    {
        QMessageBox::warning(
            this,
            "Warning",
            "Cannot create transaction since no items are in the store.\n"
            "Please add items to the store before proceeding with a transaction."
        );
    }

}

void MainWindow::showCustomerDialog()
{
    NewCustomerDialog * dialog = new NewCustomerDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::restoreBackup() {
    BackupManager::restore();
    populateTreeView();
    statusBar()->showMessage("Backup restored", 3000);
}

void MainWindow::broadcastXml() {
    QString xml = StoreDataModel::instance().toXml();
    UdpBroadcaster *broadcaster = new UdpBroadcaster(xml);
    broadcaster->start();
    statusBar()->showMessage("Broadcast sent", 3000);
}

void MainWindow::populateTreeView() {
    model->clear();
    model->setHorizontalHeaderLabels({"Transaction", "Type", "Quantity"});

    QList<Customer> customers = StoreDataModel::instance().getCustomers();
    for (const Customer &c : customers) {
        QStandardItem *customerItem = new QStandardItem(c.getName());

        for (const Transaction &t : c.getTransactions()) {
            QStandardItem *timestampItem = new QStandardItem(t.getTimestamp().toString("yyyy/MM/dd HH:mm"));

            for (const TransactionItem &ti : t.getItems()) {
                QList<QStandardItem *> row;
                row << new QStandardItem(ti.getName())
                    << new QStandardItem(ti.getType())
                    << new QStandardItem(QString::number(ti.getQuantity()));
                timestampItem->appendRow(row);
            }

            customerItem->appendRow(timestampItem);
        }

        model->appendRow(customerItem);
    }

    treeView->setModel(model);
    treeView->expandAll();
}
