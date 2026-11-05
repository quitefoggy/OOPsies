#include "shapelist_window.h"
#include <qboxlayout.h>


ShapeList_window::ShapeList_window(QWidget *parent)
    : QDialog{parent}
{
    setWindowTitle("Non-Modal dialog");
    resize(640,480);

    QHBoxLayout *layout = new QHBoxLayout(this);
    Shapelist = new QListWidget(this);
    layout->addWidget(Shapelist);
    //layout->setSizePolicy(QSizePolicy::Expanding);
}

void ShapeList_window::AddShapeToList(QString data){
    Shapelist->addItem(data);
}

QString ShapeList_window::getShapeList(){
    int currentListSize = Shapelist->count();
    QString returning_data = "";

    for (int i = 0; i < currentListSize; i++){
        QString currentShape = Shapelist->item(i)->text().split(" ").join(",");
        returning_data = returning_data + currentShape + "\n";
    }

    return returning_data;
}
