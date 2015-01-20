#include "classaudio.h"
#include <QMediaPlayer>
#include <QFile>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioOutput>

classAudio::classAudio(QString audioPath)
{
    QMediaPlayer player;
    player.setMedia(QUrl::fromLocalFile(audioPath));
    player.setVolume(50);
    player.play();
}
