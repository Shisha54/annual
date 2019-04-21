#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <QSound>

class Audio
{

public:
    Audio(std::string pathToSounds, std::string pathToMusic);
    void play(std::string nameOfSound);
    //void setVolume(..) итд

    //Пример того, как воспроизвести звук:



};

#endif // AUDIO_H
