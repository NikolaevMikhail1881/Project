#include "functions.h"

QByteArray parsing(QString data_from_client, int sock_desc){
    QString login;
    data_from_client = data_from_client.left(data_from_client.length()-2);
    qDebug() << data_from_client;

    QStringList data_from_client_list = data_from_client.split(QLatin1Char(' '));
    qDebug()<<data_from_client_list.front();

    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();

    if (nameOfFunc == "auth"){
        change_sock_desc(data_from_client_list.at(0), sock_desc);
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));
    }
    else return "error\r\n";
}

