#include "userwidget.h"
#include "ui_userwidget.h"
#include "sql/sqldao.h"
#include <QMessageBox>
extern User gUser;

UserWidget::UserWidget(QWidget* mainWidget, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidget),
    mainWidget(mainWidget),
    maintains(new MaintainShowDialog(this,0,user)),
    esd(new EquipmentShowDialog(this,0,user)),
    mpd(new ModifyPwdDialog(this))
{
    ui->setupUi(this);
}

UserWidget::~UserWidget()
{
    delete ui;
}

User UserWidget::getUser() const
{
    return user;
}

void UserWidget::setUser(const User &value)
{
    user = value;
}

void UserWidget::closeEvent(QCloseEvent *event)
{
    /*1.改变在线状态*/
    SqlDao sd;
    sd.updateUserOnline(user.getUsername(), false);
    gUser.setOnline(false);
    /*2.界面切换*/
    mainWidget->show();
    this->hide();

    event->ignore();
}

void UserWidget::showEvent(QShowEvent *event)
{
//    this->refleshUser();

    event->accept();
}

void UserWidget::on_modifyButton_clicked()
{
    mpd->show();
}

void UserWidget::on_equipmentButton_clicked()
{
    esd->show();
}

void UserWidget::on_maintainButton_clicked()
{
     maintains->show();
}
