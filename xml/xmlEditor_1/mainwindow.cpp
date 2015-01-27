#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->open_File, SIGNAL(triggered()), this, SLOT(addFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addFile()
{
    _file = QFileDialog::getOpenFileName(this, "Select one file to open","/home/user1/Documents", "XML (*.xml)");
   if(!_editor.setFile(_file))
   {
       // Eror opening file
   }
}

void MainWindow::xmlToTreeWidget(const QString file)
{
    //ui->treeWidget->
}
