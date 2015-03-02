#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread = new QThread;
    tc = new TestClass(1);
    tc->moveToThread(thread);

    connect(thread, SIGNAL(started()), tc, SLOT(run()));

    connect(tc, SIGNAL(finished()), thread, SLOT(quit()));
    connect(tc, SIGNAL(finished()), tc, SLOT(deleteLater()));

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), this, SLOT(showMSG()));

    thread->start();
}

void MainWindow::closeEvent(QCloseEvent *event){
    tc->stop();
    thread->wait();
    event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}
