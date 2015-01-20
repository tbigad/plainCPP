#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H
#include <QMediaPlayer>
#include <QString>
#include <QList>
#include <QMediaPlaylist>
#include <QWidget>
#include <QUrl>

class SoundPlayer
{
private:
    QWidget *_parent;
    QMediaPlayer *_mediaPlayer;
    QMediaPlaylist *_mediaPlayList;
    int _currentPosition;
public:    
    SoundPlayer(QWidget *parent);
    ~SoundPlayer();
    void addFileToPlaylist(QString path);
    void removeFileFromThePlaylist(int index);
    void setVolume(int volume);
    void play();
    void pause();
    void unPause();
    void stop();
    void mute();
    void unMute();
    void playFileFromPlaylist(int index);
    void playSeparatedFile(QString path);
};

#endif // SOUNDPLAYER_H
