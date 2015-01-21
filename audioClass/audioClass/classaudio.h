#ifndef CLASSAUDIO_H
#define CLASSAUDIO_H

#include <QAudio>
#include <QMultimedia>
#include <QString>
#include <QtCore>
#include <QtGlobal>
#include <QMediaPlayer>
#include <QFile>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioOutput>

class classAudio
{
private:
    QMediaPlayer *_player;
public:
    classAudio();
    classAudio(const QString &audioPath);
    classAudio(const QString &audioPath, bool &playNow);
    ~classAudio();
    void setPath(const QString audioPath);
    void play();
    void stop();
    void pause();
    void seek(qint64& pos);
    void setVolume(int vol);
};

#endif // CLASSAUDIO_H
