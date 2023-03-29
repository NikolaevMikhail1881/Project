#ifndef MYTCPSERVER_H // нужно для того чтобы сервер объявлялся один раз
#define MYTCPSERVER_H // нужно для того чтобы сервер объявлялся один раз
#include <QObject> // класс вокруг которого построена объектная модель Qt. Без него не сможем включать классические вещи из консольных приложений
#include <QTcpServer> // для сервера
#include <QTcpSocket> // для соединения используем сокет

#include <QtNetwork> // для работы по сети
#include <QByteArray> // для передачи сообщений по сети
#include <QDebug>  // для вывода в консоль сообщений
#include <QMap> // для подключения контейнера map

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr); // конструктор, где ключевое слово explicit не дает использовать конструктора неявное преобразование типов
    ~MyTcpServer(); // деструктор
public slots: // когда приходит запрос на подключение запускает последовательность поераций которые необходимо сделать при подключении нового клиента
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
private:
    QTcpServer * mTcpServer; // свойство объекта которое будет самим сервером
    QMap <int, QTcpSocket*> mTcpSocket; // отвечает за подключение; будем хранить сокеты с их id
    int server_status; // для отладки
};
#endif // MYTCPSERVER_H

