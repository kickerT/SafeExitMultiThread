#include "bbb.h"
#include <QMutexLocker>
#include <QDebug>
#include "thread.h"

BBB::BBB(QObject *parent) :
    QObject(parent),
    m_Exit(false)
{
}

BBB::~BBB()
{
    qDebug() << "~BBB()";
}

bool BBB::isExit()
{
    QMutexLocker locker(&m_Mutex);
    return m_Exit;
}

void BBB::setExit(bool v)
{
    QMutexLocker locker(&m_Mutex);
    m_Exit = v;
}

void BBB::onRun()
{
    while (1)
    {
        if (isExit())
        {
            qDebug() << "Safe exit BBB";

            break;
        }

        qDebug() << "BBB";

        Thread::sleepEx(1);
    }
}
