#include "mainwindow.h"
#include "work1.h"
#include "work2.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_work1_clicked()
{
    work1* WorkWindow1 = new work1(this,"Hellow");
    WorkWindow1->show();

    connect(WorkWindow1,&work1::selection_return,this,&MainWindow::change_info_text);
}
void MainWindow::on_work2_clicked()
{
    work2* WorkWindow2 = new work2(this,"Hellow");
    WorkWindow2->show();

    connect(WorkWindow2,&work2::messageSent,this,&MainWindow::change_info_text);
}
void MainWindow::change_info_text(QString data)
{
    ui->label->setText(data);
}

