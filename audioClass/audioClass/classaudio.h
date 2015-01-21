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
    classAudio(const QString &audioPath);
    classAudio(const QString &audioPath, bool &playNow);
    ~classAudio();
    void play();
    void stop();
    void pause();
    void seek(qint64);
};

#endif // CLASSAUDIO_H
