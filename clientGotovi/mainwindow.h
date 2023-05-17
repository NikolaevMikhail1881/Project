#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "formauth.h"
#include "formtask.h"
#include "functionsforclient.h"
#include "client.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopServices>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FormAuth *ui_auth;
    FormTask *ui_task;
private slots:
    void slot_show(QString log);
    void on_pushButton_task1_clicked();
    void on_pushButton_task2_clicked();
    void on_pushButton_task3_clicked();
    void on_actionTask_1_triggered();
    void on_actionTask_2_triggered();
    void on_actionTask_3_triggered();
    void on_pushButton_exit_clicked();
    void on_pushButton_stat_clicked();

    void on_actionOur_project_triggered();
    void on_actionExit_triggered();
    void on_actionDevelopers_triggered();
    void on_actionOur_website_triggered();
};
#endif // MAINWINDOW_H
