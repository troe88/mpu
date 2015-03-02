#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>

class TestClass : public QObject
{
    Q_OBJECT
    int num_;
    bool s_;

public:
    explicit TestClass(int i, QObject *parent = 0);
    void stop();

    ~TestClass();

public slots:
    void run();

signals:
    void finished();
};

#endif // TESTCLASS_H
