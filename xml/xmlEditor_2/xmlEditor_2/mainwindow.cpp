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
}

void MainWindow::selectTreeItem(QModelIndex index)
{
    ui->treeView->setCurrentIndex(index);
    ui->tableWidget->clear();
    TreeItem *selected = model->itemFromIndex(ui->treeView->currentIndex());

    if(selected->hasChildren())
    {
        for(int i=0;i<selected->childCount(); i++)
        {
            QTableWidgetItem *valueTWI = new QTableWidgetItem;
            valueTWI->setText(selected->child(i)->getValue());
           if(valueTWI->text().size()>0)
           {
            QTableWidgetItem *textTWI = new QTableWidgetItem;
            textTWI->setText(selected->child(i)->text());
            textTWI->setFlags(Qt::ItemIsEnabled);
            qDebug() << textTWI->text() << " "<< valueTWI->text();
            ui->tableWidget->setRowCount(selected->childCount());
            ui->tableWidget->setColumnCount(2);
            ui->tableWidget->setItem(i,0,textTWI);
            ui->tableWidget->setItem(i,1,valueTWI);
           }
         }
    }
 }
