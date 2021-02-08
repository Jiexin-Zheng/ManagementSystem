/********************************************************************************
** Form generated from reading UI file 'confirmdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDIALOG_H
#define UI_CONFIRMDIALOG_H

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

class Ui_ConfirmDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *label;

    void setupUi(QDialog *ConfirmDialog)
    {
        if (ConfirmDialog->objectName().isEmpty())
            ConfirmDialog->setObjectName(QStringLiteral("ConfirmDialog"));
        ConfirmDialog->resize(398, 287);
        verticalLayoutWidget = new QWidget(ConfirmDialog);
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

        label = new QLabel(ConfirmDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 60, 181, 71));

        retranslateUi(ConfirmDialog);

        QMetaObject::connectSlotsByName(ConfirmDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDialog)
    {
        ConfirmDialog->setWindowTitle(QApplication::translate("ConfirmDialog", "Dialog", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("ConfirmDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ConfirmDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("ConfirmDialog", "\344\275\240\347\241\256\345\256\232\350\246\201\346\211\247\350\241\214\344\275\240\346\211\200\351\200\211\346\213\251\347\232\204\346\223\215\344\275\234\345\230\233\357\274\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfirmDialog: public Ui_ConfirmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDIALOG_H
