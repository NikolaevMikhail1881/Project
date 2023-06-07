#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>




class MyTcpServer : public QObject
{
    Q_OBJECT
public:

    explicit MyTcpServer(QObject *parent = nullptr);

    ~MyTcpServer();
public slots:

    void slotNewConnection();

    void slotClientDisconnected();

    void slotServerRead();
    QVector<QVector<int>> heapSort(QVector<int>& arr, int n, int step);
private:
    void heapify(QVector<int>& arr, int n, int i, QVector<QVector<int>>& steps);


    QTcpServer * mTcpServer;

    QMap <int, QTcpSocket*> mTcpSocket;

    int server_status;
};
#endif
