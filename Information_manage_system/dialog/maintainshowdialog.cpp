#include "maintainshowdialog.h"
#include "ui_maintainshowdialog.h"
#include"sql/sqldao.h"
#include <QMessageBox>
#include <QDebug>

MaintainShowDialog::MaintainShowDialog(QWidget* mainWidget,QWidget *parent ,User& user) :
    QDialog(parent),
    ui(new Ui::MaintainShowDialog),
    mainWidget(mainWidget),
    eed(new MaintainEditDialog(this,0,user)),
    user(user)
{
    ui->setupUi(this);
}

MaintainShowDialog::~MaintainShowDialog()
{
    delete ui;
}

void MaintainShowDialog::on_idButton_clicked()
{
    QString id = ui->idlineEdit->text();
    int rowTmp = ui->tableWidget->rowCount();
    int ret = 0;
    for(int row = 0;row < rowTmp;row++)
    {
        ui->tableWidget->removeRow(0);
    }
    this->setWindowTitle("养护信息");

    SqlDao sd;
    Maintain maintain = sd.searchMaintainById(id,ret);
    ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"编号"<<"设备编号"<<"时间"<<"维修人"<<"设备状态"<<"故障现象"<<"维修内容"<<"故障等级");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
    int RowCont = 0;

    ui->tableWidget->insertRow(RowCont);//增加一行
    ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(maintain.getId()));
    ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(maintain.getMatchId()));
    ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(maintain.getDate()));
    ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(maintain.getMaintainer()));
    ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(maintain.getState()));
    ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(maintain.getProblem()));
    ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(maintain.getDetails()));
    ui->tableWidget->setItem(RowCont,7,new QTableWidgetItem(maintain.getFaultLevel()));

    ui->idlineEdit->clear();
}

void MaintainShowDialog::on_matchIdButton_clicked()
{
    QString matchid = ui->matchIdlineEdit->text();
    int rowTmp = ui->tableWidget->rowCount();
    for(int row = 0;row < rowTmp;row++)
    {
        ui->tableWidget->removeRow(0);
    }
    this->setWindowTitle("养护信息");

    SqlDao sd;
    QVector<Maintain> maintains = sd.searchMaintainByMatchId(matchid);
    ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"编号"<<"设备编号"<<"时间"<<"维修人"<<"设备状态"<<"故障现象"<<"维修内容"<<"故障等级");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
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

    ui->matchIdlineEdit->clear();
}

void MaintainShowDialog::on_editButton_clicked()
{
    eed->show();
    this->hide();
}

void MaintainShowDialog::on_sortByTimeButton_clicked()
{
    //    ui->setupUi(this);
        int rowTmp = ui->tableWidget->rowCount();
        for(int row = 0;row < rowTmp;row++)
        {
            ui->tableWidget->removeRow(0);
        }
        this->setWindowTitle("养护信息");
    //    ui->tableWidget->clear();

        SqlDao sd;
        QVector<Maintain> maintains = sd.sortAllMaintainByTime();
        ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"编号"<<"设备编号"<<"时间"<<"维修人"<<"设备状态"<<"故障现象"<<"维修内容"<<"故障等级");
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
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

void MaintainShowDialog::on_sortByMatchIdButton_clicked()
{
    //    ui->setupUi(this);
        int rowTmp = ui->tableWidget->rowCount();
        for(int row = 0;row < rowTmp;row++)
        {
            ui->tableWidget->removeRow(0);
        }
        this->setWindowTitle("养护信息");
    //    ui->tableWidget->clear();

        SqlDao sd;
        QVector<Maintain> maintains = sd.sortAllMaintainByMatchId();
        ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"编号"<<"设备编号"<<"时间"<<"维修人"<<"设备状态"<<"故障现象"<<"维修内容"<<"故障等级");
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
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
