#ifndef WORKER2_H
#define WORKER2_H

#include "brigadier.h"

class Worker2 : public Brigadier
{
    Q_OBJECT

public:
    void stop()Q_DECL_OVERRIDE;

public slots:
    void run()Q_DECL_OVERRIDE;

public:
    explicit Worker2(QString name, QObject *parent = 0);
    ~Worker2();
};


#endif // WORKER2_H
