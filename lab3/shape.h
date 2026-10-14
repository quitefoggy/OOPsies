#ifndef SHAPE_H
#define SHAPE_H

#include <qpainter.h>
#include <QRubberBand>

class Shape{
protected:
    QPoint ps1, ps2;
    int xs1, ys1, xs2, ys2;
    QColor sh_color;
public:
    Shape(){
        xs1 = 0;
        ys1 = 0;
        xs2 = 1;
        ys2 = 1;
        ps1 = QPoint(xs1,ys1);
        ps2 = QPoint(xs2,ys2);
        sh_color = Qt::black;
    };
    ~Shape();

    void Set (int x1, int y1, int x2, int y2){
        xs1 = x1;
        ys1 = y1;
        xs2 = x2;
        ys2 = y2;
    };
    virtual void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) = 0;
    virtual int GetName() = 0;
};


class PointShape: public Shape{
private:
    QColor p_color = Qt::blue;
    int sh_size = 3;
public:
    PointShape(){
        p_color = Qt::blue;
        sh_size = 3;
    };
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
};

class LineShape: public Shape{
private:
    QColor l_color = Qt::blue;
    int sh_size;
public:
    LineShape(){
        l_color = Qt::blue;
        sh_size = 8;
    }
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
};

class RectShape: public Shape{
private:
    QColor r_color = Qt::black;
    int sh_size = 8;
public:
    RectShape(){
        r_color = Qt::black;
        sh_size = 8;
    };
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
};
class ElipseShape: public virtual Shape{
private:
    QColor e_color = Qt::black;
    int sh_size = 5;
public:
    ElipseShape(){
        e_color = Qt::black;
        sh_size = 5;
    };
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
};

#endif // SHAPE_H
