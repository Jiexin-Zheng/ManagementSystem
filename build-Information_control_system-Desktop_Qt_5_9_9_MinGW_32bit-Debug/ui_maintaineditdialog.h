/********************************************************************************
** Form generated from reading UI file 'maintaineditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTAINEDITDIALOG_H
#define UI_MAINTAINEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaintainEditDialog
{
public:
    QTableWidget *tableWidget;
    QPushButton *modifyButton;
    QPushButton *removeButton;
    QPushButton *cancelButton;
    QPushButton *addButton;
    QPushButton *confirmButton;

    void setupUi(QWidget *MaintainEditDialog)
    {
        if (MaintainEditDialog->objectName().isEmpty())
            MaintainEditDialog->setObjectName(QStringLiteral("MaintainEditDialog"));
        MaintainEditDialog->resize(540, 479);
        tableWidget = new QTableWidget(MaintainEditDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 10, 471, 341));
        modifyButton = new QPushButton(MaintainEditDialog);
        modifyButton->setObjectName(QStringLiteral("modifyButton"));
        modifyButton->setGeometry(QRect(110, 430, 81, 23));
        removeButton = new QPushButton(MaintainEditDialog);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(330, 430, 81, 23));
        cancelButton = new QPushButton(MaintainEditDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(330, 380, 75, 23));
        addButton = new QPushButton(MaintainEditDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(220, 430, 81, 23));
        confirmButton = new QPushButton(MaintainEditDialog);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(110, 380, 75, 23));

        retranslateUi(MaintainEditDialog);

        QMetaObject::connectSlotsByName(MaintainEditDialog);
    } // setupUi

    void retranslateUi(QWidget *MaintainEditDialog)
    {
        MaintainEditDialog->setWindowTitle(QApplication::translate("MaintainEditDialog", "Form", Q_NULLPTR));
        modifyButton->setText(QApplication::translate("MaintainEditDialog", "\344\277\256\346\224\271\345\205\273\346\212\244\344\277\241\346\201\257", Q_NULLPTR));
        removeButton->setText(QApplication::translate("MaintainEditDialog", "\345\210\240\351\231\244\345\205\273\346\212\244\344\277\241\346\201\257", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("MaintainEditDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        addButton->setText(QApplication::translate("MaintainEditDialog", "\345\242\236\345\212\240\345\205\273\346\212\244\344\277\241\346\201\257", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("MaintainEditDialog", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MaintainEditDialog: public Ui_MaintainEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTAINEDITDIALOG_H
