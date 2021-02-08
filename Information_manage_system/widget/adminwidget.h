#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>
#include"dialog/equipmentshowdialog.h"
#include<QCloseEvent>
#include"dialog/maintainshowdialog.h"

namespace Ui {
class AdminWidget;
}

class AdminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWidget(QWidget* mainwindow = 0, QWidget *parent = nullptr);
    ~AdminWidget();

    User getUser() const;
    void setUser(const User &value);

private:
    Ui::AdminWidget *ui;
    QWidget *mainwindow;
    EquipmentShowDialog *equipments;
    MaintainShowDialog* maintains;
    User user;
protected:
    virtual void closeEvent(QCloseEvent* event);
private slots:
    void on_equipmentButton_clicked();
    void on_maintainButton_clicked();
};

#endif // ADMINWIDGET_H
