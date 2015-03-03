#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QMutex>

class Worker1 : public QObject
{
    Q_OBJECT
protected:
    bool s_;
    QString name_;
    QMutex  mutex_;
    virtual void stop() = 0;

protected slots:
    virtual void run() = 0;

public:
    explicit Worker1(QString name, QObject *parent = 0);
    ~Worker1();

signals:
    void finished();
    void sendData(const QString & text);
};

#endif // TESTCLASS_H
