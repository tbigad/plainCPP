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

void MainWindow::on_pushButton_clicked()
{
    QString inLineEditDisplay=ui->lineEdit->text();
        for(int i=0; i<inLineEditDisplay.length(); i++)
        {
            if(inLineEditDisplay[i]=='+')
            {
                QString firstPart=inLineEditDisplay.left(i);
                QString secondPart=inLineEditDisplay.right(inLineEditDisplay.length()-(i+1));
                double firstPartAsDouble=firstPart.toDouble();
                double secondPartAsDouble=secondPart.toDouble();
                inLineEditDisplay=QString::number(firstPartAsDouble+secondPartAsDouble);
            }
            if(inLineEditDisplay[i]=='-')
            {
                QString firstPart=inLineEditDisplay.left(i);
                QString secondPart=inLineEditDisplay.right(inLineEditDisplay.length()-(i+1));
                double firstPartAsDouble=firstPart.toDouble();
                double secondPartAsDouble=secondPart.toDouble();
                inLineEditDisplay=QString::number(firstPartAsDouble-secondPartAsDouble);
            }

            if(inLineEditDisplay[i]=='*')
            {
                QString firstPart=inLineEditDisplay.left(i);
                QString secondPart=inLineEditDisplay.right(inLineEditDisplay.length()-(i+1));
                double firstPartAsDouble=firstPart.toDouble();
                double secondPartAsDouble=secondPart.toDouble();
                inLineEditDisplay=QString::number(firstPartAsDouble*secondPartAsDouble);
            }
            if(inLineEditDisplay[i]=='/')
            {
                QString firstPart=inLineEditDisplay.left(i);
                QString secondPart=inLineEditDisplay.right(inLineEditDisplay.length()-(i+1));
                double firstPartAsDouble=firstPart.toDouble();
                double secondPartAsDouble=secondPart.toDouble();
                inLineEditDisplay=QString::number(firstPartAsDouble/secondPartAsDouble);
            }
        }
        ui->lineEdit->setText(inLineEditDisplay);
}

void MainWindow::on_numberButton_1_clicked()
{
    ui->lineEdit->insert("1");
}

void MainWindow::on_numberButton_2_clicked()
{
    ui->lineEdit->insert("2");
}

void MainWindow::on_numberButton_3_clicked()
{
    ui->lineEdit->insert("3");
}

void MainWindow::on_numberButton_4_clicked()
{
    ui->lineEdit->insert("4");
}

void MainWindow::on_numberButton_5_clicked()
{
    ui->lineEdit->insert("5");
}

void MainWindow::on_numberButton_6_clicked()
{
    ui->lineEdit->insert("6");
}

void MainWindow::on_numberButton_7_clicked()
{
    ui->lineEdit->insert("7");
}

void MainWindow::on_numberButton_8_clicked()
{
    ui->lineEdit->insert("8");
}

void MainWindow::on_numberButton_9_clicked()
{
    ui->lineEdit->insert("9");
}

void MainWindow::on_numberButton_0_clicked()
{
    ui->lineEdit->insert("0");
}

void MainWindow::on_plusButton_clicked()
{
    ui->lineEdit->insert("+");
}

void MainWindow::on_minusButton_clicked()
{
    ui->lineEdit->insert("-");
}

void MainWindow::on_multiplicationButton_clicked()
{
    ui->lineEdit->insert("*");
}

void MainWindow::on_divisionButton_clicked()
{
    ui->lineEdit->insert("/");
}

void MainWindow::on_dotButton_clicked()
{
    ui->lineEdit->insert(".");
}
