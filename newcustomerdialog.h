#ifndef NEWCUSTOMERDIALOG_H
#define NEWCUSTOMERDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;
class QWidget;


class NewCustomerDialog : public QDialog {
    Q_OBJECT

public:
    explicit NewCustomerDialog(QWidget *parent = nullptr);

signals:
    void customerAdded(const QString &name);

private slots:
    void onInputChanged();
    void onAddCustomerClicked();

private:
    QLineEdit *nameEdit;
    QPushButton *addButton;

    void setupUi();
};

#endif // NEWCUSTOMERDIALOG_H
