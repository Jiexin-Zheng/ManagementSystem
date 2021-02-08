#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>
#include"dialog/equipmenteditdialog.h"


namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QWidget *parent,EquipmentEditDialog* mainwindow);
    ~ConfirmDialog();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ConfirmDialog *ui;
    EquipmentEditDialog* mainwindow;

};

#endif // CONFIRMDIALOG_H
