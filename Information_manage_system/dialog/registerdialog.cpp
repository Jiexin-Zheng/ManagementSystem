#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "sql/sqldao.h"
#include <QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_confirmButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString userpwd = ui->pwdLineEdit->text();
    QString userpwdAg = ui->pwdAgainLineEdit->text();
    QString areaId = ui->areaIdLineEdit->text();

    if(username == "admin"){
        //管理员
        QMessageBox::warning(this,"注册信息","注册失败，重复注册");
        return;
    }

    /*1.判断是否可以注册*/
    do{
        SqlDao sd;
        bool ret = sd.searchUserByUsername(username);
        if(ret){
            //有了，不能重复注册
            QMessageBox::warning(this,"注册信息","注册失败，重复注册");
            break;
        }

        ret = (userpwd == userpwdAg);
        if(!ret){
            QMessageBox::warning(this,"注册信息","注册失败，密码不一致");
        }else{
            sd.insertUser(User(username,userpwd,false,areaId));
            QMessageBox::information(this,"注册信息","注册成功");
        }
    }while(0);

    on_cancelButton_clicked();
}

void RegisterDialog::on_cancelButton_clicked()
{
    ui->usernameLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->pwdAgainLineEdit->clear();

    this->hide();
}
