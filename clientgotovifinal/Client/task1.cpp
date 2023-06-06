#include "task1.h"
#include "ui_task1.h"


task1::task1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task1)
{
    ui->setupUi(this);
}

task1::~task1()
{
    delete ui;
}

void task1::setTaskNumber(int n, QString _log)
{
    variant = generateVariant();
    log = _log;
    ui->label_variant->setText("Ваш вариант: " + variant);
    show();
}

void task1::on_send_answer_but_clicked()
{
    /*
    QString text = ui->lineEdit_answer->text();
    QString ans = solver_task1(variant);
    if(text == ans){
        check_ans(1, variant, "true", log);
    }else{
        check_ans(1, variant, "false", log);
    }
*/
    check_ans(1, variant, ui->lineEdit_answer->text(), log);
}

QString task1::generateVariant()
{

    QString variant = "";
    std::vector<int> cont = {1,2,3,4,5,6,7,8,9};
    while(variant.size()<9){
        for(int i = 9; i > 0; i--){
            srand(time(NULL));
            // Получить случайное число - формула
            int num = 0 + rand() % (i - 1 + 1);
            variant += QString::number(cont[num]);
            cont.erase(cont.begin() + num);
        }

    }
    qDebug()<<variant;
    return variant;
    close();
}


