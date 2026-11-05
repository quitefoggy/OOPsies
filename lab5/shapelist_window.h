#ifndef SHAPELIST_WINDOW_H
#define SHAPELIST_WINDOW_H

#include <QDialog>
#include <qlistwidget.h>

class ShapeList_window : public QDialog
{
    Q_OBJECT
public:
    explicit ShapeList_window(QWidget *parent = nullptr);
    void AddShapeToList(QString data);
    QString getShapeList();

private:
    QListWidget *Shapelist;

};

#endif // SHAPELIST_WINDOW_H
