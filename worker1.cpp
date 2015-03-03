#include "worker1.h"
#include <QThread>

Worker1::Worker1(QString name, QObject *parent) : QObject(parent)
{
    name_ = name;
    s_ = false;
}


Worker1::~Worker1()
{

}

