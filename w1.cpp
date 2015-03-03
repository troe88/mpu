#include "w1.h"
#include <QThread>
#include <QMutex>

w1::w1(QString name, QObject *parent) : Worker1(name, parent)
{

}


void w1::run(){
    int i = 0;
    while (!s_) {
        this->thread()->msleep(1);
        i++;
        sendData(QString::number(i) + "\n");
    }
    qDebug() << "stop: " << name_;
}

void w1::stop(){
    mutex_.lock();
    s_ = true;
    mutex_.unlock();

    emit finished();
}

w1::~w1(){

}
