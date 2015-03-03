#include "worker1.h"
#include <QThread>
#include <QMutex>

Worker1::Worker1(QString name, QObject *parent) : Brigadier(name, parent)
{

}


void Worker1::run(){
    int i = 0;
    while (!s_) {
        this->thread()->msleep(1);
        i++;
        sendData(QString::number(i) + "\n");
        sendData(QString("Test\n"));
    }
    qDebug() << "stop: " << name_;
}

void Worker1::stop(){
    mutex_.lock();
    s_ = true;
    mutex_.unlock();

    emit finished();
}

Worker1::~Worker1(){

}
