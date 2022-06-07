#ifndef DELETEDEFINE_H
#define DELETEDEFINE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

namespace Ui {
class DeleteDefine;
}

class DeleteDefine : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDefine(QWidget *parent = nullptr , Ui::MainWindow *Win = nullptr);
    ~DeleteDefine();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui_Win;
    Ui::DeleteDefine *ui;
};

#endif // DELETEDEFINE_H
