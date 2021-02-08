#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include "model/user.h"
#include <QCloseEvent>
#include <QShowEvent>
#include"dialog/equipmentshowdialog.h"
#include"dialog/modifypwddialog.h"
#include"dialog/maintainshowdialog.h"

namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidget(QWidget* mainWidget, QWidget *parent = nullptr);
    ~UserWidget();

    User getUser() const;
    void setUser(const User &value);
private:
    Ui::UserWidget *ui;
    QWidget* mainWidget;
    User user;
    EquipmentShowDialog *esd;
    MaintainShowDialog* maintains;
    ModifyPwdDialog* mpd;
protected:
    virtual void closeEvent(QCloseEvent* event);
    virtual void showEvent(QShowEvent *event);
private slots:
    void on_modifyButton_clicked();
    void on_equipmentButton_clicked();
    void on_maintainButton_clicked();
};

#endif // USERWIDGET_H
