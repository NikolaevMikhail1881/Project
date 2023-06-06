#ifndef FUNCTIOFORSERVER_H
#define FUNCTIOFORSERVER_H

#include <QStringList>
#include <QString>
#include <QMap>
#include <QDebug>
#include "db.h"

QByteArray parsing (QString data_from_client, int desc);

QByteArray auth(QString log, QString pass);
QByteArray reg(QString log, QString pass);
QString solver_task1(QString var);
QString solver_task2(QString ss);
#endif // FUNCTIOFORSERVER_H
