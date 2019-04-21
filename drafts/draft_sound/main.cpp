#include "audio.h"

#include <iostream>
#include <QCoreApplication>

int main(int argc, char * argv[])
{
    QCoreApplication b(argc, argv);
    //Чтобы работало вот так:
    //Audio audio("C://path//to//folderWithWav","C://path//to//folderWithMusic");
    //audio.play("boom.wav"); // в папке с wav проиграть звук boom.wav
    //

    //Документация: https://doc.qt.io/qt-5/qsound.html

    //Пример проигрывания:
    QSound::play("C:\\Users\\konov\\Documents\\Audacity\\1.wav"); //Вставить путь до wav файла
    return b.exec();
}
