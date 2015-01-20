#include "mainwindow.h"
#include <QApplication>
#include "classaudio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString st = "/home/user1/Desktop/sound/Yamaha-SY-35-Clarinet-C5.wav";
    classAudio audio = new classAudio(st);
    return a.exec();
}
