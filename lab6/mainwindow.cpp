#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qprocess.h>
#include <qthread.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushStart_clicked()
{

    if (object2_proc.state()==QProcess::Running){
        object2_proc.terminate();
        object2_proc.waitForFinished();
    }
    if (object3_proc.state()==QProcess::Running){
        object3_proc.terminate();
        object3_proc.waitForFinished();
    }

    QString Namount = ui->TextEditN->toPlainText();
    QString MinNum = ui->TextEditMin->toPlainText();
    QString MaxNum = ui->TextEditMax->toPlainText();
    arguments2.clear();
    arguments2 << Namount << MinNum << MaxNum;
    //ui->label->setText(arguments2[0]);

    if (object2_proc.state()==QProcess::NotRunning && object3_proc.state()==QProcess::NotRunning){
        object2_proc.start(program2,arguments2);
        //QThread::msleep(1000);
        object3_proc.start(program3,arguments3);
    }
}

