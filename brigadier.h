#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QMutex>

class Brigadier : public QObject
{
    Q_OBJECT

protected:
    bool s_;
    QString name_;
    QMutex  mutex_;
    virtual void stop() = 0;

protected:
    explicit Brigadier(QString name, QObject *parent = 0);
    ~Brigadier();

protected slots:
    virtual void run() = 0;

signals:
    void finished();
    void sendData(const QString & text);
};

#endif // TESTCLASS_H
