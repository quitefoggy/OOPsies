#include <QtWidgets>
#include "shape.h"


void PointShape::Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter){
    ps1 = p1;
    ps2 = p2;
    sh_size = size;
    sh_color = color;

    painter.setPen(QPen(sh_color, sh_size, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.setBrush(QBrush(sh_color));
    painter.drawEllipse(p1,sh_size,sh_size);

}
void LineShape::Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter){
    ps1 = p1;
    ps2 = p2;
    sh_size = size;
    sh_color = color;

    painter.setPen(QPen(sh_color, sh_size, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawLine(p1,p2);
}
void RectShape::Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter){
    ps1 = p1;
    ps2 = p2;
    sh_size = size;
    sh_color = color;

    painter.setBrush(QBrush(Qt::cyan));
    painter.setPen(QPen(color, size, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawRect(QRect(p1,p2));
}
void ElipseShape::Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter){
    ps1 = p1;
    ps2 = p2;
    sh_size = size;
    sh_color = color;
    int rx = abs(p2.x()-p1.x());
    int ry = abs(p2.y()-p1.y());

    painter.setBrush(QBrush(Qt::green));
    painter.setPen(QPen(color, size, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawEllipse(p1, rx, ry);

}

int PointShape::GetName(){
    return 0;
};
int LineShape::GetName(){
    return 1;
};
int RectShape::GetName(){
    return 2;
};
int ElipseShape::GetName(){
    return 3;
};
