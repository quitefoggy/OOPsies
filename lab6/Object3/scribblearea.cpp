#include <QtWidgets>
//#include <iostream>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif

#include "scribblearea.h"


ScribbleArea::ScribbleArea(QWidget *parent): QWidget(parent)
{
    // Roots the widget to the top left even if resized
    setAttribute(Qt::WA_StaticContents);

    // Set defaults for the monitored variables
    modified = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
    p = new PointShape();
    //rubber_color.setBrush(QPalette::Accent, QBrush(Qt::blue));

    image = QImage(this->size(),QImage::Format_ARGB32);
}

// Used to load the image and place it in the widget
bool ScribbleArea::openImage(const QString &fileName)
{
    // Holds the image
    QImage loadedImage;

    // If the image wasn't loaded leave this function
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

// Save the current image
bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat)
{
    // Created to hold the image
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}

// Used to change the pen color
void ScribbleArea::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

// Used to change the pen width
void ScribbleArea::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

// Color the image area with white
void ScribbleArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    //modified = true;
    update();
}

void ScribbleArea::drawAxis()
{
    clearImage();
    QPainter painter(&image);
    //painter.begin(&image);

    int cur_width = this->width();
    int cur_height = this->height();


    top_left.setX(int(cur_width*0.2));
    top_left.setY(int(cur_height*0.2));

    bottom_left.setX(int(cur_width*0.2));
    bottom_left.setY(int(cur_height - cur_height*0.2));

    bottom_right.setX(int(cur_width - cur_width*0.2));
    bottom_right.setY(int(cur_height - cur_height*0.2));

    p = new LineShape();
    p->Show(top_left,bottom_left,1,Qt::black,painter);
    p->Show(bottom_left,bottom_right,1,Qt::black,painter);
    update();
    //painter.end();

}

void ScribbleArea::drawGraph(std::vector<int> point_list){
    if (!point_list.empty()){
        QPainter painter(&image);

        //lastPoint = QPoint(bottom_left.x()+0,bottom_left.y()-point_list[0]);
        lastPoint = QPoint(bottom_left.x()+0*50,bottom_left.y()-point_list[0]);

        for (int i = 0; i<point_list.size(); i++){
            p = new PointShape();
            QPoint cur_point = QPoint(bottom_left.x()+i*50,bottom_left.y()-point_list[i]);
            p->Show(cur_point,cur_point,5,Qt::blue,painter);
            p = new LineShape();
            p->Show(lastPoint,cur_point,2,Qt::blue,painter);
            lastPoint = cur_point;
        }
        //p->Show(lastPoint, event->pos(), myPenWidth, myPenColor, painter);
        update();
    }
}

// QPainter provides functions to draw on the widget
// The QPaintEvent is sent to widgets that need to
// update themselves

void ScribbleArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Returns the rectangle that needs to be updated
    QRect dirtyRect = event->rect();

    // Draws the rectangle where the image needs to
    // be updated
    painter.drawImage(dirtyRect, image, dirtyRect);
}


// Resize the image to slightly larger then the main window
// to cut down on the need to resize the image
void ScribbleArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}



// When the app is resized create a new image using
// the changes made to the image
void ScribbleArea::resizeImage(QImage *image, const QSize &newSize)
{
    // Check if we need to redraw the image
    if (image->size() == newSize)
        return;

    // Create a new image to display and fill it with white
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    // Draw the image
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}
