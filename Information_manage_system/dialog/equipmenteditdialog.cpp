#include "equipmenteditdialog.h"
#include "ui_equipmenteditdialog.h"
#include"sql/sqldao.h"
#include <QMessageBox>
#include"dialog/confirmdialog.h"

EquipmentEditDialog::EquipmentEditDialog(QWidget* mainwindow,QWidget *parent,User& user) :
    QWidget(parent),
    ui(new Ui::EquipmentEditDialog),
    mainwindow(mainwindow),
    editFlag(0),
    user(user),
    cd(new ConfirmDialog(0,this))
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);//可以选中多个
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        int rowTmp = ui->tableWidget->rowCount();
        for(int row = 0;row < rowTmp;row++)
        {
            ui->tableWidget->removeRow(0);
        }
        this->setWindowTitle("机电设备信息");

        SqlDao sd;
        QVector<Equipment> equipments = sd.sortAllEquipmentByArea();
        ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"设备名称"<<"设备类别"<<"设备品牌"<<"设备编号"<<"设备编码"<<"设备规格"<<"设备来源"<<"设备状态"<<"开始使用日期"<<"保修期限"<<"说明"<<"设备型号"<<"区号");
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
        int RowCont = 0;
        QVector<Equipment>::iterator it;
        it = equipments.begin();
        do{
            ui->tableWidget->insertRow(RowCont);//增加一行
            ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(it->getName()));
            ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(it->getCategory()));
            ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(it->getBrand()));
            ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(it->getMatchId()));
            ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(it->getCode()));
            ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(it->getSpecification()));
            ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(it->getSource()));
            ui->tableWidget->setItem(RowCont,7,new QTableWidgetItem(it->getState()));
            ui->tableWidget->setItem(RowCont,8,new QTableWidgetItem(it->getStarttime()));
            ui->tableWidget->setItem(RowCont,9,new QTableWidgetItem(it->getLimittime()));
            ui->tableWidget->setItem(RowCont,10,new QTableWidgetItem(it->getNote()));
            ui->tableWidget->setItem(RowCont,11,new QTableWidgetItem(it->getModelNumber()));
            ui->tableWidget->setItem(RowCont,12,new QTableWidgetItem(it->getAreaId()));
            ++it;
            RowCont++;
        }while(it != equipments.end());
}

EquipmentEditDialog::~EquipmentEditDialog()
{
    delete ui;
}

User EquipmentEditDialog::getUser()
{
    return user;
}

void EquipmentEditDialog::setUser(const User& value)
{
    user = value;
}

int EquipmentEditDialog::getEditFlag()
{
    return editFlag;
}

void EquipmentEditDialog::setEditFlag(const int& value)
{
    editFlag = value;
}

Ui::EquipmentEditDialog* EquipmentEditDialog::getUi()
{
    return ui;
}

void EquipmentEditDialog::closeEvent(QCloseEvent *event)
{
    mainwindow->show();
    this->hide();
    event->ignore();
}

void EquipmentEditDialog::showEvent(QShowEvent *event)
{
    event->accept();
}

void EquipmentEditDialog::on_modifyButton_clicked()
{
    editFlag = FLAG_MODIFY;
    //enable all items
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void EquipmentEditDialog::on_addButton_clicked()
{
    editFlag = FLAG_ADD;
    //unable all items
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void EquipmentEditDialog::on_removeButton_clicked()
{
    editFlag = FLAG_REMOVE;
    //unable all items
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void EquipmentEditDialog::on_confirmButton_clicked()
{
    cd->show();
//    this->hide();
}

void EquipmentEditDialog::on_cancelButton_clicked()
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->hide();
}

void EquipmentEditDialog::initialise()
{
    int rowTmp = ui->tableWidget->rowCount();
    for(int row = 0;row < rowTmp;row++)
    {
        ui->tableWidget->removeRow(0);
    }
    this->setWindowTitle("机电设备信息");

    SqlDao sd;
    QVector<Equipment> equipments = sd.sortAllEquipmentByArea();
    ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"设备名称"<<"设备类别"<<"设备品牌"<<"设备编号"<<"设备编码"<<"设备规格"<<"设备来源"<<"设备状态"<<"开始使用日期"<<"保修期限"<<"说明"<<"设备型号"<<"区号");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    int RowCont = 0;
    QVector<Equipment>::iterator it;
    it = equipments.begin();
    do{
        ui->tableWidget->insertRow(RowCont);//增加一行
        ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(it->getName()));
        ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(it->getCategory()));
        ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(it->getBrand()));
        ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(it->getMatchId()));
        ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(it->getCode()));
        ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(it->getSpecification()));
        ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(it->getSource()));
        ui->tableWidget->setItem(RowCont,7,new QTableWidgetItem(it->getState()));
        ui->tableWidget->setItem(RowCont,8,new QTableWidgetItem(it->getStarttime()));
        ui->tableWidget->setItem(RowCont,9,new QTableWidgetItem(it->getLimittime()));
        ui->tableWidget->setItem(RowCont,10,new QTableWidgetItem(it->getNote()));
        ui->tableWidget->setItem(RowCont,11,new QTableWidgetItem(it->getModelNumber()));
        ui->tableWidget->setItem(RowCont,12,new QTableWidgetItem(it->getAreaId()));
        ++it;
        RowCont++;
    }while(it != equipments.end());

}
