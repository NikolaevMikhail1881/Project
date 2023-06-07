#include "mytcpserver-ex.h"
#

using namespace std;

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket *cur_mTcpSocket;
        cur_mTcpSocket = mTcpServer->nextPendingConnection();
        cur_mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(cur_mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(cur_mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
        mTcpSocket.insert(cur_mTcpSocket->socketDescriptor(),cur_mTcpSocket);
    }
}

void MyTcpServer::heapify(QVector<int>& arr, int n, int i, QVector<QVector<int>>& steps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        qSwap(arr[i], arr[largest]);
        steps.push_back(arr);
        heapify(arr, n, largest, steps);
    }
}

QVector<QVector<int>> MyTcpServer::heapSort(QVector<int>& arr, int n, int step) {
    QVector<QVector<int>> steps;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, steps);

    for (int i = n - 1; i >= 0; i--) {
        qSwap(arr[0], arr[i]);
        steps.push_back(arr);
        heapify(arr, i, 0, steps);
    }
    return steps;
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *cur_mTcpSocket = (QTcpSocket*)sender();
    QString res = "";
    while(cur_mTcpSocket->bytesAvailable()>0){
        QByteArray array=cur_mTcpSocket->readAll();
        res.append(array);
    }

    QStringList msg_parts = res.split("&");
    if (msg_parts.size() == 3 && msg_parts[0] == "sort") {
        int step = msg_parts[1].toInt();
        QVector<int> array;
        foreach (const QString &str, msg_parts[2].split(" ")) {
            array.append(str.toInt());
        }
        QVector<QVector<int>> sortedArrays = heapSort(array, array.size(), step);
        int currentStep = 0;
        for (auto sortedArray : sortedArrays) {
            QByteArray result;
            result.append("sort&" + QString::number(currentStep).toUtf8() + "&");
            for (int num : sortedArray) {
                result.append(QString::number(num).toUtf8() + " ");
            }
            cur_mTcpSocket->write(result + "\r\n");
            currentStep++;
        }
    } else {
        cur_mTcpSocket->write("Invalid message format\r\n");
    }
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *cur_mTcpSocket = (QTcpSocket*)sender();
    cur_mTcpSocket->close();
}
