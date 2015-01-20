#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QStringList>
#include <QTableWidgetItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _players.append(new SoundPlayer(this));
    _players.append(new SoundPlayer(this));
    _players.append(new SoundPlayer(this));
    isMuted = false;
    isPlaying = false;
    isPaused = false;
    this->ui->playlist->insertColumn(ui->playlist->columnCount());
    this->_players.first()->setVolume(ui->volumeSlider->value());
    connect (ui->actionOpen_file_with_appending_to_playlist, SIGNAL(triggered()), this, SLOT(openFileWithAppending()));
    connect (ui->actionOpen_separated_file, SIGNAL(triggered()), this, SLOT(openFileWithoutAppending()));
    connect (ui->actionCreate_playlist_from_directory, SIGNAL(triggered()), this, SLOT(createPlaylistFromDirectory()));
    connect (ui->playButton, SIGNAL(clicked()), this, SLOT(playButtonClicked()));
    connect (ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseButtonClicked()));
    connect (ui->stopButton, SIGNAL(clicked()), this, SLOT(stopButtonClicked()));
    connect (ui->muteButton, SIGNAL(clicked()), this, SLOT(muteButtonClicked()));
    connect (ui->volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(volumeSliderValueChanged(int)));
    connect(ui->playlist, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(itemSelected(int, int)));
    }

MainWindow::~MainWindow()
{
    delete ui;
    for (int i; i < _players.size(); i++)
    {
        delete _players.at(i);
    }
}

void MainWindow::playTestFile(QString path, SoundPlayer *sp)
{
    this->_players.at(this->_players.indexOf(sp))->playSeparatedFile(path);
}

void MainWindow::volumeSliderValueChanged(int value)
{
    this->_players.first()->setVolume(value);
}

void MainWindow::playButtonClicked()
{
    this->_players.first()->play();
}

void MainWindow::pauseButtonClicked()
{
    if (!isPaused)
    {
        this->_players.first()->pause();
        isPaused = true;
    }
    else
    {
        this->_players.first()->unPause();
        isPaused = false;
    }
}

void MainWindow::stopButtonClicked()
{
    this->_players.first()->stop();
}

void MainWindow::muteButtonClicked()
{
    if(!isMuted)
    {
        this->_players.first()->mute();
        isMuted = true;
    }
    else
    {
        this->_players.first()->unMute();
        isMuted = false;
    }
}

void MainWindow::openFileWithAppending()
{
    QString path = QFileDialog::getOpenFileName(this, "Select .wav file", "/windows", "*.wav");
    this->_players.first()->addFileToPlaylist(path);
    addToPlaylist(path);
}

void MainWindow::openFileWithoutAppending()
{
    QString path = QFileDialog::getOpenFileName(this, "Select .wav file", "/windows", "*.wav");
    this->_players.first()->playSeparatedFile(path);
}

void MainWindow::createPlaylistFromDirectory()
{
    QDir dir (QFileDialog::getExistingDirectory(this, "Select directiry", "/home", QFileDialog::DontResolveSymlinks));
    QStringList wav = dir.entryList(QStringList("*.wav"));
    foreach (QString file, wav)
    {
        this->_players.first()->addFileToPlaylist(dir.path()+"/"+file);
        addToPlaylist(dir.path()+"/"+file);
    }
}

void MainWindow::addToPlaylist(QString path)
{
    this->ui->playlist->insertRow(this->ui->playlist->rowCount());
    this->ui->playlist->setColumnWidth(0, ui->playlist->width());
    this->ui->playlist->setItem(this->ui->playlist->rowCount()-1, this->ui->playlist->columnCount()-1,
        new QTableWidgetItem (path));
}

void MainWindow::itemSelected(int row, int col)
{
    this->_players.first()->playFileFromPlaylist(row);
}
