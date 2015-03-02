#ifndef MYTHREAD_H
#define MYTHREAD_H


class MyThread : public QThread
{
public:
    MyThread();
    void setMessage(const QString &message);
    void run();
    void stop();

private:
    QString messageStr;
    volatile bool stopped;

public:
    ~MyThread();
};

#endif // MYTHREAD_H
