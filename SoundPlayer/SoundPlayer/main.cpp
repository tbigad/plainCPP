#include "mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <QThread>
#include <QMediaPlayer>
#include <QMediaPlaylist>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
