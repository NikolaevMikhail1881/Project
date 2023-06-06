#include "task2.h"
#include "ui_task2.h"
#include "Random.hpp"
#include <QDebug>
#include <iostream>
#include <vector>
//#include "tree.h"
#include "client.h"
task2::task2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);
}

task2::~task2()
{
    delete ui;
}

void task2::setTaskNumber(int n, QString _log)
{
    task_number = n;
    log = _log;
    generate_variant();
    show();
}

void task2::generate_variant(){
    /*
    Генерация 7 случайных цифр в диапозоне (1 - 9)

    QString text = "";
    for (int i = 0; i < 7; i++){
        int a = Random::get(1, 9);
        text.append(QString::number(a));
        text.append(", ");
    }
    text.resize(text.size() - 2);
    ui->prufer->setText(text);*/
    QString res = "";
    QSet<QString> edges;
    int length = Random::get(2, 9); // Вершины
    int kolvo_reber = Random::get(2, 5) % ((length * (length - 1)) / 2) + 1; // количество ребер
    qDebug() << length << ' ' << kolvo_reber;
    while (edges.size() < kolvo_reber) {
        int vertex1 = Random::get(1, 9) % length+1;
        int vertex2 = Random::get(1, 9) % length+1;

        if (vertex1 < vertex2) {
            edges.insert('(' + QString::number(vertex1) + ',' + QString::number(vertex2) + ')');
        }
        else if (vertex2 < vertex1) {
            edges.insert('(' + QString::number(vertex2) + ',' + QString::number(vertex1) + ')');
        }
    }

    for (auto it = edges.begin(); it != edges.end(); it++) {
        res.append(*it);
        res.append(",");
    }
    res = res.mid(0, res.size() - 1);
    res = QString::number(length) + res;
    ui->prufer->setText(res);
}

bool task2::on_button_decode_clicked(){
    QString ss = ui->prufer->text(); //Получаем строку
    qDebug() << ss;
    QString v1 = ui->lineEdit1->text();
    QString a = check_ans(task_number, ss, v1, log);
    qDebug() << a;
    if (a == "true"){
        ui->result->setText("Всё верно!");
    }
    else{
        ui->result->setText("Неправильно!");
    }
    return true;

}

