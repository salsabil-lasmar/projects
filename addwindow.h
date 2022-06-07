#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
namespace Ui {
class AddNewDefine;
}

class AddNewDefine : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDefine(MainWindow *parent = nullptr );
    ~AddNewDefine();



private slots:
    void on_pushButton_clicked();

private:
    Ui::AddNewDefine *ui;
    MainWindow *parent;
};

#endif // ADDWINDOW_H
