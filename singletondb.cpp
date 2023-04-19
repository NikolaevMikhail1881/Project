#include "singletondb.h"
#include <QCoreApplication>
#include <QSqlError>
#include <QDebug>

DatabaseSingleton& DatabaseSingleton::instance()
{
    static DatabaseSingleton instance;
    return instance;
}

QSqlDatabase DatabaseSingleton::getDatabase() const
{
    return m_database;
}

DatabaseSingleton::DatabaseSingleton()
{
    // Устанавливаем тип базы данных и имя подключения
    m_database = QSqlDatabase::addDatabase("QSQLITE", "dbconnect");

    // Устанавливаем путь к файлу базы данных
    QString dbPath = QCoreApplication::applicationDirPath() + "/db.sqlite";
    m_database.setDatabaseName(dbPath);

    // Открываем базу данных
    if (!m_database.open()) {
        qCritical() << "Невозможно открыть базу данных:" << m_database.lastError().text();
    }
}

DatabaseSingleton::~DatabaseSingleton()
{
    m_database.close();
    QSqlDatabase::removeDatabase("dbconnect");
}
