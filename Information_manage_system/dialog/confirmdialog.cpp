#include "confirmdialog.h"
#include "ui_confirmdialog.h"
#include "equipmenteditdialog.h"
#include "ui_equipmenteditdialog.h"
#include"sql/sqldao.h"
#include <QMessageBox>
#include<QDebug>
extern User gUser;
ConfirmDialog::ConfirmDialog(QWidget *parent,EquipmentEditDialog* mainwindow) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog),
    mainwindow(mainwindow)
{
    ui->setupUi(this);
    QObject::connect(ui->confirmButton,SIGNAL(clicked()),mainwindow,SLOT(initialise()));
    QObject::connect(ui->confirmButton,SIGNAL(clicked()),mainwindow,SLOT(initialise()));
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}

void ConfirmDialog::on_confirmButton_clicked()
{
    QList<QTableWidgetItem*> items = mainwindow->getUi()->tableWidget->selectedItems();
    int count = items.count();
    Equipment equipment,equipment1;
    QTableWidgetItem *item;
    qDebug()<<"count: "<<count;
 //   int* searchRet = nullptr;
    int searchRet = 0;
    SqlDao sd;
    QString matchid = "";
    QString text = "";
    int i;
    qDebug()<<"editFlag: "<<mainwindow->getEditFlag();
    switch(mainwindow->getEditFlag()){
        case FLAG_ADD:
        for(i = 0; i < count; i++)
        {
            item = items.at(i);
            text = item->text(); //获取内容
            qDebug()<<"TEXT: "<<item->text();
            qDebug()<<"item column: "<<item->column();
            switch(item->column()){
                case 0:
                equipment.setName(text);
                break;
                case 1:
                equipment.setCategory(text);
                break;
                case 2:
                equipment.setBrand(text);
                break;
                case 3:
                equipment.setMatchId(text);
                break;
                case 4:
                equipment.setCode(text);
                break;
                case 5:
                equipment.setSpecification(text);
                break;
                case 6:
                equipment.setSource(text);
                break;
                case 7:
                equipment.setState(text);
                break;
                case 8:
                equipment.setStarttime(text);
                break;
                case 9:
                equipment.setLimittime(text);
                break;
                case 10:
                equipment.setNote(text);
                break;
                case 11:
                equipment.setModeNumber(text);
                break;
                case 12:
                equipment.setAreaId(text);
            }

                    matchid = mainwindow->getUi()->tableWidget->item(0,3)->text();
                            qDebug()<<"111  ";
                    qDebug()<<"area:  "<<gUser.getAreaId();
                    equipment1 = sd.searchEquipmentByMatchId(matchid,searchRet);
                    if((mainwindow->getUi()->tableWidget->item(0,12)->text()) != gUser.getAreaId() && gUser.getUsername()!="admin")
                    {
                        QMessageBox::warning(this,"警告","你所进行的操作不在你的区域权限范围内！");
                    }else{
                        if(searchRet){
                            QMessageBox::warning(this,"错误","你所增加的机电设备已经存在！");
                        }else{
                            sd.insertEquipment(equipment);
                        }
                    }

        }


        //free(searchRet);
        break;


        case FLAG_MODIFY:
        for(i = 0; i < count; i++)
        {
    //        int column = ui->tableWidget->column(items.at(i));
            item = items.at(i);
            text = item->text(); //获取内容
            qDebug()<<"TEXT: "<<item->text();
            qDebug()<<"item column: "<<item->column();
            matchid = mainwindow->getUi()->tableWidget->item(item->row(),3)->text();
            equipment = sd.searchEquipmentByMatchId(matchid,searchRet);
            //free(searchRet);
            switch(item->column()){
                case 0:
                equipment.setName(text);
                sd.updateEquipment(equipment);
                break;
                case 1:
                equipment.setCategory(text);
                qDebug()<<"category: "<<equipment.getCategory();
                sd.updateEquipment(equipment);
                break;
                case 2:
                equipment.setBrand(text);
                sd.updateEquipment(equipment);
                break;
                case 3:
                equipment.setMatchId(text);
                sd.updateEquipment(equipment);
                break;
                case 4:
                equipment.setCode(text);
                sd.updateEquipment(equipment);
                break;
                case 5:
                equipment.setSpecification(text);
                sd.updateEquipment(equipment);
                break;
                case 6:
                equipment.setSource(text);
                sd.updateEquipment(equipment);
                break;
                case 7:
                equipment.setState(text);
                sd.updateEquipment(equipment);
                break;
                case 8:
                equipment.setStarttime(text);
                sd.updateEquipment(equipment);
                break;
                case 9:
                equipment.setLimittime(text);
                sd.updateEquipment(equipment);
                break;
                case 10:
                equipment.setNote(text);
                sd.updateEquipment(equipment);
                break;
                case 11:
                equipment.setModeNumber(text);
                sd.updateEquipment(equipment);
                break;
                case 12:
                equipment.setAreaId(text);
                break;
            }
            qDebug()<<"area:  "<<gUser.getAreaId();
            if((mainwindow->getUi()->tableWidget->item(item->row(),12)->text())!=gUser.getAreaId() && gUser.getUsername()!="admin"){
                //no priviledge
               QMessageBox::warning(this,"警告","你所进行的操作不在你的区域权限范围内！");
               mainwindow->setEditFlag(0);
               //close?
               mainwindow->getUi()->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
               this->close();
            }else{
               sd.updateEquipment(equipment);
            }

        }
        break;



        case FLAG_REMOVE:
        for(i = 0; i < count; i++)
        {
            item = items.at(i);
            text = item->text(); //获取内容
            qDebug()<<"TEXT: "<<item->text();
            qDebug()<<"item column: "<<item->column();
            matchid = mainwindow->getUi()->tableWidget->item(item->row(),3)->text();
            equipment = sd.searchEquipmentByMatchId(matchid,searchRet);
            if(equipment.getAreaId() != gUser.getAreaId() && gUser.getUsername()!="admin"){
                QMessageBox::warning(this,"警告","你所进行的操作不在你的区域权限范围内！");
                this->close();
                mainwindow->setEditFlag(0);
                mainwindow->getUi()->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            }
            if(searchRet) sd.deleteEquipment(equipment);
        }
        break;

    }
    mainwindow->setEditFlag(0);
    mainwindow->getUi()->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->close();
}

void ConfirmDialog::on_cancelButton_clicked()
{
    mainwindow->setEditFlag(0);
    mainwindow->getUi()->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->close();
}
