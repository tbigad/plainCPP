#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Open_file, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(selectTreeItem(QModelIndex)));
    connect(ui->Save_file, SIGNAL(triggered()),this, SLOT(saveFile()));
    connect(ui->tableWidget, SIGNAL(cellChanged(int,int)), this, SLOT(changeItem(int,int)));
    openHelp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Select file to open"),"/home/user1/Documents", tr("XML (*.xml)"));
    model = new TreeModel();
    QString xmlcontent = "";
    QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            xmlcontent = file.readAll();
            file.close();
        }
        model->fillModel(xmlcontent);
        ui->treeView->setModel(model);
        file.close();
}

void MainWindow::saveFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/user1/Documents", tr("XML (*.xml)"));
    model->writeXml(filePath);
    ui->tableWidget->clear();
    ui->treeView->reset();
}

void MainWindow::selectTreeItem(QModelIndex index)
{
    int i=0;
    ui->treeView->setCurrentIndex(index);
    ui->tableWidget->clear();
    while(ui->tableWidget->columnCount()>0)
    {
        ui->tableWidget->removeColumn(0);
    }
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
    TreeItem *selected = model->itemFromIndex(ui->treeView->currentIndex());
    printHelp(selected);
    if(selected->hasChildren())
    {
        while (!selected->child(i)->getValue().isEmpty())
        {
          qDebug() << i;
          i++;
          if (i >= selected->childCount())
          {
              break;
          }
        }
        ui->tableWidget->setRowCount(i);
        ui->tableWidget->setColumnCount(2);
        for(int i=0;i<selected->childCount(); i++)
        {
            QTableWidgetItem *valueTWI = new QTableWidgetItem;
            valueTWI->setText(selected->child(i)->getValue());
            if(valueTWI->text().size()>0)
            {
             QStringList headerList;
             headerList << "Varible" << "Value";
             ui->tableWidget->setHorizontalHeaderLabels(headerList);
             ui->tableWidget->horizontalHeader()->show();
             QTableWidgetItem *textTWI = new QTableWidgetItem;
             textTWI->setText(selected->child(i)->text());
             textTWI->setFlags(Qt::ItemIsEnabled);
             qDebug() << textTWI->text() << " "<< valueTWI->text();


             ui->tableWidget->setItem(i,0,textTWI);
             ui->tableWidget->setItem(i,1,valueTWI);
           }
         }

    }
 }

void MainWindow::changeItem(int row, int col)
{
    model->itemFromIndex(ui->treeView->currentIndex())->child(row)->setValue(ui->tableWidget->item(row,col)->text());
}

void MainWindow::openHelp()
{
    QString filePath = "../xmlExamples/help.xml";
    help = new QDomDocument;
    QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            if(!help->setContent(&file))
            {qDebug()<< "can't setContent";}
            file.close();
        }else
        {
            file.close();
            qDebug() << "Can't open file";
        }

}

void MainWindow::printHelp(TreeItem *itemForHelp)
{
    QDomNodeList list;
    for (int i=0;list.count()<i;i++)
    {
        qDebug()<< list.item(i).toElement().text() << " in Help";
        ui->listWidget->addItem(list.item(i).toElement().text());
    }
}


