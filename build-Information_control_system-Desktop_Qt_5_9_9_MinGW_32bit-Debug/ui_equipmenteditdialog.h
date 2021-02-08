/********************************************************************************
** Form generated from reading UI file 'equipmenteditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPMENTEDITDIALOG_H
#define UI_EQUIPMENTEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EquipmentEditDialog
{
public:
    QTableWidget *tableWidget;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QPushButton *modifyButton;
    QPushButton *addButton;
    QPushButton *removeButton;

    void setupUi(QWidget *EquipmentEditDialog)
    {
        if (EquipmentEditDialog->objectName().isEmpty())
            EquipmentEditDialog->setObjectName(QStringLiteral("EquipmentEditDialog"));
        EquipmentEditDialog->resize(669, 513);
        tableWidget = new QTableWidget(EquipmentEditDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 20, 581, 321));
        confirmButton = new QPushButton(EquipmentEditDialog);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(110, 400, 75, 23));
        cancelButton = new QPushButton(EquipmentEditDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(430, 400, 75, 23));
        modifyButton = new QPushButton(EquipmentEditDialog);
        modifyButton->setObjectName(QStringLiteral("modifyButton"));
        modifyButton->setGeometry(QRect(114, 450, 121, 23));
        addButton = new QPushButton(EquipmentEditDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(280, 450, 91, 23));
        removeButton = new QPushButton(EquipmentEditDialog);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(420, 450, 91, 23));

        retranslateUi(EquipmentEditDialog);

        QMetaObject::connectSlotsByName(EquipmentEditDialog);
    } // setupUi

    void retranslateUi(QWidget *EquipmentEditDialog)
    {
        EquipmentEditDialog->setWindowTitle(QApplication::translate("EquipmentEditDialog", "Form", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("EquipmentEditDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("EquipmentEditDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        modifyButton->setText(QApplication::translate("EquipmentEditDialog", "\344\277\256\346\224\271\346\234\272\347\224\265\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
        addButton->setText(QApplication::translate("EquipmentEditDialog", "\345\242\236\345\212\240\346\234\272\347\224\265\350\256\276\345\244\207", Q_NULLPTR));
        removeButton->setText(QApplication::translate("EquipmentEditDialog", "\345\210\240\351\231\244\346\234\272\347\224\265\350\256\276\345\244\207", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EquipmentEditDialog: public Ui_EquipmentEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPMENTEDITDIALOG_H
