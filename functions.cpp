/**
 * @file functions.cpp
 * @brief Описание функций сервера
 */
#include "functions.h"
#include "mytcpserver.h"

/**
 * @brief Получает данные от клиента и выполняет соответствующее действие.
 *
 * @param data_from_client QString, представляющий данные, полученные от клиента.
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий результат выполненного действия или сообщение об ошибке.
 */
QByteArray parsing(QString data_from_client, int sock_desc){
    QString login;
    data_from_client = data_from_client.left(data_from_client.length()-2);
    qDebug() << data_from_client;

    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    qDebug()<<data_from_client_list.front();

    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();

    if (nameOfFunc == "auth"){
        change_sock_desc(data_from_client_list.at(0), sock_desc);
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));
    }
    else if (nameOfFunc == "reg"){
        QString log =data_from_client_list.at(0);
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2), sock_desc);
        change_sock_desc(data_from_client_list.at(0), sock_desc);
    }else if (nameOfFunc == "updstat") {
        qDebug()<<login;
        return check_ans(data_from_client_list.at(0), data_from_client_list.at(1), sock_desc);}
    else if (nameOfFunc == "stat")
    {
        qDebug()<<"stat" + data_from_client_list.at(0);
        return look_stat(sock_desc);
    }
    else if (nameOfFunc == "stat1")
    {
        qDebug()<<"stat" + data_from_client_list.at(0);
        return look_stat1(sock_desc);
    }
    else if (nameOfFunc == "stat2")
    {
        qDebug()<<"stat" + data_from_client_list.at(0);
        return look_stat2(sock_desc);
    }
    else if (nameOfFunc == "stat3")
    {
        qDebug()<<"stat" + data_from_client_list.at(0);
        return look_stat3(sock_desc);
    }
    else if (nameOfFunc == "del")
    {
        qDebug()<<"stat" + data_from_client_list.at(0);
        return del_status(sock_desc);
    }
    else return "error\r\n";
}

/**
 * @brief Аутентифицирует пользователя с заданными учетными данными.
 *
 * @param log Имя пользователя.
 * @param pass Пароль пользователя.
 *
 * @return QByteArray, содержащий результат аутентификации.
 */
QByteArray auth(QString log, QString pass)
{

    QByteArray result = "";
    result.append(Database::getInstance()->auth(log, pass));
    qDebug() << result;
    return result;
}

/**
 * @brief Регистрирует нового пользователя в базе данных.
 *
 * @param log QString, обозначающий логин пользователя.
 * @param pass QString, обозначающий пароль пользователя.
 * @param mail QString, обозначающий электронную почту пользователя.
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий результат операции регистрации.
 */
QByteArray reg(QString log, QString pass, QString mail, int sock_desc)
{
    QByteArray result = "";
    result.append(Database::getInstance()->reg(log, pass, mail, sock_desc));
    qDebug() << result;
    change_sock_desc(log, sock_desc);
    return result;
}

/**
 * @brief Проверяет ответ пользователя в базе данных.
 *
 * @param numb QString, представляющий номер связанный с пользователем.
 * @param ans QString, представляющий проверяемый ответ.
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий результат операции проверки ответа.
 */
QByteArray check_ans(QString numb, QString ans, int sock_desc)
{
    QByteArray res;

    res.append(Database::getInstance()->check_ans(numb, ans, sock_desc));
    qDebug()<<res;
    return res;
}

/**
 * @brief Получает статистику первого пользователя из базы данных.
 *
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий статистику.
 */
QByteArray look_stat(int sock_desc)
{
    QByteArray result;
    result.append(Database::getInstance()->count_stat(sock_desc).toInt());
    qDebug()<<result;
    return result;
}
/**
 * @brief Получает статистику второго пользователя из базы данных.
 *
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий статистику.
 */
QByteArray look_stat1(int sock_desc)
{
    QByteArray result;
    result.append(Database::getInstance()->count_stat1(sock_desc).toInt());
    qDebug()<<result;
    return result;
}
/**
 * @brief Получает статистику третьего пользователя из базы данных.
 *
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий статистику.
 */
QByteArray look_stat2(int sock_desc)
{
    QByteArray result;
    result.append(Database::getInstance()->count_stat2(sock_desc).toInt());
    qDebug()<<result;
    return result;
}
/**
 * @brief Получает статистику четвертого пользователя из базы данных.
 *
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий статистику.
 */
QByteArray look_stat3(int sock_desc)
{
    QByteArray result;
    result.append(Database::getInstance()->count_stat3(sock_desc).toInt());
    qDebug()<<result;
    return result;
}
/**
 * @brief Изменение статуса пользователя в базе данных.
 *
 * @param login QString, представляющий логин пользователя.
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий результат операции изменения статуса.
 */
QByteArray change_sock_desc(QString login, int sock_desc)
{
    QByteArray result;
    result.append(Database::getInstance()->change_status(login, sock_desc));
    qDebug()<<result;
    return result;
}

/**
 * @brief Удаляет статус пользователя в базе данных.
 *
 * @param sock_desc Целое число, представляющее дескриптор сокета.
 *
 * @return QByteArray, содержащий результат операции удаления статуса.
 */
QByteArray del_status(int sock_desc)
{
    QByteArray result;
    result.append(Database::getInstance()->del_status(sock_desc));
    return result;
}
