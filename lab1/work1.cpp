#include "work1.h"
#include "ui_work1.h"

work1::work1(QWidget *parent, QString message)
    : QDialog(parent)
    , ui(new Ui::work1)
{
    ui->setupUi(this);

    connect(this,&work1::accepted,this,[this](){
        QString group = "";
        if (ui->listWidget->currentItem()!=nullptr){
            group = "Вивід з work1: " + ui->listWidget->currentItem()->text();
        }
        if(group!=""){
            emit selection_return(group);
        } else{
            emit selection_return("У work1 нічого не вибрано.");
        }

    });
}

work1::~work1()
{
    delete ui;
}
