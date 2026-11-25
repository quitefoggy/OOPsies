#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <qpainter.h>

#include "shape.h"


class ScribbleArea: public QWidget
{
    Q_OBJECT

public:
    ScribbleArea(QWidget *parent = nullptr);
    QImage image;
    void drawAxis();
    void drawGraph(std::vector<int> point_list);

    QPoint top_left = QPoint();
    QPoint bottom_left = QPoint();
    QPoint bottom_right = QPoint();

    Shape *p;

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    // Stores the location at the current mouse event
    QPoint lastPoint;

    bool modified;
    bool isModified() const { return modified; }

    int myPenWidth;
    int penWidth() const { return myPenWidth; }
    QColor myPenColor;
    QColor penColor() const { return myPenColor; }

protected:
    void paintEvent(QPaintEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
    void resizeImage(QImage *image, const QSize &newSize);

    // Events to handle
    void clearImage();

};
#endif
