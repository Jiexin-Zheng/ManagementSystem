/********************************************************************************
** Form generated from reading UI file 'modifypwddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYPWDDIALOG_H
#define UI_MODIFYPWDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModifyPwdDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *pwdlineEdit;
    QLineEdit *pwdagainlineEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ModifyPwdDialog)
    {
        if (ModifyPwdDialog->objectName().isEmpty())
            ModifyPwdDialog->setObjectName(QStringLiteral("ModifyPwdDialog"));
        ModifyPwdDialog->resize(400, 300);
        label = new QLabel(ModifyPwdDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 100, 54, 12));
        label_2 = new QLabel(ModifyPwdDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 170, 101, 16));
        pwdlineEdit = new QLineEdit(ModifyPwdDialog);
        pwdlineEdit->setObjectName(QStringLiteral("pwdlineEdit"));
        pwdlineEdit->setGeometry(QRect(170, 100, 113, 20));
        pwdagainlineEdit = new QLineEdit(ModifyPwdDialog);
        pwdagainlineEdit->setObjectName(QStringLiteral("pwdagainlineEdit"));
        pwdagainlineEdit->setGeometry(QRect(170, 160, 113, 20));
        confirmButton = new QPushButton(ModifyPwdDialog);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(70, 230, 75, 23));
        cancelButton = new QPushButton(ModifyPwdDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(200, 230, 75, 23));

        retranslateUi(ModifyPwdDialog);

        QMetaObject::connectSlotsByName(ModifyPwdDialog);
    } // setupUi

    void retranslateUi(QDialog *ModifyPwdDialog)
    {
        ModifyPwdDialog->setWindowTitle(QApplication::translate("ModifyPwdDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ModifyPwdDialog", "\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("ModifyPwdDialog", "\345\206\215\346\254\241\350\276\223\345\205\245", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("ModifyPwdDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ModifyPwdDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModifyPwdDialog: public Ui_ModifyPwdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPWDDIALOG_H
