#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plus_clicked()
{
    QString str = QString::number(ui->lineEditA->text().toDouble()+ui->lineEditB->text().toDouble());
    ui->lineEditB->setText(str);
    ui->lineEditA->clear();
}

void MainWindow::on_minus_clicked()
{
    QString str = QString::number(ui->lineEditA->text().toDouble()-ui->lineEditB->text().toDouble());
    ui->lineEditB->setText(str);
    ui->lineEditA->clear();
}



void MainWindow::on_Multiplication_clicked()
{
    QString str = QString::number(ui->lineEditA->text().toDouble()/ui->lineEditB->text().toDouble());
    ui->lineEditB->setText(str);
    ui->lineEditA->clear();
}

void MainWindow::on_Division_clicked()
{
    QString str = QString::number(ui->lineEditA->text().toDouble()*ui->lineEditB->text().toDouble());
    ui->lineEditB->setText(str);
    ui->lineEditA->clear();
}
