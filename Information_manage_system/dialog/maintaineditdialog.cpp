#include "maintaineditdialog.h"
#include "ui_maintaineditdialog.h"
#include"sql/sqldao.h"
#include <QMessageBox>
#include"dialog/confirmdialogmaintain.h"

MaintainEditDialog::MaintainEditDialog(QWidget* mainwindow,QWidget *parent,User& user) :
    QWidget(parent),
    ui(new Ui::MaintainEditDialog),
    mainwindow(mainwindow),
    editFlag(0),
    user(user),
    cd(new ConfirmDialogMaintain(0,this))
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);//可以选中多个
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        int rowTmp = ui->tableWidget->rowCount();
        for(int row = 0;row < rowTmp;row++)
        {
            ui->tableWidget->removeRow(0);
        }
        this->setWindowTitle("养护信息");

        SqlDao sd;
        QVector<Maintain> maintains = sd.sortAllMaintainByTime();
        ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"编号"<<"设备编号"<<"时间"<<"维修人"<<"设备状态"<<"故障现象"<<"维修内容"<<"故障等级");
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
        int RowCont = 0;
        QVector<Maintain>::iterator it;
        it = maintains.begin();
        do{
            ui->tableWidget->insertRow(RowCont);//增加一行
            ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(it->getId()));
            ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(it->getMatchId()));
            ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(it->getDate()));
            ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(it->getMaintainer()));
            ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(it->getState()));
            ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(it->getProblem()));
            ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(it->getDetails()));
            ui->tableWidget->setItem(RowCont,7,new QTableWidgetItem(it->getFaultLevel()));
            ++it;
            RowCont++;
        }while(it != maintains.end());
}

MaintainEditDialog::~MaintainEditDialog()
{
    delete ui;
}

User MaintainEditDialog::getUser()
{
    return user;
}

void MaintainEditDialog::setUser(const User& value)
{
    user = value;
}

int MaintainEditDialog::getEditFlag()
{
    return editFlag;
}

void MaintainEditDialog::setEditFlag(const int& value)
{
    editFlag = value;
}

Ui::MaintainEditDialog* MaintainEditDialog::getUi()
{
    return ui;
}

void MaintainEditDialog::closeEvent(QCloseEvent *event)
{
    mainwindow->show();
    this->hide();
    event->ignore();
}

void MaintainEditDialog::showEvent(QShowEvent *event)
{
    event->accept();
}


void MaintainEditDialog::on_confirmButton_clicked()
{
    cd->show();
}

void MaintainEditDialog::on_cancelButton_clicked()
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->hide();
}

void MaintainEditDialog::on_modifyButton_clicked()
{
    editFlag = FLAG_MODIFY;
    //enable all items
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void MaintainEditDialog::on_addButton_clicked()
{
    editFlag = FLAG_ADD;
    //unable all items
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);


}

void MaintainEditDialog::on_removeButton_clicked()
{
    editFlag = FLAG_REMOVE;
    //unable all items
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void MaintainEditDialog::initialise()
{
    int rowTmp = ui->tableWidget->rowCount();
    for(int row = 0;row < rowTmp;row++)
    {
        ui->tableWidget->removeRow(0);
    }
    this->setWindowTitle("养护信息");

    SqlDao sd;
    QVector<Maintain> maintains = sd.sortAllMaintainByTime();
    ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"编号"<<"设备编号"<<"时间"<<"维修人"<<"设备状态"<<"故障现象"<<"维修内容"<<"故障等级");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    int RowCont = 0;
    QVector<Maintain>::iterator it;
    it = maintains.begin();
    do{
        ui->tableWidget->insertRow(RowCont);//增加一行
        ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(it->getId()));
        ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(it->getMatchId()));
        ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(it->getDate()));
        ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(it->getMaintainer()));
        ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(it->getState()));
        ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(it->getProblem()));
        ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(it->getDetails()));
        ui->tableWidget->setItem(RowCont,7,new QTableWidgetItem(it->getFaultLevel()));
        ++it;
        RowCont++;
    }while(it != maintains.end());

}
