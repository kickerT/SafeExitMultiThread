#ifndef BBB_H
#define BBB_H

#include <QObject>
#include <QMutex>

class BBB : public QObject
{
    Q_OBJECT
public:
    explicit BBB(QObject *parent = 0);
    ~BBB();

    bool isExit();
    void setExit(bool v);

signals:

public slots:
    void onRun();

private:
    bool m_Exit;
    QMutex m_Mutex;
};

#endif // BBB_H
