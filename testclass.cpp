#include "testclass.h"

TestClass::TestClass(int i, QObject *parent) : QObject(parent)
{
    num_ = i;
}

void TestClass::run() {
    for (int i=0; i< 115000; ++i) {
        qDebug() << "from ";
    }
    emit finished();
}

TestClass::~TestClass()
{

}

