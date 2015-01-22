#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "classaudio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(kostyl(int)));
    _audio.setVolume(ui->volumeSlider->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_openFileButton_1_clicked()
{
    QString audioPath = QFileDialog::getOpenFileName(this);
    ui->filePath->setText(audioPath);
    _audio.setPath(ui->filePath->text());
}

void MainWindow::on_playButton_1_clicked()
{
    _audio.play();
}

void MainWindow::on_pauseButton_1_clicked()
{
    _audio.pause();
}

void MainWindow::on_stopButton_1_clicked()
{
    _audio.stop();
}

void MainWindow::kostyl(int vol)
{
    _audio.setVolume(vol);
}

//void MainWindow::seekAudio(int pos)
//{
//    _audio.seek(_audio.);
//}
