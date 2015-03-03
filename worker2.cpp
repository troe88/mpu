#include "worker2.h"
#include <QThread>
#include <QMutex>
#include <QTime>

Worker2::Worker2(QString name, QObject *parent) : Brigadier(name, parent)
{

}


void Worker2::run(){
    QTime myTimer;
    myTimer.start();
    int s = myTimer.currentTime().msecsSinceStartOfDay();


    while (!s_) {
        this->thread()->msleep(1);
        int r = myTimer.currentTime().msecsSinceStartOfDay() - s;
        qDebug() << r;
        sendData(myTimer.fromMSecsSinceStartOfDay(r).toString() + "\n");
    }
    qDebug() << "stop: " << name_ ;
}

void Worker2::stop(){
    mutex_.lock();
    s_ = true;
    mutex_.unlock();

    emit finished();
}

Worker2::~Worker2(){

}


