#ifndef EQUIPMENTSHOWDIALOG_H
#define EQUIPMENTSHOWDIALOG_H

#include <QDialog>
#include"dialog/equipmenteditdialog.h"
#include"model/user.h"

namespace Ui {
class EquipmentShowDialog;
}

class EquipmentShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EquipmentShowDialog(QWidget* mainWidget,QWidget *parent ,User& user);
    ~EquipmentShowDialog();

private slots:
    void on_sortByMatchIdButton_clicked();

    void on_sortByNameButton_clicked();

    void on_sortByAreaButton_clicked();

    void on_editButton_clicked();

    void on_nameButton_clicked();

    void on_matchIdButton_clicked();

    void on_areaButton_clicked();

private:
    Ui::EquipmentShowDialog *ui;
    QWidget* mainWidget;
    EquipmentEditDialog* eed;
    User& user;
};

#endif // EQUIPMENTSHOWDIALOG_H
