#include "brigadier.h"
#include <QThread>

Brigadier::Brigadier(QString name, QObject *parent) : QObject(parent)
{
    name_ = name;
    s_ = false;
}


Brigadier::~Brigadier()
{

}

