#include "worker2.h"

#include <QThread>
#include <QMutex>

Worker2::Worker2(QString name, QObject *parent) : Brigadier(name, parent)
{

}


void Worker2::run(){
    int i = 0;
    while (!s_) {
        this->thread()->msleep(1);
        i++;
        sendData(QString::number(i) + "\n");
    }
    qDebug() << "stop: " << name_;
}

void Worker2::stop(){
    mutex_.lock();
    s_ = true;
    mutex_.unlock();

    emit finished();
}

Worker2::~Worker2(){

}


