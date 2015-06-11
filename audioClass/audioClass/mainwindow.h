#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "classaudio.h"
#include <QListWidgetItem>

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
    void setVolumeFromUI(int vol);
    void setPathFromListWidget(QListWidgetItem *path);
    void addFilesToPlayList();
    void setCurrentItem(QListWidgetItem * item);
    void on_rmFromListButton_clicked();

private:
    void removeFromPListWidget(QListWidgetItem *item);
    Ui::MainWindow *ui;
    classAudio _audio;
    QStringList _files;
};

#endif // MAINWINDOW_H
