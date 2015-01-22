#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "classaudio.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openFileButton_1_clicked();
    void on_playButton_1_clicked();
    void on_pauseButton_1_clicked();
    void on_stopButton_1_clicked();
    void kostyl(int vol);
    void seekAudio(int pos);
private:
    Ui::MainWindow *ui;
    classAudio _audio;
};

#endif // MAINWINDOW_H
