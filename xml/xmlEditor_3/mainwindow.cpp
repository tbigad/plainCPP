#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Open_file, SIGNAL(triggered()), this, SLOT(openFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString error;
    QErrorMessage errorMsg;
    _filePath = QFileDialog::getOpenFileName(this, "Select file to open","/home/", "XML (*.xml)");
    if(_domDoc.setContent(_filePath,false,&error))
    {
       errorMsg.showMessage(error);
       errorMsg.exec();
    }

}
