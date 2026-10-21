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
void LineOOShape::Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter){
    ps1 = p1;
    ps2 = p2;
    sh_size = size;
    int dot_size = sh_size+3;
    sh_color = color;

    painter.setPen(QPen(sh_color, sh_size, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    /*
    * painter.drawLine(p1,p2);
    * painter.drawEllipse(p1,dot_size,dot_size);
    * painter.drawEllipse(p2,dot_size,dot_size);
    */
    LineShape::Show(p1,p2,size,color,painter);
    PointShape::Show(p1,p2,dot_size,color,painter);
    PointShape::Show(p2,p1,dot_size,color,painter);

};
void CubeShape::Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter){
    ps1 = p1;
    ps2 = p2;
    sh_size = size;
    sh_color = color;

    int buffX = p1.x()-p2.x();
    int buffY = p1.y()-p2.y();

    QPoint inner1tl = QPoint();
    inner1tl.setX(p1.x()+((buffX*20)/100));
    inner1tl.setY(p1.y());

    QPoint inner1br = QPoint();
    inner1br.setX(p2.x());
    inner1br.setY(p2.y()-((buffY*20)/100));

    QPoint inner2tl = QPoint();
    inner2tl.setX(p1.x());
    inner2tl.setY(p1.y()+((buffY*20)/100));

    QPoint inner2br = QPoint();
    inner2br.setX(p2.x()-((buffX*20)/100));
    inner2br.setY(p2.y());

    //painter.setBrush(QBrush(Qt::cyan));
    painter.setPen(QPen(color, size, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    //painter.drawRect(QRect(p1,p2));
    RectShape::Show(inner1tl,inner1br,size,color,painter);

    LineShape::Show(inner1tl,inner2tl,size,color,painter);
    LineShape::Show(QPoint(p2.x(),p1.y()),QPoint(inner2br.x(),inner2tl.y()),size,color,painter);
    LineShape::Show(inner1br,inner2br,size,color,painter);
    LineShape::Show(QPoint(p1.x(),p2.y()),QPoint(inner1tl.x(),inner1br.y()),size,color,painter);

    RectShape::Show(inner2tl,inner2br,size,color,painter);


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
int LineOOShape::GetName(){
    return 4;
};
int CubeShape::GetName(){
    return 5;
};