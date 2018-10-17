#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
class AAA;
class BBB;
class Thread;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    void initialize();
    void cleanup();

signals:

private slots:
    void timeout();

private:
    Ui::MainWidget *ui;
    AAA *a;
    BBB *b;
    Thread *ta;
    Thread *tb;
};

#endif // MAINWIDGET_H
