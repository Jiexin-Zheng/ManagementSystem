#ifndef EQUIPMENTEDITDIALOG_H
#define EQUIPMENTEDITDIALOG_H

#include <QWidget>
#include <QCloseEvent>
#include <QShowEvent>
#include"model/equipment.h"
#include"model/user.h"
//#include"dialog/confirmdialog.h"
class ConfirmDialog;//类的前置声明解决头文件相互包含
#define FLAG_REMOVE 1
#define FLAG_ADD 2
#define FLAG_MODIFY 3

namespace Ui {
class EquipmentEditDialog;
}

class EquipmentEditDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EquipmentEditDialog(QWidget* mainwindow,QWidget *parent,User& user);
    ~EquipmentEditDialog();

protected:
    virtual void closeEvent(QCloseEvent* event);
    virtual void showEvent(QShowEvent *event);

private slots:
    void on_modifyButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

    void initialise();

private:
    Ui::EquipmentEditDialog *ui;
    QWidget* mainwindow;
    int editFlag;
    User& user;
    ConfirmDialog* cd;
public:
    User getUser();
    void setUser(const User& value);
    int getEditFlag();
    void setEditFlag(const int& value);
    Ui::EquipmentEditDialog* getUi();
};

#endif // EQUIPMENTEDITDIALOG_H
