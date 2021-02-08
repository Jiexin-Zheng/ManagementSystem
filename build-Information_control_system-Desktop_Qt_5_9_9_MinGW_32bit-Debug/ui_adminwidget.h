/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *userButton;
    QPushButton *equipmentButton;
    QPushButton *maintainButton;
    QCalendarWidget *calendarWidget;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QWidget *AdminWidget)
    {
        if (AdminWidget->objectName().isEmpty())
            AdminWidget->setObjectName(QStringLiteral("AdminWidget"));
        AdminWidget->resize(511, 470);
        verticalLayoutWidget = new QWidget(AdminWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(160, 90, 160, 83));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        userButton = new QPushButton(verticalLayoutWidget);
        userButton->setObjectName(QStringLiteral("userButton"));

        verticalLayout->addWidget(userButton);

        equipmentButton = new QPushButton(verticalLayoutWidget);
        equipmentButton->setObjectName(QStringLiteral("equipmentButton"));

        verticalLayout->addWidget(equipmentButton);

        maintainButton = new QPushButton(verticalLayoutWidget);
        maintainButton->setObjectName(QStringLiteral("maintainButton"));

        verticalLayout->addWidget(maintainButton);

        calendarWidget = new QCalendarWidget(AdminWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(120, 240, 256, 190));
        commandLinkButton = new QCommandLinkButton(AdminWidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(170, 190, 172, 41));

        retranslateUi(AdminWidget);

        QMetaObject::connectSlotsByName(AdminWidget);
    } // setupUi

    void retranslateUi(QWidget *AdminWidget)
    {
        AdminWidget->setWindowTitle(QApplication::translate("AdminWidget", "Form", Q_NULLPTR));
        userButton->setText(QApplication::translate("AdminWidget", "\347\224\250\346\210\267\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        equipmentButton->setText(QApplication::translate("AdminWidget", "\346\234\272\347\224\265\350\256\276\345\244\207\347\256\241\347\220\206", Q_NULLPTR));
        maintainButton->setText(QApplication::translate("AdminWidget", "\345\205\273\346\212\244\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("AdminWidget", "\345\274\200\345\247\213\344\275\240\347\232\204\346\223\215\344\275\234\357\274\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdminWidget: public Ui_AdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
