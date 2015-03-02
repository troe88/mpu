#include "mythread.h"

MyThread::MyThread()
{
    stopped = false;
}

void Thread::run()
{
    while (!stopped)
        cerr << messageStr.ascii();
    stopped = false;
    cerr << endl;
}

void Thread::stop()
{
    stopped = true;
}


MyThread::~MyThread()
{

}

