#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "testclass.h"
#include <QThread>
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QThread* thread = new QThread;
    TestClass* tc = new TestClass(1);
    tc->moveToThread(thread);

    connect(thread, SIGNAL(started()), tc, SLOT(run()));

    // По завершению выходим из потока, и удаляем рабочий класс
    connect(tc, SIGNAL(finished()), thread, SLOT(quit()));
    connect(tc, SIGNAL(finished()), tc, SLOT(deleteLater()));

    // Удаляем поток, после выполнения операции
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), this, SLOT(showMSG()));

    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
