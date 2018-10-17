#include "aaa.h"
#include <QMutexLocker>
#include <QDebug>
#include "thread.h"

AAA::AAA(QObject *parent) :
    QObject(parent),
    m_Exit(false)
{
}

AAA::~AAA()
{
    qDebug() << "~AAA()";
}

bool AAA::isExit()
{
    QMutexLocker locker(&m_Mutex);
    return m_Exit;
}

void AAA::setExit(bool v)
{
    QMutexLocker locker(&m_Mutex);
    m_Exit = v;
}

void AAA::onRun()
{
    while (1)
    {
        if (isExit())
        {
            qDebug() << "Safe exit AAA";

            break;
        }

        qDebug() << "AAA";

        Thread::sleepEx(1);
    }
}
