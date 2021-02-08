#ifndef MAINTAINSHOWDIALOG_H
#define MAINTAINSHOWDIALOG_H

#include <QDialog>
#include"model/user.h"
#include"dialog/maintaineditdialog.h"

namespace Ui {
class MaintainShowDialog;
}

class MaintainShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MaintainShowDialog(QWidget* mainWidget,QWidget *parent ,User& user);
    ~MaintainShowDialog();

private slots:
    void on_idButton_clicked();

    void on_matchIdButton_clicked();

    void on_editButton_clicked();

    void on_sortByTimeButton_clicked();

    void on_sortByMatchIdButton_clicked();

private:
    Ui::MaintainShowDialog *ui;
    QWidget* mainWidget;
    MaintainEditDialog* eed;
    User& user;
};

#endif // MAINTAINSHOWDIALOG_H
