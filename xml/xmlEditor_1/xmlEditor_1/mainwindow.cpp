#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Open_File, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->treeView,SIGNAL(doubleClicked(QModelIndex)),ui->treeView,SLOT(edit(QModelIndex)));
    model = new DomModel(QDomDocument(), this);
    ui->treeView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;    
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select file to open","../", "XML (*.xml)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QDomDocument document;
            if (document.setContent(&file)) {
                DomModel *newModel = new DomModel(document, this);
                ui->treeView->setModel(newModel);
                delete model;
                model = newModel;
                xmlPath = filePath;
            }
            file.close();
        }
    }
}
