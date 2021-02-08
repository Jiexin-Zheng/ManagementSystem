#ifndef MAINTAINEDITDIALOG_H
#define MAINTAINEDITDIALOG_H

#include <QWidget>
#include"model/user.h"
#include <QCloseEvent>
#include <QShowEvent>

class ConfirmDialogMaintain;
#define FLAG_REMOVE 1
#define FLAG_ADD 2
#define FLAG_MODIFY 3

namespace Ui {
class MaintainEditDialog;
}

class MaintainEditDialog : public QWidget
{
    Q_OBJECT

public:
    explicit MaintainEditDialog(QWidget* mainwindow,QWidget *parent,User& user);
    ~MaintainEditDialog();

private:
    Ui::MaintainEditDialog *ui;
    QWidget* mainwindow;
    int editFlag;
    User& user;
    ConfirmDialogMaintain* cd;

public:
    User getUser();
    void setUser(const User& value);
    int getEditFlag();
    void setEditFlag(const int& value);
    Ui::MaintainEditDialog* getUi();

protected:
    virtual void closeEvent(QCloseEvent* event);
    virtual void showEvent(QShowEvent *event);
private slots:
    void on_confirmButton_clicked();
    void on_cancelButton_clicked();
    void on_modifyButton_clicked();
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void initialise();
};

#endif // MAINTAINEDITDIALOG_H
