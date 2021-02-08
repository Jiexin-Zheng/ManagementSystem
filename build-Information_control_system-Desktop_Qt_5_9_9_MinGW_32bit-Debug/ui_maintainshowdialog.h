/********************************************************************************
** Form generated from reading UI file 'maintainshowdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTAINSHOWDIALOG_H
#define UI_MAINTAINSHOWDIALOG_H

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

class Ui_MaintainShowDialog
{
public:
    QPushButton *matchIdButton;
    QPushButton *editButton;
    QPushButton *sortByTimeButton;
    QPushButton *idButton;
    QTableWidget *tableWidget;
    QLabel *searchLabel;
    QPushButton *sortByMatchIdButton;
    QLineEdit *idlineEdit;
    QLineEdit *matchIdlineEdit;

    void setupUi(QDialog *MaintainShowDialog)
    {
        if (MaintainShowDialog->objectName().isEmpty())
            MaintainShowDialog->setObjectName(QStringLiteral("MaintainShowDialog"));
        MaintainShowDialog->resize(995, 454);
        matchIdButton = new QPushButton(MaintainShowDialog);
        matchIdButton->setObjectName(QStringLiteral("matchIdButton"));
        matchIdButton->setGeometry(QRect(840, 230, 141, 23));
        editButton = new QPushButton(MaintainShowDialog);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(90, 410, 75, 23));
        sortByTimeButton = new QPushButton(MaintainShowDialog);
        sortByTimeButton->setObjectName(QStringLiteral("sortByTimeButton"));
        sortByTimeButton->setGeometry(QRect(280, 410, 101, 23));
        idButton = new QPushButton(MaintainShowDialog);
        idButton->setObjectName(QStringLiteral("idButton"));
        idButton->setGeometry(QRect(840, 170, 141, 23));
        tableWidget = new QTableWidget(MaintainShowDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(70, 60, 581, 321));
        searchLabel = new QLabel(MaintainShowDialog);
        searchLabel->setObjectName(QStringLiteral("searchLabel"));
        searchLabel->setGeometry(QRect(780, 100, 101, 20));
        sortByMatchIdButton = new QPushButton(MaintainShowDialog);
        sortByMatchIdButton->setObjectName(QStringLiteral("sortByMatchIdButton"));
        sortByMatchIdButton->setGeometry(QRect(490, 410, 151, 23));
        idlineEdit = new QLineEdit(MaintainShowDialog);
        idlineEdit->setObjectName(QStringLiteral("idlineEdit"));
        idlineEdit->setGeometry(QRect(680, 170, 113, 20));
        matchIdlineEdit = new QLineEdit(MaintainShowDialog);
        matchIdlineEdit->setObjectName(QStringLiteral("matchIdlineEdit"));
        matchIdlineEdit->setGeometry(QRect(680, 230, 113, 20));

        retranslateUi(MaintainShowDialog);

        QMetaObject::connectSlotsByName(MaintainShowDialog);
    } // setupUi

    void retranslateUi(QDialog *MaintainShowDialog)
    {
        MaintainShowDialog->setWindowTitle(QApplication::translate("MaintainShowDialog", "Dialog", Q_NULLPTR));
        matchIdButton->setText(QApplication::translate("MaintainShowDialog", "\346\240\271\346\215\256\346\234\272\347\224\265\350\256\276\345\244\207\347\274\226\345\217\267\346\237\245\350\257\242", Q_NULLPTR));
        editButton->setText(QApplication::translate("MaintainShowDialog", "\347\274\226\350\276\221", Q_NULLPTR));
        sortByTimeButton->setText(QApplication::translate("MaintainShowDialog", "\344\273\245\346\227\266\351\227\264\346\216\222\345\272\217", Q_NULLPTR));
        idButton->setText(QApplication::translate("MaintainShowDialog", "\346\240\271\346\215\256\347\274\226\345\217\267\346\237\245\350\257\242", Q_NULLPTR));
        searchLabel->setText(QApplication::translate("MaintainShowDialog", "\345\205\273\346\212\244\344\277\241\346\201\257\346\237\245\350\257\242\345\214\272", Q_NULLPTR));
        sortByMatchIdButton->setText(QApplication::translate("MaintainShowDialog", "\344\273\245\346\234\272\347\224\265\350\256\276\345\244\207\347\274\226\345\217\267\346\216\222\345\272\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MaintainShowDialog: public Ui_MaintainShowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTAINSHOWDIALOG_H
