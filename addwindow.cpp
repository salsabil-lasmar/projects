#include "addwindow.h"
#include "ui_AddNewDefine.h"
#include "cdefinelist.h"
#include"cdefine.h"


#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QObject>
#include<QMessageBox>
AddNewDefine::AddNewDefine(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDefine)
{
    this->parent=parent;
    ui->setupUi(this);
   connect(ui->pushButton,SIGNAL(clicked),this,SLOT(on_pushButton_clicked()));

}

AddNewDefine::~AddNewDefine()
{
    delete ui;
}


void AddNewDefine::on_pushButton_clicked()
{

    QString path=ui->lineEdit->text();
    QString NewDefine=ui->textEdit->toPlainText();

    QFile file(path);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
      QTextStream stream (&file);
       while(!stream.atEnd())
           stream.readLine();

     QStringList list =NewDefine.split('\n');
     for(  const auto &e : qAsConst(list) ){
      stream << "   "<<e <<'\n';
     }

  }

  file.close();

  this->close();
  parent->loadData();

}

