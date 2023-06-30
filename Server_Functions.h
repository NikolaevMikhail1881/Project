#ifndef SERVER_FUNCTIONS_H
#define SERVER_FUNCTIONS_H
#include <QStringList>
#include <QString>

/// \authors Mikhail_Nikolaev
/// \date 30.06.2023
/// \version 1.0.0
/// \brief parsing функция для реализации парсинга запросов

// функция обработки запроса сервером
QByteArray parsing(QString main_data_from_client, long long id_descriptor);  // парсинг данных, введенных пользователем

#endif // SERVER_FUNCTIONS_H
