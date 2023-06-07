#ifndef UNITTEST_H
#define UNITTEST_H

#include <QtTest/QTest>
#include "mytcpserver-ex.h"

class TestMyTcpServer : public QObject
{
    Q_OBJECT

public:
    TestMyTcpServer() {}
    ~TestMyTcpServer() {}

private slots:
    void test_heapSort();

private:
    MyTcpServer server;
};

#endif // UNITTEST_H
