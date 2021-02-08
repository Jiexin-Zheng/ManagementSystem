#ifndef CONFIRMDIALOGMAINTAIN_H
#define CONFIRMDIALOGMAINTAIN_H

#include <QDialog>
#include"dialog/maintaineditdialog.h"

namespace Ui {
class ConfirmDialogMaintain;
}

class ConfirmDialogMaintain : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialogMaintain(QWidget *parent,MaintainEditDialog* mainwindow);
    ~ConfirmDialogMaintain();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ConfirmDialogMaintain *ui;
    MaintainEditDialog* mainwindow;
};

#endif // CONFIRMDIALOGMAINTAIN_H
