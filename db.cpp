#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>


QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
db.setHostName("localhost");
db.setDatabaseName("postrges");
db.setUserName("username");
db.setPassword("password");

if (!db.open()) // Проверка соединения
{
    qDebug() << db.lastError().text(); // Текст ошибки
}else
{
    qDebug() << "Database connection established successfully!"; // успешное соединение
}

QSqlQuery query; // выделение всего стола
query.exec("SELECT * FROM table_name");

while (query.next()) // создание очереди 
{
    QString id = query.value(0).toString(); 
    QString name = query.value(1).toString();
}