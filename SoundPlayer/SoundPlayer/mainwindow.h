#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <soundplayer.h>
#include <QString>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QList <SoundPlayer*> _players;
    bool isMuted;
    bool isPlaying;
    bool isPaused;
private slots:
    void volumeSliderValueChanged(int value);
    void playButtonClicked();
    void pauseButtonClicked();
    void stopButtonClicked();
    void muteButtonClicked();
    void openFileWithAppending();
    void openFileWithoutAppending();
    void createPlaylistFromDirectory();
    void itemSelected(int, int);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList <SoundPlayer*> getPlayers() {return this->_players;}
    void appendPlayer(SoundPlayer *newPlayer) {this->_players.append(newPlayer);}
    void playTestFile(QString path, SoundPlayer*);
    void addToPlaylist(QString path);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
