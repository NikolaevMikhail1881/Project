#include "functions.h"
#include "usercheck.h"
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
        return "error\n";
}
QByteArray reg(QString log, QString pass, QString mail)
{
    bool registrationSuccess = registerUser(log, pass);
    if (registrationSuccess) {
        return "reg_success\n";
    } else {
        return "reg_failed\n";
    }
}

QByteArray auth(QString log, QString pass)
{
    bool authorizationSuccess = authorizeUser(log, pass);
    if (authorizationSuccess) {
        return "auth_success\n";
    } else {
        return "auth_failed\n";
    }
}
