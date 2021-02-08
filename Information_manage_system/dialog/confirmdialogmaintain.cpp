#include "confirmdialogmaintain.h"
#include "ui_confirmdialogmaintain.h"
#include"maintaineditdialog.h"
#include "ui_maintaineditdialog.h"
#include<QDebug>
#include<QMessageBox>
#include"sql/sqldao.h"
extern User gUser;

ConfirmDialogMaintain::ConfirmDialogMaintain(QWidget *parent,MaintainEditDialog* mainwindow) :
    QDialog(parent),
    ui(new Ui::ConfirmDialogMaintain),
    mainwindow(mainwindow)
{
    ui->setupUi(this);
    QObject::connect(ui->confirmButton,SIGNAL(clicked()),mainwindow,SLOT(initialise()));
    QObject::connect(ui->confirmButton,SIGNAL(clicked()),mainwindow,SLOT(initialise()));
}

ConfirmDialogMaintain::~ConfirmDialogMaintain()
{
    delete ui;
}

void ConfirmDialogMaintain::on_confirmButton_clicked()
{
    QList<QTableWidgetItem*> items = mainwindow->getUi()->tableWidget->selectedItems();
    int count = items.count();
    Maintain maintain,maintain1;
    QTableWidgetItem *item;
    qDebug()<<"count: "<<count;
 //   int* searchRet = nullptr;
    int searchRet = 0;
    SqlDao sd;
    QString id = "";
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
                maintain.setId(text);
                break;
                case 1:
                maintain.setMatchId(text);
                break;
                case 2:
                maintain.setDate(text);
                break;
                case 3:
                maintain.setMaintainer(text);
                break;
                case 4:
                maintain.setState(text);
                break;
                case 5:
                maintain.setProblem(text);
                break;
                case 6:
                maintain.setDetails(text);
                break;
                case 7:
                maintain.setFaultLevel(text.toInt());
                break;
            }


                    maintain1 = sd.searchMaintainById(id,searchRet);

                        if(searchRet){
                            QMessageBox::warning(this,"错误","你所增加的养护信息已经存在！");
                        }else{
                            sd.insertMaintain(maintain);
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
            id = mainwindow->getUi()->tableWidget->item(item->row(),3)->text();
            maintain = sd.searchMaintainById(id,searchRet);
            //free(searchRet);
            switch(item->column()){
            case 0:
            maintain.setId(text);
            break;
            case 1:
            maintain.setMatchId(text);
            break;
            case 2:
            maintain.setDate(text);
            break;
            case 3:
            maintain.setMaintainer(text);
            break;
            case 4:
            maintain.setState(text);
            break;
            case 5:
            maintain.setProblem(text);
            break;
            case 6:
            maintain.setDetails(text);
            break;
            case 7:
            maintain.setFaultLevel(text.toInt());
            break;
            }
            qDebug()<<"area:  "<<gUser.getAreaId();

               sd.updateMaintain(maintain);


        }
        break;



        case FLAG_REMOVE:
        for(i = 0; i < count; i++)
        {
            item = items.at(i);
            text = item->text(); //获取内容
            qDebug()<<"TEXT: "<<item->text();
            qDebug()<<"item column: "<<item->column();
            id = mainwindow->getUi()->tableWidget->item(item->row(),3)->text();
            maintain = sd.searchMaintainById(id,searchRet);

            if(searchRet) sd.deleteMaintain(maintain);
        }
        break;

    }
    mainwindow->setEditFlag(0);
    mainwindow->getUi()->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->close();
}

void ConfirmDialogMaintain::on_cancelButton_clicked()
{
    mainwindow->setEditFlag(0);
    mainwindow->getUi()->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->close();
}
