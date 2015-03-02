#include "worker1.h"
#include <QThread>

Worker1::Worker1(int i, QObject *parent) : QObject(parent)
{
    num_ = i;
    s_ = false;
}

void Worker1::run() {
    while (!s_) {
        qDebug() << "from: " << num_;
    }
}

void Worker1::stop(){
    s_ = true;
    emit finished();
}


Worker1::~Worker1()
{

}

