#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

namespace Ui {
class EditDefine;
}

class EditDefine : public QDialog
{
    Q_OBJECT

public:
    explicit EditDefine(QWidget *parent = nullptr , Ui::MainWindow *Win = nullptr);
    ~EditDefine();

private slots:
    void on_pushButton_clicked();

private:
   Ui::MainWindow *ui_Win;
    Ui::EditDefine *ui;
};

#endif // EDITWINDOW_H
