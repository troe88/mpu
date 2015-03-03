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

protected slots:
    virtual void run() = 0;

public:
    explicit Brigadier(QString name, QObject *parent = 0);
    ~Brigadier();

signals:
    void finished();
    void sendData(const QString & text);
};

#endif // TESTCLASS_H
