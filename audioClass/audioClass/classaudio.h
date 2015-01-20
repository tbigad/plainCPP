#ifndef CLASSAUDIO_H
#define CLASSAUDIO_H

#include <QAudio>
#include <QMultimedia>
#include <QString>
#include <QtCore>
#include <QtGlobal>

class classAudio
{
public:
    classAudio(QString audioPath);
    void play();
    void stop();
    void pause();
    void seek(qint64);
};

#endif // CLASSAUDIO_H
