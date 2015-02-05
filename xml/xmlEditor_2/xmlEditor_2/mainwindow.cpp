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


    if(!selected->hasChildren())
    {
        QTableWidgetItem *valueTWI = new QTableWidgetItem;
        QTableWidgetItem *textTWI = new QTableWidgetItem;
        qDebug() << selected->getValue() << " " << selected->text() << " in !selected->hasChildren()";
        if(!selected->getValue().isEmpty())
        {

          ui->tableWidget->setRowCount(1);
          ui->tableWidget->setColumnCount(2);

         QStringList headerList;
         headerList << "Varible" << "Value";
         ui->tableWidget->setHorizontalHeaderLabels(headerList);
         ui->tableWidget->horizontalHeader()->show();

         valueTWI->setText(selected->getValue());
         textTWI->setText(selected->text());
         textTWI->setFlags(Qt::ItemIsEnabled);
         qDebug() << textTWI->text() << " "<< valueTWI->text() << " in selectTreeItem in !selected->hasChildren()";
         ui->tableWidget->setItem(0,0,textTWI);
         ui->tableWidget->setItem(0,1,valueTWI);
        }/*else
        {
            delete valueTWI;
            delete textTWI;
        }*/
    }

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
             qDebug() << textTWI->text() << " "<< valueTWI->text() << " in selectTreeItem";

             ui->tableWidget->setItem(i,0,textTWI);
             ui->tableWidget->setItem(i,1,valueTWI);
           }
         }

    }
 }

void MainWindow::changeItem(int row, int col)
{
    if(model->itemFromIndex(ui->treeView->currentIndex())->hasChildren())
    {
        model->itemFromIndex(ui->treeView->currentIndex())->child(row)->setValue(ui->tableWidget->item(row,col)->text());
    }
    else {
       model->itemFromIndex(ui->treeView->currentIndex())->setValue(ui->tableWidget->item(row,col)->text());
    }


}

void MainWindow::openHelp()
{
    QString filePath = "../xmlExamples/help.xml";
    help = new QDomDocument;
    QFile file(filePath);
        if (file.open(QIODevice::ReadOnly))
        {
        if(!help->setContent(&file))
        {
            qDebug()<< "can't setContent";
            file.close();
        }
 file.close();
        }
}

void MainWindow::printHelp(TreeItem *itemForHelp)
{
    ui->textBrowser->clear();
    qDebug()<< itemForHelp->text() << " in printHelp";

    QDomElement helpElement = help->documentElement();
    QDomNode n = helpElement.firstChild();
    while(!n.isNull())
    {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull())
        {
            if(e.tagName()==itemForHelp->text())
            {
                ui->textBrowser->setText(e.text());
            }
        }
        n = n.nextSibling();
    }
}





