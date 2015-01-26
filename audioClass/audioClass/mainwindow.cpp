#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "classaudio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(setVolumeFromUI(int)));
    connect(ui->openFiles, SIGNAL(triggered()), this, SLOT(addFilesToPlayList()));
    connect(ui->playList, SIGNAL(itemPressed(QListWidgetItem*)),this, SLOT(setPathFromListWidget(QListWidgetItem*)));
    connect(ui->playList, SIGNAL(itemPressed(QListWidgetItem*)),this, SLOT(setCurrentItem(QListWidgetItem*)));
    _audio.setVolume(ui->volumeSlider->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addFilesToPlayList()
{
    _files = QFileDialog::getOpenFileNames(this, "Select one or more files to open","/home/user1/Music", "Sound (*.wav)");
    ui->playList->addItems(_files);
   // _audio.playPlaylist(_files,ui->playList->currentRow());
}

void MainWindow::on_openFileButton_1_clicked()
{
    QString audioPath = QFileDialog::getOpenFileName(this);
    ui->filePath->setText(audioPath);
 //   _audio.setPath(ui->filePath->text());
    classAudio *audio;
    audio = new classAudio(audioPath, true);
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

void MainWindow::setVolumeFromUI(int vol)
{
    _audio.setVolume(vol);
}

void MainWindow::setPathFromListWidget(QListWidgetItem *path)
{
    _audio.setPath(path->text());
}

void MainWindow::removeFromPListWidget(QListWidgetItem *item)
{
    delete ui->playList->takeItem(ui->playList->row(item));
}

void MainWindow::setCurrentItem(QListWidgetItem * item)
{
    ui->playList->setCurrentItem(item);
}

void MainWindow::on_rmFromListButton_clicked()
{
   this->removeFromPListWidget(ui->playList->currentItem());
}
