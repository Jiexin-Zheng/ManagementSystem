#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog/registerdialog.h"
#include "widget/userwidget.h"
#include "widget/adminwidget.h"
#include <QCloseEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginInButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::MainWindow *ui;
    RegisterDialog* rd;

    UserWidget* uw;
    AdminWidget* aw;
};
#endif // MAINWINDOW_H
