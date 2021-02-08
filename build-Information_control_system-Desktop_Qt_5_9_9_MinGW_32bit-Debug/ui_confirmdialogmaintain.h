/********************************************************************************
** Form generated from reading UI file 'confirmdialogmaintain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDIALOGMAINTAIN_H
#define UI_CONFIRMDIALOGMAINTAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfirmDialogMaintain
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ConfirmDialogMaintain)
    {
        if (ConfirmDialogMaintain->objectName().isEmpty())
            ConfirmDialogMaintain->setObjectName(QStringLiteral("ConfirmDialogMaintain"));
        ConfirmDialogMaintain->resize(400, 300);
        label = new QLabel(ConfirmDialogMaintain);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 70, 181, 71));
        verticalLayoutWidget = new QWidget(ConfirmDialogMaintain);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 170, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        confirmButton = new QPushButton(verticalLayoutWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        verticalLayout->addWidget(confirmButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        retranslateUi(ConfirmDialogMaintain);

        QMetaObject::connectSlotsByName(ConfirmDialogMaintain);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDialogMaintain)
    {
        ConfirmDialogMaintain->setWindowTitle(QApplication::translate("ConfirmDialogMaintain", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ConfirmDialogMaintain", "\344\275\240\347\241\256\345\256\232\350\246\201\346\211\247\350\241\214\344\275\240\346\211\200\351\200\211\346\213\251\347\232\204\346\223\215\344\275\234\345\230\233\357\274\237", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("ConfirmDialogMaintain", "\347\241\256\350\256\244", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ConfirmDialogMaintain", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfirmDialogMaintain: public Ui_ConfirmDialogMaintain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDIALOGMAINTAIN_H
