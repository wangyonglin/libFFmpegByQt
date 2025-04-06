#include <QCoreApplication>
#include <QApplication>
#include <QDebug>
#include "CameraPlayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    libFFmpegByQt::CameraPlayer player;
    player.play("/dev/video0");
    player.show();
    return a.exec();
}

