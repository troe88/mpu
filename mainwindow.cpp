#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread1_ = new QThread;
    thread2_ = new QThread;

    w1_ = new Worker1(QString("w1"));
    w1_->moveToThread(thread1_);

    w2_ = new Worker2(QString("w2"));
    w2_->moveToThread(thread2_);

    connect(thread1_, SIGNAL(started()), w1_, SLOT(run()));
    connect(w1_, SIGNAL(finished()), thread1_, SLOT(quit()));
    connect(w1_, SIGNAL(finished()), w1_, SLOT(deleteLater()));
    connect(thread1_, SIGNAL(finished()), thread1_, SLOT(deleteLater()));
    connect(w1_, SIGNAL(sendData(const QString &)), this->ui->worker1, SLOT(setText(const QString &)));
    thread1_->start();

    connect(thread2_, SIGNAL(started()), w2_, SLOT(run()));
    connect(w2_, SIGNAL(finished()), thread2_, SLOT(quit()));
    connect(w2_, SIGNAL(finished()), w2_, SLOT(deleteLater()));
    connect(thread2_, SIGNAL(finished()), thread2_, SLOT(deleteLater()));
    connect(w2_, SIGNAL(sendData(const QString &)), this->ui->worker2, SLOT(setText(const QString &)));
    thread2_->start();
}

void MainWindow::closeEvent(QCloseEvent *event){
    w1_->stop();
    thread1_->wait();

    w2_->stop();
    thread2_->wait();

    event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}
