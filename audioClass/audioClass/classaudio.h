#ifndef CLASSAUDIO_H
#define CLASSAUDIO_H

#include <QString>
#include <QMediaPlayer>
#include <QFile>
#include <QList>
#include <QMediaPlaylist>

class classAudio
{
private:
    QMediaPlayer *_player;
public:
    classAudio();
    classAudio(const QString audioPath);
    classAudio(const QString audioPath, bool playNow);
    classAudio(QMediaPlaylist list);
    ~classAudio();
    void setPath(const QString audioPath);
    void play();
    void stop();
    void pause();
    void seek(qint64 pos);
    void setVolume(int vol);
    void playPlaylist(QStringList pathAaudios, int index);

};

#endif // CLASSAUDIO_H
