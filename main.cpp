#include <QCoreApplication>
#include "Server.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server Server;  // создание сервера
    return a.exec();
}
