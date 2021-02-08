/********************************************************************************
** Form generated from reading UI file 'equipmentshowdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPMENTSHOWDIALOG_H
#define UI_EQUIPMENTSHOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_EquipmentShowDialog
{
public:
    QTableWidget *tableWidget;
    QPushButton *sortByMatchIdButton;
    QPushButton *sortByNameButton;
    QPushButton *sortByAreaButton;
    QPushButton *editButton;
    QLabel *searchLabel;
    QLineEdit *namelineEdit;
    QPushButton *nameButton;
    QPushButton *matchIdButton;
    QLineEdit *matchIdlineEdit;
    QPushButton *areaButton;
    QLineEdit *arealineEdit;

    void setupUi(QDialog *EquipmentShowDialog)
    {
        if (EquipmentShowDialog->objectName().isEmpty())
            EquipmentShowDialog->setObjectName(QStringLiteral("EquipmentShowDialog"));
        EquipmentShowDialog->resize(1018, 521);
        tableWidget = new QTableWidget(EquipmentShowDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 30, 581, 321));
        sortByMatchIdButton = new QPushButton(EquipmentShowDialog);
        sortByMatchIdButton->setObjectName(QStringLiteral("sortByMatchIdButton"));
        sortByMatchIdButton->setGeometry(QRect(480, 380, 171, 23));
        sortByNameButton = new QPushButton(EquipmentShowDialog);
        sortByNameButton->setObjectName(QStringLiteral("sortByNameButton"));
        sortByNameButton->setGeometry(QRect(130, 380, 131, 23));
        sortByAreaButton = new QPushButton(EquipmentShowDialog);
        sortByAreaButton->setObjectName(QStringLiteral("sortByAreaButton"));
        sortByAreaButton->setGeometry(QRect(290, 380, 171, 23));
        editButton = new QPushButton(EquipmentShowDialog);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(40, 380, 75, 23));
        searchLabel = new QLabel(EquipmentShowDialog);
        searchLabel->setObjectName(QStringLiteral("searchLabel"));
        searchLabel->setGeometry(QRect(780, 80, 51, 16));
        namelineEdit = new QLineEdit(EquipmentShowDialog);
        namelineEdit->setObjectName(QStringLiteral("namelineEdit"));
        namelineEdit->setGeometry(QRect(680, 140, 113, 20));
        nameButton = new QPushButton(EquipmentShowDialog);
        nameButton->setObjectName(QStringLiteral("nameButton"));
        nameButton->setGeometry(QRect(830, 140, 101, 23));
        matchIdButton = new QPushButton(EquipmentShowDialog);
        matchIdButton->setObjectName(QStringLiteral("matchIdButton"));
        matchIdButton->setGeometry(QRect(830, 200, 101, 23));
        matchIdlineEdit = new QLineEdit(EquipmentShowDialog);
        matchIdlineEdit->setObjectName(QStringLiteral("matchIdlineEdit"));
        matchIdlineEdit->setGeometry(QRect(680, 200, 113, 20));
        areaButton = new QPushButton(EquipmentShowDialog);
        areaButton->setObjectName(QStringLiteral("areaButton"));
        areaButton->setGeometry(QRect(830, 260, 101, 23));
        arealineEdit = new QLineEdit(EquipmentShowDialog);
        arealineEdit->setObjectName(QStringLiteral("arealineEdit"));
        arealineEdit->setGeometry(QRect(680, 260, 113, 20));

        retranslateUi(EquipmentShowDialog);

        QMetaObject::connectSlotsByName(EquipmentShowDialog);
    } // setupUi

    void retranslateUi(QDialog *EquipmentShowDialog)
    {
        EquipmentShowDialog->setWindowTitle(QApplication::translate("EquipmentShowDialog", "Dialog", Q_NULLPTR));
        sortByMatchIdButton->setText(QApplication::translate("EquipmentShowDialog", "\346\214\211\350\256\276\345\244\207\347\274\226\345\217\267\350\277\233\350\241\214\346\216\222\345\272\217", Q_NULLPTR));
        sortByNameButton->setText(QApplication::translate("EquipmentShowDialog", "\346\214\211\345\234\260\345\214\272\350\277\233\350\241\214\346\216\222\345\272\217", Q_NULLPTR));
        sortByAreaButton->setText(QApplication::translate("EquipmentShowDialog", "\346\214\211\350\256\276\345\244\207\345\220\215\347\247\260\350\277\233\350\241\214\346\216\222\345\272\217", Q_NULLPTR));
        editButton->setText(QApplication::translate("EquipmentShowDialog", "\347\274\226\350\276\221", Q_NULLPTR));
        searchLabel->setText(QApplication::translate("EquipmentShowDialog", "\346\237\245\350\257\242\345\214\272", Q_NULLPTR));
        nameButton->setText(QApplication::translate("EquipmentShowDialog", "\346\214\211\350\256\276\345\244\207\345\220\215\347\247\260\346\237\245\350\257\242", Q_NULLPTR));
        matchIdButton->setText(QApplication::translate("EquipmentShowDialog", "\346\214\211\350\256\276\345\244\207\347\274\226\345\217\267\346\237\245\350\257\242", Q_NULLPTR));
        areaButton->setText(QApplication::translate("EquipmentShowDialog", "\346\214\211\345\234\260\345\214\272\346\237\245\350\257\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EquipmentShowDialog: public Ui_EquipmentShowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPMENTSHOWDIALOG_H
