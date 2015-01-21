#include "classaudio.h"


classAudio::classAudio(const QString &audioPath)
{
    _player = new QMediaPlayer();
    _player->setMedia(QUrl::fromLocalFile(audioPath));
    _player->setVolume(50);
}

classAudio::classAudio(const QString &audioPath, bool &playNow)
{
    if(playNow)
    {
    QMediaPlayer player;
    player.setMedia(QUrl::fromLocalFile(audioPath));
    player.setVolume(50);
    player.play();
    }
    else
    {
    }
}

void classAudio::play()
{
    this->_player->play();
}

void classAudio::stop()
{
    this->_player->stop();
}

void classAudio::pause()
{
    this->_player->pause();
}

classAudio::~classAudio()
{
   delete _player;
}

void classAudio::seek(qint64 &pos)
{
    this->_player->setPosition(pos);
}
