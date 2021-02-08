#include "adminwidget.h"
#include "ui_adminwidget.h"
#include "sql/sqldao.h"
#include <QMessageBox>
#include <QDebug>

AdminWidget::AdminWidget(QWidget* mainwindow,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWidget),
    mainwindow(mainwindow),
    maintains(new MaintainShowDialog(this,0,user)),
    equipments(new EquipmentShowDialog(this,0,user))
{
    ui->setupUi(this);
}

AdminWidget::~AdminWidget()
{
    delete ui;
}

User AdminWidget::getUser() const
{
    return user;
}

void AdminWidget::setUser(const User &value)
{
    user = value;
}

void AdminWidget::closeEvent(QCloseEvent *event)
{
    mainwindow->show();
    this->hide();

    event->ignore();
}

void AdminWidget::on_equipmentButton_clicked()
{
    equipments->show();
}

void AdminWidget::on_maintainButton_clicked()
{
    maintains->show();
}
