#include "object2.h"
#include "./ui_object2.h"
#include <QClipboard>
#include <qthread.h>
#include <random>

Object2::Object2(QWidget *parent): QMainWindow(parent), ui(new Ui::Object2)
{
    ui->setupUi(this);
}

Object2::~Object2()
{
    delete ui;
}

void Object2::logic(int N, int Min, int Max){
    std::uniform_real_distribution<double> unif(Min, Max);
    std::default_random_engine re;
    //std::vector<double> val_vector(N);
    QString all_nums;
    QClipboard *clipboard = QApplication::clipboard();

    for (int i = 0; i < N; i++){
        double ran_val = unif(re);
        ui->listWidget->addItem(QString("Value: ") + QString::number(ran_val,'f',2));
        all_nums.append(QString::number(ran_val,'f',2)+QString(" "));
        //val_vector[i] = ran_val;
    }

    //setWindowTitle(all_nums);
    clipboard->setText(all_nums,QClipboard::Clipboard); //QClipboard::Clipboard or Selection
    QThread::msleep(1);
}