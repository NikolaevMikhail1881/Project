#include "functions.h"
#include <QStringList>
#include <QDebug>

QByteArray parsing(QString data_from_client)
{
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc == "auth")
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));
    else if (nameOfFunc == "reg")
         return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
    else
        return "error";
}
QByteArray reg(QString log, QString pass, QString mail){
    return "reg";
}
QByteArray auth(QString log, QString pass){
    return "auth";
}
