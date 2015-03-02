#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QDebug>
#include "worker1.h"
#include <QThread>
#include <QtConcurrent/QtConcurrent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Worker1* tc;
    QThread* thread;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);

public slots:
    void showMSG() { qDebug() << "msg"; }
};

#endif // MAINWINDOW_H
