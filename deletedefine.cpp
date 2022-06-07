#include "deletedefine.h"
#include "ui_deletedefine.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cdefinelist.h"
#include "cdefine.h"

#include<QFile>
#include<QTextStream>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include<QMessageBox>
#include<QDebug>
DeleteDefine::DeleteDefine(QWidget *parent, Ui::MainWindow *Win) :
    QDialog(parent),
    ui_Win (Win),
    ui(new Ui::DeleteDefine)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked),this,SLOT(on_pushButton_clicked()));
}

DeleteDefine::~DeleteDefine()
{
    delete ui;
};

void DeleteDefine::on_pushButton_clicked()
{
      int  row = ui->lineEdit->text().toInt();

       QString name  = ui_Win->tableView->model()->data(ui_Win->tableView->model()->index(row-1,0)).toString();
       QString path = ui_Win->tableView->model()->data(ui_Win->tableView->model()->index(row-1,2)).toString();

       QFile file(path);
     if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {

         QTextStream stream (&file);
         QRegularExpression startline  (".*#define\\s*");
         QRegularExpression  endline ("\\s*.*");
         QRegularExpression regex (startline.pattern() + name + endline.pattern());
         QString s;
         while(!stream.atEnd()){

             QString line =stream.readLine();
             QRegularExpressionMatch regexMatcher = regex.match(line);
             if(!regexMatcher.hasMatch())
                 s.append(line + "\n");
          }
          file.resize(0);
          stream << s;
          file.close();

     }

       CDefineList obj;
       obj.setDefineList(path);

      ui_Win->tableView->model()->removeRow(row-1);//to refresh the table in real-time
}

