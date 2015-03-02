#include "testclass.h"
#include <QThread>

TestClass::TestClass(int i, QObject *parent) : QObject(parent)
{
    num_ = i;
    s_ = false;
}

void TestClass::run() {
    while (!s_) {
        qDebug() << "from: " << num_;
    }
}

void TestClass::stop(){
    s_ = true;
    emit finished();
}


TestClass::~TestClass()
{

}

