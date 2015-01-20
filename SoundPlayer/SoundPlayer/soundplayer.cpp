#include "soundplayer.h"

SoundPlayer::SoundPlayer(QWidget *parent)
{
    _parent = parent;
    _mediaPlayer = new QMediaPlayer();
    _mediaPlayList = new QMediaPlaylist();
    _mediaPlayer->setPlaylist(_mediaPlayList);
    _currentPosition = 0;
}

SoundPlayer::~SoundPlayer()
{
    delete _mediaPlayer;
    delete _mediaPlayList;
}

void SoundPlayer::setVolume(int volume)
{
    this->_mediaPlayer->setVolume(volume);
}

void SoundPlayer::play()
{
    this->_mediaPlayer->play();
}

void SoundPlayer::addFileToPlaylist(QString path)
{
    this->_mediaPlayList->addMedia(QUrl::fromLocalFile(path));
}

void SoundPlayer::removeFileFromThePlaylist(int index)
{
    this->_mediaPlayList->removeMedia(index);
}

void SoundPlayer::pause()
{
    _currentPosition = this->_mediaPlayer->position();
    this->_mediaPlayer->pause();
}

void SoundPlayer::unPause()
{
    this->_mediaPlayer->setPosition(_currentPosition);
    this->_mediaPlayer->play();
}

void SoundPlayer::stop()
{
    this->_mediaPlayer->stop();
}

void SoundPlayer::mute()
{
    this->_mediaPlayer->setMuted(true);
}

void SoundPlayer::unMute()
{
    this->_mediaPlayer->setMuted(false);
}

void SoundPlayer::playFileFromPlaylist(int index)
{
    this->_mediaPlayList->setCurrentIndex(index);
    play();
}

void SoundPlayer::playSeparatedFile(QString path)
{
    this->_mediaPlayList->addMedia(QUrl::fromLocalFile(path));
    this->play();
}

