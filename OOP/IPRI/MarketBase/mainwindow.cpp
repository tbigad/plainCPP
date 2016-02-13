#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    market = new Market;
    market->addItem("milk",1.1, 5);
    market->addItem("bread",0.8,10);
    market->addItem("egg",1.01,3);
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete market;
}

void MainWindow::update()
{
    ui->tableWidget->clear();
    list<shared_ptr<MarketItem> > _itemList = market->getList();
    ui->tableWidget->setRowCount(_itemList.size());
    ui->tableWidget->setColumnCount(3);

    int i = 0;
    foreach (shared_ptr<MarketItem> item, _itemList) {
        QString qstr = QString::fromUtf8(item->getTitle().c_str(), item->getTitle().size());
        QTableWidgetItem* title = new QTableWidgetItem(qstr);
        qstr = QString::number(item->getQuantity());
        QTableWidgetItem* quantity = new QTableWidgetItem(qstr);
        qstr = QString::number(item->getCost());
        QTableWidgetItem* cost = new QTableWidgetItem(qstr);
        ui->tableWidget->setItem(i,0,title);
        ui->tableWidget->setItem(i,1,cost);
        ui->tableWidget->setItem(i,2,quantity);
        i++;
    }

}
