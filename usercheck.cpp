#include "usercheck.h"
#include "singletondb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool registerUser(const QString& username, const QString& password)
{
    QSqlDatabase db = DatabaseSingleton::instance().getDatabase();

    // Проверяет, существует ли пользователь
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Ошибка при проверке наличия пользователя:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        qDebug() << "Пользователь уже существует";
        return false;
    }

    // Регистрация нового пользователя
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Ошибка регистрации пользователя:" << query.lastError().text();
        return false;
    }

    return true;
}

bool authorizeUser(const QString& username, const QString& password)
{
    QSqlDatabase db = DatabaseSingleton::instance().getDatabase();

    // Проверяет, существует ли пользователь и совпадает ли пароль
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Ошибка при проверке учетных данных пользователя:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        qDebug() << "Неверное имя пользователя или пароль";
        return false;
    }

    return true;
}
