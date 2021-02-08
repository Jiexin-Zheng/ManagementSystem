/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *registerButton;
    QPushButton *loginInButton;
    QPushButton *findBackButton;
    QLineEdit *pwdLineEdit;
    QLineEdit *userNameLineEdit;
    QLabel *userNameLabel;
    QLabel *pwdLabel;
    QLabel *findBackLabel;
    QLabel *welcomeLabel;
    QCommandLinkButton *commandLinkButton;
    QCalendarWidget *calendarWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(820, 604);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(180, 400, 75, 23));
        loginInButton = new QPushButton(centralwidget);
        loginInButton->setObjectName(QStringLiteral("loginInButton"));
        loginInButton->setGeometry(QRect(380, 400, 75, 23));
        findBackButton = new QPushButton(centralwidget);
        findBackButton->setObjectName(QStringLiteral("findBackButton"));
        findBackButton->setGeometry(QRect(640, 400, 75, 23));
        pwdLineEdit = new QLineEdit(centralwidget);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(340, 300, 113, 20));
        pwdLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 127);"));
        userNameLineEdit = new QLineEdit(centralwidget);
        userNameLineEdit->setObjectName(QStringLiteral("userNameLineEdit"));
        userNameLineEdit->setGeometry(QRect(340, 240, 113, 20));
        userNameLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 127);"));
        userNameLabel = new QLabel(centralwidget);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));
        userNameLabel->setGeometry(QRect(180, 240, 51, 21));
        pwdLabel = new QLabel(centralwidget);
        pwdLabel->setObjectName(QStringLiteral("pwdLabel"));
        pwdLabel->setGeometry(QRect(180, 310, 54, 12));
        findBackLabel = new QLabel(centralwidget);
        findBackLabel->setObjectName(QStringLiteral("findBackLabel"));
        findBackLabel->setGeometry(QRect(560, 470, 191, 41));
        findBackLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(150, 40, 591, 101));
        welcomeLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";\n"
"background-color: rgb(255, 255, 127);"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(260, 390, 111, 41));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(510, 170, 256, 190));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 820, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        registerButton->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        loginInButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        findBackButton->setText(QApplication::translate("MainWindow", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        userNameLabel->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        pwdLabel->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        findBackLabel->setText(QApplication::translate("MainWindow", "\345\277\230\350\256\260\345\257\206\347\240\201\357\274\237\350\257\267\347\202\271\345\207\273\342\200\234\346\211\276\345\233\236\345\257\206\347\240\201\342\200\235\346\214\211\351\224\256", Q_NULLPTR));
        welcomeLabel->setText(QApplication::translate("MainWindow", "\351\253\230\351\200\237\345\205\254\350\267\257\346\234\272\347\224\265\350\256\276\345\244\207\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
