#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

/// \authors Mikhail_Nikolaev
/// \date 30.06.2023
/// \version 1.0.0
/// \brief slotClientConnected метод, отвечающий за обработку подключения нового пользователя
/// \brief slotSlientDisconnected метод, отвечающий за обработку отключения нового пользователя
/// \brief slotServerRead метод отвечающий за чтение команд из консоли

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
public slots:
    void slotClientConnected();
    void slotClientDisconnected();

    void slotServerRead();


private:
    QVector<QTcpSocket*> multiple_sockets;  // массив сокетов
    QTcpServer * Server;  // сервер
    QTcpSocket * Socket;  // сокет
    int server_status;  // статус сервера

    // переменные для работы с чтением на сервере
    QByteArray read_array;  // массив для считывания
    QString result_Server_Read;  // результат чтения сервера
};
#endif // _SERVER_H







