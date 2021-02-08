#include "modifypwddialog.h"
#include "ui_modifypwddialog.h"
#include<QMessageBox>
#include"sql/sqldao.h"
#include<QDebug>
extern User gUser;

ModifyPwdDialog::ModifyPwdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyPwdDialog)
{
    ui->setupUi(this);
}

ModifyPwdDialog::~ModifyPwdDialog()
{
    delete ui;
}

void ModifyPwdDialog::on_confirmButton_clicked()
{
    QString userpwd = ui->pwdlineEdit->text();
    QString userpwdAg = ui->pwdagainlineEdit->text();
    SqlDao sd;
    bool ret = false;
    ret = (userpwd == userpwdAg);
    if(!ret){
        QMessageBox::warning(this,"修改失败","密码不一致");
    }else{
        qDebug()<<gUser.getUsername();
        sd.updateUesrpwd(gUser.getUsername(),userpwd);
        QMessageBox::information(this,"修改密码","修改成功");
    }
    on_cancelButton_clicked();
}

void ModifyPwdDialog::on_cancelButton_clicked()
{
    ui->pwdlineEdit->clear();
    ui->pwdagainlineEdit->clear();
    this->hide();
}
