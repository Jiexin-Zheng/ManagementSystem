/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWidget
{
public:
    QPushButton *equipmentButton;
    QPushButton *maintainButton;
    QPushButton *modifyButton;
    QCalendarWidget *calendarWidget;
    QLabel *label;

    void setupUi(QWidget *UserWidget)
    {
        if (UserWidget->objectName().isEmpty())
            UserWidget->setObjectName(QStringLiteral("UserWidget"));
        UserWidget->resize(393, 473);
        equipmentButton = new QPushButton(UserWidget);
        equipmentButton->setObjectName(QStringLiteral("equipmentButton"));
        equipmentButton->setGeometry(QRect(150, 140, 91, 23));
        maintainButton = new QPushButton(UserWidget);
        maintainButton->setObjectName(QStringLiteral("maintainButton"));
        maintainButton->setGeometry(QRect(150, 190, 101, 23));
        modifyButton = new QPushButton(UserWidget);
        modifyButton->setObjectName(QStringLiteral("modifyButton"));
        modifyButton->setGeometry(QRect(110, 80, 171, 23));
        calendarWidget = new QCalendarWidget(UserWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(80, 250, 256, 190));
        label = new QLabel(UserWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 30, 121, 21));

        retranslateUi(UserWidget);

        QMetaObject::connectSlotsByName(UserWidget);
    } // setupUi

    void retranslateUi(QWidget *UserWidget)
    {
        UserWidget->setWindowTitle(QApplication::translate("UserWidget", "Form", Q_NULLPTR));
        equipmentButton->setText(QApplication::translate("UserWidget", "\346\234\272\347\224\265\350\256\276\345\244\207\347\256\241\347\220\206", Q_NULLPTR));
        maintainButton->setText(QApplication::translate("UserWidget", "\345\205\273\346\212\244\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        modifyButton->setText(QApplication::translate("UserWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("UserWidget", "\347\224\250\346\210\267\347\256\241\347\220\206\347\225\214\351\235\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserWidget: public Ui_UserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
