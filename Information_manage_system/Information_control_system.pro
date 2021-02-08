QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog/confirmdialog.cpp \
    dialog/confirmdialogmaintain.cpp \
    dialog/equipmenteditdialog.cpp \
    dialog/equipmentshowdialog.cpp \
    dialog/maintaineditdialog.cpp \
    dialog/maintainshowdialog.cpp \
    dialog/modifypwddialog.cpp \
    dialog/registerdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    model/equipment.cpp \
    model/maintain.cpp \
    model/user.cpp \
    sql/sqldao.cpp \
    sql/sqlmanager.cpp \
    widget/adminwidget.cpp \
    widget/userwidget.cpp

HEADERS += \
    dialog/confirmdialog.h \
    dialog/confirmdialogmaintain.h \
    dialog/equipmenteditdialog.h \
    dialog/equipmentshowdialog.h \
    dialog/maintaineditdialog.h \
    dialog/maintainshowdialog.h \
    dialog/modifypwddialog.h \
    dialog/registerdialog.h \
    mainwindow.h \
    model/equipment.h \
    model/maintain.h \
    model/user.h \
    sql/sqldao.h \
    sql/sqlmanager.h \
    widget/adminwidget.h \
    widget/userwidget.h

FORMS += \
    dialog/confirmdialog.ui \
    dialog/confirmdialogmaintain.ui \
    dialog/equipmenteditdialog.ui \
    dialog/equipmentshowdialog.ui \
    dialog/maintaineditdialog.ui \
    dialog/maintainshowdialog.ui \
    dialog/modifypwddialog.ui \
    dialog/registerdialog.ui \
    mainwindow.ui \
    widget/adminwidget.ui \
    widget/userwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
