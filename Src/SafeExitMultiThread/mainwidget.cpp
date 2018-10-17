#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QTimer>
#include <QDebug>
#include "aaa.h"
#include "bbb.h"
#include "thread.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    a(NULL),
    b(NULL),
    ta(NULL),
    tb(NULL)
{
    ui->setupUi(this);

    initialize();
}

MainWidget::~MainWidget()
{
    qDebug() << "~MainWidget()";

    cleanup();
    delete ui;
}

void MainWidget::initialize()
{
    a = new AAA;
    b = new BBB;
    ta = new Thread(this);
    tb = new Thread(this);
    a->moveToThread(ta);
    b->moveToThread(tb);
    connect(ta, SIGNAL(started()), a, SLOT(onRun()));
    connect(tb, SIGNAL(started()), b, SLOT(onRun()));
    ta->start();
    tb->start();

    QTimer::singleShot(1000, this, SLOT(timeout()));
}

void MainWidget::cleanup()
{
    a->setExit(true);
    ta->quit();
    ta->wait();
    delete ta;
    delete a;

    b->setExit(true);
    tb->quit();
    tb->wait();
    delete tb;
    delete b;
}

void MainWidget::timeout()
{
    qDebug() << "timeout.";
    close();
}
