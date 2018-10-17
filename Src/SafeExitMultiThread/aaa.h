#ifndef AAA_H
#define AAA_H

#include <QObject>
#include <QMutex>

class AAA : public QObject
{
    Q_OBJECT
public:
    explicit AAA(QObject *parent = 0);
    ~AAA();

    bool isExit();
    void setExit(bool v);

signals:

public slots:
    void onRun();

private:
    bool m_Exit;
    QMutex m_Mutex;
};

#endif // AAA_H
