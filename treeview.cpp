#include "treeview.h"
#include "ui_treeview.h"

#include<QStandardItem>
#include<QFile>
#include<QDir>
#include<QItemSelection>
treeView::treeView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::treeView)
{
    ui->setupUi(this);
    QString path="C:\\Projekte\\windekis_src\\GIT\\windekis\\windekis";
    QDir dir (path );
    QList <QFileInfo> clientList= dir.entryInfoList();
    QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();

    for(  const auto &e : qAsConst(clientList)){
        QString ClientName= e.baseName();

        QString pathclientName=path+"\\"+ClientName;
        QDir directory (pathclientName);
        QStringList filters;
        filters << "*.groupproj";
        directory.setNameFilters(filters);
        QStringList testlist = directory.entryList();
        for(  const auto &element : qAsConst(testlist)){


             if(element.contains(".groupproj")  ){

                 auto item = new QStandardItem (ClientName);

                 rootNode->appendRow(item);
                 item->appendRow(new QStandardItem ("Define"));
                 item->appendRow(new QStandardItem ("DBDesc"));
                 item->appendRow(new QStandardItem ("Configproperty"));
                 ui->treeView->setModel(standardModel);
                 break;


             }

         }

    }
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
               this, &treeView::selectionChangedSlot);
}
void treeView::selectionChangedSlot(const QItemSelection)
{

    const QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    QModelIndex seekRoot = index;
    QString showparent = seekRoot.parent().data(Qt::DisplayRole).toString();
    QString text = QString("%1 of %2").arg(selectedText)
                            .arg(showparent);
     ui->label->setText(text);
}
treeView::~treeView()
{
    delete ui;
}
