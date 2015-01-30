#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QFileDialog>
#include <QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    nRow = 0;

    ui->setupUi(this);
    connect(ui->open_file, SIGNAL(triggered()),this,SLOT(startTree()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTree()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select file to open","../", "XML (*.xml)");
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug()<< "ERROR file.open"<< endl;
        return;
    }
    if (!doc.setContent(&file)) {
        qDebug() << "ERROR doc.setContent" << endl;
        file.close();
        return;
    }
    qDebug()<< doc.firstChild().nodeName();
    file.close();
    model = new QStandardItemModel();
    preOrder(doc.firstChild(), model);
    ui->treeView->setModel(model);
}

void MainWindow::insertFather(QString name)
{
    item = new QStandardItem(name);
    item->setEditable(false);
    qDebug() <<" item in insertFather(): "<< item->text()<< endl;
}

void MainWindow::insertChildren(QString name)
{
    QStandardItem *subItem = new QStandardItem( name );
    subItem->setCheckable(true);
    subItem->setEditable(false);
    item->appendRow(subItem);
    qDebug() << "subItem in insertChildren(): "<< subItem->text() << endl;
}

void MainWindow::setItem(QStandardItemModel *model)
{
    qDebug() << "nRow in setItem" << nRow << endl;
    qDebug() << "item in setItem" << item->text() << endl;
    model->setItem(nRow, item);
    nRow++;
}

void MainWindow::preOrder(QDomNode dom, QStandardItemModel *model)
{
    QString debug;
    qDebug() << "in preOrder()" << endl;
    if(!dom.isNull()){
        string aux = dom.nodeName().toStdString();
        string value ="value";
        if(dom.isText()){
            aux = dom.parentNode().nodeName().toStdString();

            if(strcmp()==0){
                debug.fromStdString(dom.nodeValue().toStdString());
                qDebug() << debug << endl;
                insertFather(dom.nodeValue());
                setItem(model);
            }
            if(strcmp(aux.c_str())==0)
            {
                debug.fromStdString(dom.nodeValue().toStdString());
                qDebug() << "\t" << debug << endl;
                insertChildren(dom.nodeValue());
            }
        }else
        {
            preOrder(dom.firstChild(), model);
            preOrder(dom.nextSibling(), model);
        }

    }
}
