#ifndef W1_H
#define W1_H

#include "brigadier.h"

class Worker1 : public Brigadier
{
    Q_OBJECT

public:
    void stop()Q_DECL_OVERRIDE;

public slots:
    void run()Q_DECL_OVERRIDE;

public:
    explicit Worker1(QString name, QObject *parent = 0);
    ~Worker1();
};

#endif // W1_H
