#include "functioforserver.h"
#include <QDebug>



QByteArray reg(QString log, QString pass,QString mail, QString role)
{
    return Db::getInstance()->reg(log,pass,mail, role);
}


QByteArray auth(QString log, QString pass,int desc)
{
    return Db::getInstance()->auth(log,pass,desc);
}

QByteArray check_ans(QString task_number,QString variant, QString ans, QString log){
    bool res = false;
    if(task_number=="1")
    {
        res = (ans==solver_task1(variant));
    }
    else if(task_number=="2")
    {
        res = (ans == solver_task2(variant));
    }
    if(res)
        ans = "true";
    return Db::getInstance()->check_ans(task_number, variant, ans, log);
}

QByteArray count_stat(QString log){
    return Db::getInstance()->count_stat(log);
}
QByteArray count_stat1(QString log){
    return Db::getInstance()->count_stat1(log);
}
QByteArray count_stat2(QString log){
    return Db::getInstance()->count_stat2(log);
}
QByteArray count_stat3(QString log){
    return Db::getInstance()->count_stat3(log);
}

QByteArray check_role(QString log){
    return Db::getInstance()->check_role(log);
}


void del(int desc)
{
    Db::getInstance()->del_status(desc);
}

QByteArray parsing (QString data_from_client,int desc)
{
    if(data_from_client.contains('&'))
    {

        QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
        qDebug() << data_from_client_list;
        QString log, pass, mail, role;
        QString variant, text, task_number;

        if(data_from_client_list.front() == "reg")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            data_from_client_list.pop_front();
            mail = data_from_client_list.front();
            data_from_client_list.pop_front();
            role = data_from_client_list.front();
            return reg(log, pass,mail, role);
        }
        if(data_from_client_list.front() == "auth")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return auth(log, pass, desc);
        }
        if(data_from_client_list.front() == "check")
        {
            data_from_client_list.pop_front();
            task_number = data_from_client_list.front();
            data_from_client_list.pop_front();
            variant = data_from_client_list.front();
            data_from_client_list.pop_front();
            text = data_from_client_list.front();
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            qDebug() << "Debug";
            return check_ans(task_number, variant, text, log);
        }
        if(data_from_client_list.front() == "stat")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat(log);
        }
        if(data_from_client_list.front() == "stat1")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat1(log);
        }
        if(data_from_client_list.front() == "stat2")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat2(log);
        }
        if(data_from_client_list.front() == "stat3")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return count_stat3(log);
        }
        if(data_from_client_list.front() == "role")
        {
            qDebug() << data_from_client;
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            return check_role(log);
        }
    } else
    {
        return data_from_client.toUtf8();;
    }
}

QString solver_task1(QString var){
    qDebug()<<var;
    bool ok;
    long int vars = var.toLong(&ok);

    qDebug()<<vars;
    std::vector<int> tree = { (vars/10000000%10), (vars/100000000), (vars/10000000%10), (vars/1000%10), (vars/100000000), (vars/100%10), (vars/100000000), (vars/10%10), (vars/1000%10),(vars/10000%10), (vars/10000%10),(vars/100000%10), (vars/10000%10), (vars%10), (vars/10000%10), (vars/1000000%10) };
    std::list<int> ans;
    for(auto i : tree){
        qDebug()<<i;
    }
    while (tree.size() > 2) {
        for (int i = 1; i < 10; i++) {
            int count = 0;
            int min;
            for (int k = 0; k < tree.size(); k++) {
                if (i == tree[k]) {
                    count++;
                }
            }
            if (count == 1) {
                min = i;
                for (int s = 0; s < tree.size(); s++) {
                    if (min == tree[s]) {
                        if (s % 2 != 0) {
                            ans.push_back(tree[s - 1]);
                            tree.erase(tree.begin() + s);
                            tree.erase(tree.begin() + s - 1);
                        }
                        else {
                            ans.push_back(tree[s+1]);
                            tree.erase(tree.begin() + s);
                            tree.erase(tree.begin() + s + 1);
                        }
                    }
                }
                break;
            }
        }
    }

    QString res;
    for(auto i : ans){
        res += QString::number(i);
    }
    qDebug()<<res;
    return res;

}

QString solver_task2(QString ss)
{
    QString var = ss;
    qDebug() << var;
    int length = var[0].digitValue(); // макс кол-во вершин
    qDebug() << length;
    var = var.mid(1, var.size());
    QVector<QVector<bool>> matr(length, QVector<bool>(length));; // матрица
    qDebug() << matr;

    for (int i = 0; i < length; i++) { // заполняем матрицу нулями нулями
            for (int j = 0; j < length; j++)
            {
                matr[i][j] = 0;
            }
    }

    // создаем матрицу смежности
    int k = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < var.size(); i++) {

        if (var[i].isDigit() != 0 and k == 0) {
            a = var[i].digitValue();
            k += 1;
        }
        else if (var[i].isDigit() != 0 and k == 1) {
            b = var[i].digitValue();
            matr[a-1][b-1] = 1;
            matr[b-1][a-1] = 1;
            a = 0;
            b = 0;
            k = 0;
        }
    }

    // переводим вектор в строку
    QString res;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            res += QString::number(matr[i][j]);
        }
    }

    return res;
}
