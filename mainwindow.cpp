#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread = new QThread;

    w1_ = new Worker1(QString("w1"));
    w1_->moveToThread(thread);

    connect(thread, SIGNAL(started()), w1_, SLOT(run()));
    connect(w1_, SIGNAL(finished()), thread, SLOT(quit()));
    connect(w1_, SIGNAL(finished()), w1_, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(w1_, SIGNAL(sendData(const QString &)), this->ui->worker1, SLOT(setText(const QString &)));
    thread->start();
}

void MainWindow::closeEvent(QCloseEvent *event){
    w1_->stop();
    thread->wait();
    event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}
