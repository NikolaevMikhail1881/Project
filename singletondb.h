#ifndef DATABASESINGLETON_H
#define DATABASESINGLETON_H

#include <QSqlDatabase>

class DatabaseSingleton
{
public:
    static DatabaseSingleton& instance();
    QSqlDatabase getDatabase() const;

private:
    DatabaseSingleton();
    ~DatabaseSingleton();
    DatabaseSingleton(const DatabaseSingleton&) = delete;
    DatabaseSingleton& operator=(const DatabaseSingleton&) = delete;

    QSqlDatabase m_database;
};

#endif // DATABASESINGLETON_H
