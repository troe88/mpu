#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>

class Worker1 : public QObject
{
    Q_OBJECT
    int num_;
    bool s_;

public:
    explicit Worker1(int i, QObject *parent = 0);
    void stop();

    ~Worker1();

public slots:
    void run();

signals:
    void finished();
};

#endif // TESTCLASS_H
