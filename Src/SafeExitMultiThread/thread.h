#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
public:
    explicit Thread(QObject *parent = 0);
    ~Thread();

    static void sleepEx(unsigned long s);
};

#endif // THREAD_H
