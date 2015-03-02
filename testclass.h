#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>

class TestClass : public QObject
{
    Q_OBJECT
    int num_;
public:
    explicit TestClass(int i, QObject *parent = 0);
    ~TestClass();

public slots:
    void run();

signals:
    void finished();
};

#endif // TESTCLASS_H
