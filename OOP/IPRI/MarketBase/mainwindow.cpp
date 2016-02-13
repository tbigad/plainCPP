#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QThread>

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
    ui->listWidget->clear();
    list<shared_ptr<MarketItem> > _itemList = market->getList();

    foreach (shared_ptr<MarketItem> item, _itemList) {
        QString qstr ="Title: "+ QString::fromUtf8(item->getTitle().c_str(), item->getTitle().size());
        qstr +=" Quantity: "+ QString::number(item->getQuantity());
        qstr +=" Cost: "+ QString::number(item->getCost()) + '£';
        QListWidgetItem *view = new QListWidgetItem();
        view->setText(qstr);
        view->setData(Qt::WhatsThisRole, item->getID());
        ui->listWidget->insertItem(0,view);
    }

}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *itL)
{
    ui->titleEdit->clear();
    ui->priceEdit->clear();
    ui->quantityEdit->clear();

    MarketItem item = market->itemFromID(itL->data(Qt::WhatsThisRole).toInt());

    QString Title =QString::fromUtf8(item.getTitle().c_str(), item.getTitle().size());
    QString Quantity = QString::number(item.getQuantity());
    QString Cost = QString::number(item.getCost());

    ui->titleEdit->setText(Title);
    ui->priceEdit->setText(Cost);
    ui->quantityEdit->setText(Quantity);
    currentID = item.getID();
}

void MainWindow::on_addButton_pressed()
{
    std::string title = ui->titleEdit->text().toStdString();
    double Quantity = ui->quantityEdit->text().toDouble();
    int Cost = ui->priceEdit->text().toInt();
    market->addItem(title,Cost,Quantity);
    update();
}

void MainWindow::on_buyButton_pressed()
{
    if(!ui->listWidget->currentItem())
        return;
    market->itemFromID(currentID).buy();
    update();
}

void MainWindow::on_editButton_pressed()
{
    if(currentID == 0)
        return;
    std::string title = ui->titleEdit->text().toStdString();
    double Quantity = ui->quantityEdit->text().toDouble();
    int Cost = ui->priceEdit->text().toInt();
    market->editItem(currentID,title,Cost,Quantity);
    update();
}
