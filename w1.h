#ifndef W1_H
#define W1_H

#include "worker1.h"

class w1 : public Worker1
{
    Q_OBJECT

public:
    void stop()Q_DECL_OVERRIDE;

public slots:
    void run()Q_DECL_OVERRIDE;

public:
    explicit w1(QString name, QObject *parent = 0);
    ~w1();
};

#endif // W1_H
