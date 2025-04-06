#include "CameraThread.h"

libFFmpegByQt::CameraThread::CameraThread(QObject *parent)
    : QThread(parent),
    pauseFlag(false),
    stopFlag(false)
{}

libFFmpegByQt::CameraThread::~CameraThread()
{

}


libFFmpegByQt::CameraThread::State libFFmpegByQt::CameraThread::state() const
{
    State s = Stoped;
    if (!QThread::isRunning())
    {
        s = Stoped;
    }
    else if (QThread::isRunning() && pauseFlag)
    {
        s = Paused;
    }
    else if (QThread::isRunning() && (!pauseFlag))
    {
        s = Running;
    }
    return s;
}

void libFFmpegByQt::CameraThread::start(QThread::Priority pri)
{
    QThread::start(pri);
}



void libFFmpegByQt::CameraThread::stop()
{
    if (QThread::isRunning())
    {
        stopFlag = true;
        condition.wakeAll();
        QThread::quit();
        QThread::wait();
    }
}

void libFFmpegByQt::CameraThread::pause()
{
    if (QThread::isRunning())
    {
        pauseFlag = true;
    }
}

void libFFmpegByQt::CameraThread::resume()
{
    if (QThread::isRunning())
    {
        pauseFlag = false;
        condition.wakeAll();
    }
}

void libFFmpegByQt::CameraThread::run()
{
    //qDebug() << "enter thread : " << QThread::currentThreadId();
    while (!stopFlag)
    {

        loop(); // do something...

        if (pauseFlag)
        {
            mutex.lock();
            condition.wait(&mutex);
            mutex.unlock();
        }
    }
    pauseFlag = false;
    stopFlag = false;

    //qDebug() << "exit thread : " << QThread::currentThreadId();
}


