#include "equipmentshowdialog.h"
#include "ui_equipmentshowdialog.h"
#include "sql/sqldao.h"
#include <QMessageBox>
#include <QDebug>
#include"dialog/equipmenteditdialog.h"

EquipmentShowDialog::EquipmentShowDialog(QWidget* mainWidget,QWidget *parent,User& user) :
    QDialog(parent),
    ui(new Ui::EquipmentShowDialog),
    mainWidget(mainWidget),
    eed(new EquipmentEditDialog(this,0,user)),
    user(user)
{
    ui->setupUi(this);
}

EquipmentShowDialog::~EquipmentShowDialog()
{
    delete ui;
}

void EquipmentShowDialog::on_sortByMatchIdButton_clicked()
{
//    ui->setupUi(this);
    int rowTmp = ui->tableWidget->rowCount();
    for(int row = 0;row < rowTmp;row++)
    {
        ui->tableWidget->removeRow(0);
    }
    this->setWindowTitle("机电设备信息");
//    ui->tableWidget->clear();

    SqlDao sd;
    QVector<Equipment> equipments = sd.sortAllEquipmentByMatchId();
    ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"设备名称"<<"设备类别"<<"设备品牌"<<"设备编号"<<"设备编码"<<"设备规格"<<"设备来源"<<"设备状态"<<"开始使用日期"<<"保修期限"<<"说明"<<"设备型号"<<"区号");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
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

void EquipmentShowDialog::on_sortByNameButton_clicked()
{
    //    ui->setupUi(this);
        int rowTmp = ui->tableWidget->rowCount();
        for(int row = 0;row < rowTmp;row++)
        {
            ui->tableWidget->removeRow(0);
        }
        this->setWindowTitle("机电设备信息");
    //    ui->tableWidget->clear();

        SqlDao sd;
        QVector<Equipment> equipments = sd.sortAllEquipmentByName();
        ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"设备名称"<<"设备类别"<<"设备品牌"<<"设备编号"<<"设备编码"<<"设备规格"<<"设备来源"<<"设备状态"<<"开始使用日期"<<"保修期限"<<"说明"<<"设备型号"<<"区号");
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
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

void EquipmentShowDialog::on_sortByAreaButton_clicked()
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
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
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

void EquipmentShowDialog::on_editButton_clicked()
{
    eed->show();
    this->hide();
}

void EquipmentShowDialog::on_nameButton_clicked()
{
    QString name = ui->namelineEdit->text();
    int rowTmp = ui->tableWidget->rowCount();
    for(int row = 0;row < rowTmp;row++)
    {
        ui->tableWidget->removeRow(0);
    }
    this->setWindowTitle("机电设备信息");

    SqlDao sd;
    QVector<Equipment> equipments = sd.searchEquipmentByName(name);
    ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"设备名称"<<"设备类别"<<"设备品牌"<<"设备编号"<<"设备编码"<<"设备规格"<<"设备来源"<<"设备状态"<<"开始使用日期"<<"保修期限"<<"说明"<<"设备型号"<<"区号");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
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

    ui->namelineEdit->clear();
}

void EquipmentShowDialog::on_matchIdButton_clicked()
{
    QString matchid = ui->matchIdlineEdit->text();
    int rowTmp = ui->tableWidget->rowCount();
    int ret = 0;
    for(int row = 0;row < rowTmp;row++)
    {
        ui->tableWidget->removeRow(0);
    }
    this->setWindowTitle("机电设备信息");

    SqlDao sd;
    Equipment equipment = sd.searchEquipmentByMatchId(matchid,ret);
    ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"设备名称"<<"设备类别"<<"设备品牌"<<"设备编号"<<"设备编码"<<"设备规格"<<"设备来源"<<"设备状态"<<"开始使用日期"<<"保修期限"<<"说明"<<"设备型号"<<"区号");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
    int RowCont = 0;

    ui->tableWidget->insertRow(RowCont);//增加一行
    ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(equipment.getName()));
    ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(equipment.getCategory()));
    ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(equipment.getBrand()));
    ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(equipment.getMatchId()));
    ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(equipment.getCode()));
    ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(equipment.getSpecification()));
    ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(equipment.getSource()));
    ui->tableWidget->setItem(RowCont,7,new QTableWidgetItem(equipment.getState()));
    ui->tableWidget->setItem(RowCont,8,new QTableWidgetItem(equipment.getStarttime()));
    ui->tableWidget->setItem(RowCont,9,new QTableWidgetItem(equipment.getLimittime()));
    ui->tableWidget->setItem(RowCont,10,new QTableWidgetItem(equipment.getNote()));
    ui->tableWidget->setItem(RowCont,11,new QTableWidgetItem(equipment.getModelNumber()));
    ui->tableWidget->setItem(RowCont,12,new QTableWidgetItem(equipment.getAreaId()));

    ui->matchIdlineEdit->clear();
}

void EquipmentShowDialog::on_areaButton_clicked()
{
    QString area = ui->arealineEdit->text();
    int rowTmp = ui->tableWidget->rowCount();
    for(int row = 0;row < rowTmp;row++)
    {
        qDebug()<<"rowtmp:  "<<rowTmp;
        ui->tableWidget->removeRow(0);
    }
    this->setWindowTitle("机电设备信息");

    SqlDao sd;
    QVector<Equipment> equipments = sd.searchEquipmentByArea(area);
    ui->tableWidget->setColumnCount(13);//只设置列数，行数动态中增加
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"设备名称"<<"设备类别"<<"设备品牌"<<"设备编号"<<"设备编码"<<"设备规格"<<"设备来源"<<"设备状态"<<"开始使用日期"<<"保修期限"<<"说明"<<"设备型号"<<"区号");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个
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

    ui->arealineEdit->clear();
}
