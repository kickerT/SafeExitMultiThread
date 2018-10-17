#include "thread.h"

Thread::Thread(QObject *parent) :
    QThread(parent)
{

}

Thread::~Thread()
{

}

void Thread::sleepEx(unsigned long s)
{
    sleep(s);
}
