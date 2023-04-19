#ifndef FUNCS_FOR_SERVER_H
#define FUNCS_FOR_SERVER_H
#include <QObject>
#include <QString>


QByteArray parsing(QString data_from_client);

QByteArray auth(QString log, QString pass);

QByteArray reg(QString log, QString pass, QString mail);

QByteArray check_stat_by_stud();

QByteArray check_stat_by_teach();
#endif // FUNCS_FOR_SERVER_H
