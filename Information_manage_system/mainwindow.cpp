#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sql/sqldao.h"
#include <QMessageBox>
extern User gUser;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      rd(new RegisterDialog(this)),
      uw(new UserWidget(this)),
      aw(new AdminWidget(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    SqlDao sd;
    QVector<User> users = sd.sortAllUserByName();
    QVector<User>::iterator it;
    for(it = users.begin();it != users.end();++it){
        sd.updateUserOnline(it->getUsername(),false);
    }
    delete ui;
    delete rd;
    delete uw;
    delete aw;
}

void MainWindow::on_loginInButton_clicked()
{
    QString username = ui->userNameLineEdit->text();
    QString userpwd = ui->pwdLineEdit->text();
    SqlDao sd;
    gUser.setUsername(username);
    gUser.setUserpwd(userpwd);
    sd.searchUserByUsername(gUser);
    User user_tmp;
    if(username == "admin" && userpwd == "admin"){
        //管理员
        QMessageBox::information(this,"登录信息","登录成功");
        sd.updateUserOnline(username,true);

        aw->setUser(User(user_tmp));
        aw->show();
        this->hide();

        return;
    }

    /*1.判断是否注册*/
    do{
        SqlDao sd;
        bool ret = sd.searchUserByUsername(username);
        if(!ret){
            QMessageBox::warning(this,"登录信息","登录失败，账号或密码错误");
            break;
        }

        ret = sd.searchUserByOnline(username, false);
        if(!ret){
            QMessageBox::warning(this,"登录信息","登录失败，重复登录");
            break;
        }

        ret = sd.searchUserByUserpwd(username, userpwd);
        if(!ret){
            QMessageBox::warning(this,"登录信息","登录失败，账号或密码错误");
            break;
        }else{
            //改变在线状态
            sd.updateUserOnline(username,true);
            QMessageBox::information(this,"登录信息","登录成功");

            //切换界面
            gUser.setUsername(username);
            gUser.setUserpwd(userpwd);
            sd.updateUserOnline(username,true);
            sd.searchUserByUsername(user_tmp);
            uw->setUser(User(user_tmp));
            aw->setUser(User(user_tmp));
            uw->show();
            this->hide();
        }
    }while(0);

    ui->userNameLineEdit->clear();
    ui->pwdLineEdit->clear();
}

void MainWindow::on_registerButton_clicked()
{
    rd->show();
}
