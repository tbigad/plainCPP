#include "classaudio.h"


classAudio::classAudio()
{
    _player = new QMediaPlayer();
    _player->setVolume(50);
}
classAudio::classAudio(const QString& audioPath)
{
    _player->setMedia(QUrl::fromLocalFile(audioPath));
    _player = new QMediaPlayer();
   // _player->setVolume(50);
}

classAudio::classAudio(const QString& audioPath, bool playNow)
{
    if(playNow)
    {
    _player->setMedia(QUrl::fromLocalFile(audioPath));
    _player->setVolume(50);
    _player->play();
    }
}

void classAudio::setPath(const QString audioPath)
{
    _player->setMedia(QUrl::fromLocalFile(audioPath));
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

void classAudio::seek(qint64& pos)
{
    this->_player->setPosition(pos);
}

void classAudio::setVolume(int vol)
{
    if(vol<100)
    {
      this->_player->setVolume(vol);
    }
}

classAudio::~classAudio()
{
   delete _player;
}
