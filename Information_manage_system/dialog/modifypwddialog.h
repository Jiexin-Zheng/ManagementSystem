#ifndef MODIFYPWDDIALOG_H
#define MODIFYPWDDIALOG_H

#include <QDialog>

namespace Ui {
class ModifyPwdDialog;
}

class ModifyPwdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyPwdDialog(QWidget *parent = nullptr);
    ~ModifyPwdDialog();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ModifyPwdDialog *ui;
};

#endif // MODIFYPWDDIALOG_H
