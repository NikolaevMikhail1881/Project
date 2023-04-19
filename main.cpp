#include <QCoreApplication>
#include "singletondb.h"
#include "functions.h"
#include "mytcpserver.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); // создает консольное приложение с именем а с параметрами argc и argv
    MyTcpServer myserv;
    QSqlDatabase db = DatabaseSingleton::instance().getDatabase();

    // Создаём таблицу пользователей, если она не существует
    QSqlQuery query(db);
    if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT UNIQUE, password TEXT)")) {
        qDebug() << "Ошибка создания таблицы пользователей:" << query.lastError().text();
    }
    return a.exec();
}
