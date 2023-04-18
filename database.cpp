#pragma once
#include "database.h"
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
Database::Database()
{
    initDB();
}

void Database::initDB() {
    this->dbInstance = QSqlDatabase::addDatabase("QSQLITE");
    this->dbInstance.setDatabaseName("SQLite.sql");
    if (!this->dbInstance.open()) {
        qDebug() << this->dbInstance.lastError().text();
    }
    QSqlQuery query(this->dbInstance);
    query.exec("CREATE TABLE Users (login VARCHAR (255) UNIQUE PRIMARY KEY NOT NULL, password VARCHAR (255) NOT NULL, token VARCHAR (255) NOT NULL UNIQUE)");
};

Database::~Database() {
    this->dbInstance.close();
};

QSqlQuery Database::doSQLQuery(QString stringQuery) {
    //qDebug().noquote() << stringQuery;
    QSqlQuery query(this->dbInstance);
    bool status = query.exec(stringQuery);
    qDebug().noquote() << QString("Query %1, status %2").arg(stringQuery).arg(status);
    if (!status) {
      this->dbInstance.rollback();
    }
    else {
        this->dbInstance.commit();
    }
    return query;
}

Database* Database::pInstance = nullptr;
QSqlDatabase Database::dbInstance;
DatabaseDestroyer Database::destroyer;
