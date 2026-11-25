#ifndef SHAPE_H
#define SHAPE_H

#include <qpainter.h>

class Shape{
protected:
    QPoint ps1, ps2;
    QColor sh_color;
    int sh_size;
    bool is_transparent = false;
public:
    Shape(){
        ps1 = QPoint(0,0);
        ps2 = QPoint(1,1);
        sh_color = Qt::black;
    };
    ~Shape();

    void Set (int x1, int y1, int x2, int y2){
        ps1.setX(x1);
        ps1.setY(y1);
        ps2.setX(x2);
        ps2.setY(y2);
    };
    virtual void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) = 0;
    virtual int GetName() = 0;
    virtual QString GetDisplayName() = 0;

    QString getInfo(){
        QString name = GetDisplayName();
        QString info = name + " AX" + QString::number(ps1.x()) + " AY" + QString::number(ps1.y()) +
                              " BX" + QString::number(ps2.x()) + " BY" + QString::number(ps2.y()) +
                       " Size=" + QString::number(sh_size) + " Color="+sh_color.name();
        return info;
    }
};


class PointShape: public virtual Shape{
private:

public:
    PointShape(){
        sh_color = Qt::blue;
        sh_size = 3;
    };
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
    QString GetDisplayName() override;
};

class LineShape: public virtual Shape{
private:

public:
    LineShape(){
        sh_color = Qt::blue;
        sh_size = 8;
    }
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
    QString GetDisplayName() override;
};

class RectShape: public virtual Shape{
private:

public:
    RectShape(){
        sh_color = Qt::black;
        sh_size = 8;
    };
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
    QString GetDisplayName() override;
};
class ElipseShape: public virtual Shape{
private:

public:
    ElipseShape(){
        sh_color = Qt::black;
        sh_size = 5;
    };
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
    QString GetDisplayName() override;
};
class LineOOShape: public LineShape, public PointShape{
private:

public:
    LineOOShape(){
        sh_color = Qt::black;
        sh_size = 5;
    };
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
    QString GetDisplayName() override;
};
class CubeShape: public LineShape, public RectShape{
private:

public:
    CubeShape(){
        is_transparent = true;
        sh_color = Qt::black;
        sh_size = 8;
    };
    void Show(QPoint p1, QPoint p2, int size, QColor color, QPainter &painter) override;
    int GetName() override;
    QString GetDisplayName() override;
};

#endif // SHAPE_H
