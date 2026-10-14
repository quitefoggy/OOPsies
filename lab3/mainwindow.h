#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QObject>

#include "shape.h"

// ScribbleArea used to paint the image
class ScribbleArea;

class MainWindow : public QMainWindow
{
    // Declares our class as a QObject which is the base class
    // for all Qt objects
    // QObjects handle events
    Q_OBJECT

public:
    MainWindow();

    // What we'll draw on
    ScribbleArea *scribbleArea;

protected:
    // Function used to close an event
    void closeEvent(QCloseEvent *event) override;

    // The events that can be triggered
private slots:
    void open();
    void save();
    void penColor();
    void penWidth();
    void changeShape(int shape_id);
    void about();

private:

    PointShape *mw_dot;
    LineShape *mw_line;
    RectShape *mw_rect;
    ElipseShape *mw_eli;

    // Will tie user actions to functions
    void createActions();
    void createMenus();

    // Will check if changes have occurred since last save
    bool maybeSave();

    // Opens the Save dialog and saves
    bool saveFile(const QByteArray &fileFormat);


    // The menu widgets
    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *shapeMenu;
    QMenu *helpMenu;

    // All the actions that can occur
    QAction *openAct;

    // Actions tied to specific file formats
    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *printAct;

    //Actions tied to info menus
    QAction *aboutAct;
    QAction *aboutQtAct;

    //Actions tied to drawing

    QActionGroup *shape_group;
    QAction *sh_dot;
    QAction *sh_line;
    QAction *sh_rectangle;
    QAction *sh_elipse;

    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *clearScreenAct;
};

#endif
