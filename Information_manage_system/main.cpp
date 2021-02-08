#include "mainwindow.h"
#include"model/user.h"
#include <QApplication>

User gUser;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
