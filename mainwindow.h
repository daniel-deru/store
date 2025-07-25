#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTreeView;
class QStandardItemModel;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void showItemDialog();
    void showTransactionDialog();
    void showCustomerDialog();
    void restoreBackup();
    void broadcastXml();
    void populateTreeView();
    void showHelpDialog();
    void showAboutDialog();
    void showStatus(const QString message, int durationMs = 3000);

private:
    QTreeView *treeView;
    QStandardItemModel *model;

    void setupMenusAndToolbar();


};

#endif // MAINWINDOW_H
