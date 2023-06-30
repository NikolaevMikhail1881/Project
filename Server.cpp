#include "Server.h"
#include <QDebug>
#include <QCoreApplication>
#include "Server_Functions.h"

// деактивация сервера
Server::~Server()
{
    Server->close();
    server_status=0;
}

// активация сервера
Server::Server(QObject *parent) : QObject(parent){
    Server = new QTcpServer(this);
    connect(Server, &QTcpServer::newConnection,
            this, &Server::slotClientConnected);

    if(!Server->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

// новое подключение пользователя
void Server::slotClientConnected(){
    if(server_status == 1){
        Socket=Server->nextPendingConnection();  // создание нового подключения
        connect(Socket, &QTcpSocket::readyRead,this,&Server::slotServerRead);  // создание режима чтения
        connect(Socket,&QTcpSocket::disconnected,this,&Server::slotClientDisconnected);  // создание режима отключения

        // вывод текста-приветствия
        Socket->write("Hello, user!!! You have opened the  server!\r\nPlease, write you command >>> ");

        multiple_sockets.push_back(Socket);
        qDebug() << "new client connected";  // вывод отчета об успешном подключении

    }
}

// чтение пользовательских данных
void Server::slotServerRead(){
    result_Server_Read = "";  // обнуление переменной в которую записывается результат считывания
    Socket = (QTcpSocket*)sender();  // работа с последним активным сокетом
    long long id_descriptor = Socket->socketDescriptor();
    while(Socket->bytesAvailable()>0)
    {
        read_array = Socket->readAll();  // считывание
        result_Server_Read.append(read_array);  // занесение в данных результирующий массив
        Socket->write(parsing(result_Server_Read.toUtf8(), id_descriptor));  // обработка считанных данных с предварительной конвертацией в Utf8
    }

}

// отключение пользователя
void Server::slotClientDisconnected(){
    Socket = (QTcpSocket*)sender();  // работа с последним активным сокетом
    //qDebug() << Socket->socketDescriptor();
    Socket->close();  // закрытие сокета
    qDebug() << "new client disconnected";  // вывод отчета об успешном отключении
}
