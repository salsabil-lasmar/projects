#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cdefinelist.h"
#include"cdefine.h"
#include"addwindow.h"
#include "deletedefine.h"
#include "editwindow.h"
#include "getpath.h"

#include<QDebug>
#include<QFile>
#include<QVBoxLayout>
#include<QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel();
    loadData();

     ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

     connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));

}

void MainWindow::loadData()
{
    model->clear();
    model->setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Value"));
    model->setHorizontalHeaderItem(2, new QStandardItem("type_file"));

    ui->tableView->setModel(model);
    CDefineList obj;
    obj.init();
    QList<QStandardItem *> list_items;
    for(auto itr = obj.mDefineList.begin(); itr != obj.mDefineList.end() ; ++itr) {
         list_items.append(new QStandardItem(itr->name));
         list_items.append(new QStandardItem(itr->value));
         list_items.append(new QStandardItem(itr->type_file));

         model->appendRow(list_items);
         list_items.clear();
     }
}
void MainWindow::treeView(){

  /*  QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();
    QList<QString> ClientList;
    getpath obj;
    ClientList = obj.getClientList();
    for(  const auto &element : qAsConst(ClientList)){

        auto item = new QStandardItem (element);

        rootNode->appendRow(item);
        item->appendRow(new QStandardItem ("Define"));
        item->appendRow(new QStandardItem ("DBDesc"));
        item->appendRow(new QStandardItem ("Configproperty"));
        ui->treeView->setModel(standardModel);
        break;
    }*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_pushButton_clicked()
{
    AddNewDefine* addNewDefine=new  AddNewDefine(this);
    addNewDefine->show();

}


void MainWindow :: slotCustomMenuRequested(QPoint pos)
{


    QMenu *contextMenu = new QMenu(this);
    QAction * deleteAct = new QAction(tr("delete"), this);
    QAction * editAct = new QAction(tr("edit"), this);

    connect(deleteAct, SIGNAL(triggered()), this,SLOT(SlotDeleteDefine()));
    connect(editAct, SIGNAL(triggered()), this, SLOT(SlotEditDefine()));

    contextMenu->addAction(deleteAct);
    contextMenu->addAction(editAct);

    contextMenu->popup(ui->tableView->viewport()->mapToGlobal(pos));


}


void MainWindow::SlotDeleteDefine()
{
     const QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int row =index.row();
   QString name  = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toString();
   QString path = ui->tableView->model()->data(ui->tableView->model()->index(row,2)).toString();

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

   loadData();
}

void MainWindow::SlotEditDefine()
{
    class EditDefine* editDefine=new class EditDefine(nullptr , ui);
    editDefine->show();
}


