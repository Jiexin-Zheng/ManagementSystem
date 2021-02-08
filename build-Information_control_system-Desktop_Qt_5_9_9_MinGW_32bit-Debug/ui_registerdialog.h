/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLabel *usernameLabel;
    QLabel *pwdLabel;
    QLineEdit *usernameLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *pwdAgainLabel;
    QLineEdit *pwdAgainLineEdit;
    QLabel *areaIdLabel;
    QLineEdit *areaIdLineEdit;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(349, 399);
        usernameLabel = new QLabel(RegisterDialog);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));
        usernameLabel->setGeometry(QRect(60, 70, 54, 12));
        pwdLabel = new QLabel(RegisterDialog);
        pwdLabel->setObjectName(QStringLiteral("pwdLabel"));
        pwdLabel->setGeometry(QRect(60, 120, 54, 12));
        usernameLineEdit = new QLineEdit(RegisterDialog);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(170, 70, 113, 20));
        pwdLineEdit = new QLineEdit(RegisterDialog);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(170, 120, 113, 20));
        confirmButton = new QPushButton(RegisterDialog);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(70, 230, 75, 23));
        cancelButton = new QPushButton(RegisterDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(200, 230, 75, 23));
        pwdAgainLabel = new QLabel(RegisterDialog);
        pwdAgainLabel->setObjectName(QStringLiteral("pwdAgainLabel"));
        pwdAgainLabel->setGeometry(QRect(60, 170, 51, 20));
        pwdAgainLineEdit = new QLineEdit(RegisterDialog);
        pwdAgainLineEdit->setObjectName(QStringLiteral("pwdAgainLineEdit"));
        pwdAgainLineEdit->setGeometry(QRect(170, 170, 113, 20));
        pwdAgainLineEdit->setReadOnly(false);
        areaIdLabel = new QLabel(RegisterDialog);
        areaIdLabel->setObjectName(QStringLiteral("areaIdLabel"));
        areaIdLabel->setGeometry(QRect(60, 20, 54, 12));
        areaIdLineEdit = new QLineEdit(RegisterDialog);
        areaIdLineEdit->setObjectName(QStringLiteral("areaIdLineEdit"));
        areaIdLineEdit->setGeometry(QRect(170, 20, 113, 20));
        commandLinkButton = new QCommandLinkButton(RegisterDialog);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(70, 290, 211, 41));

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Dialog", Q_NULLPTR));
        usernameLabel->setText(QApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        pwdLabel->setText(QApplication::translate("RegisterDialog", "\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("RegisterDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("RegisterDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        pwdAgainLabel->setText(QApplication::translate("RegisterDialog", "\345\206\215\346\254\241\350\276\223\345\205\245", Q_NULLPTR));
        areaIdLabel->setText(QApplication::translate("RegisterDialog", "\345\234\260\345\214\272\345\214\272\345\217\267", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("RegisterDialog", "\351\251\254\344\270\212\350\216\267\345\217\226\344\275\240\347\232\204\347\263\273\347\273\237\347\256\241\347\220\206\350\264\246\346\210\267\345\220\247\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
