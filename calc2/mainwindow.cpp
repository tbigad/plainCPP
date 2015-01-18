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
        //inLineEditDisplay.append('+');
        ui->lineEdit->setText(inLineEditDisplay);
}
