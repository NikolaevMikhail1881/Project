#ifndef TASK1_H
#define TASK1_H


#include <QWidget>
#include "functionsforclient.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>
#include <list>
#include <random>
#include <QWidget>
#include <QTcpServer>

namespace Ui {
class task1;
}

class task1 : public QWidget
{
    Q_OBJECT

public:
    explicit task1(QWidget *parent = nullptr);
    ~task1();
    void setTaskNumber(int n, QString _log);


private slots:
    void on_send_answer_but_clicked();

private:
    Ui::task1 *ui;
    int task_number;
    QString variant;
    QString log;
    //Ui::MainWindow *main_ui;
    QString generateVariant();


};


#endif // TASK1_H
