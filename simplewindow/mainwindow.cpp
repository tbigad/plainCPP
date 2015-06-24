#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete win;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sWinVec.push_back(QSharedPointer<SimpleWindow>(new SimpleWindow));
  //  win = new SimpleWindow();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    //win->close();
    for(int i = 0; i< sWinVec.size(); i++)
    {
        sWinVec[i].data()->close();
    }
    sWinVec.clear();
    event->accept();
}
