#include "work2.h"
#include "ui_work2.h"

work2::work2(QWidget *parent, QString message)
    : QDialog(parent)
    , ui(new Ui::work2)
{
    ui->setupUi(this);

    connect(this, &work2::accepted,this,[this](){
        QString message = "Вивід з work2: ";
        if (ui->plainTextEdit->toPlainText() != ""){
            message = message + ui->plainTextEdit->toPlainText();
        } else{
            message = "У work2 не було даних.";
        }
        emit messageSent(message);
    });
}

work2::~work2()
{
    delete ui;
}
