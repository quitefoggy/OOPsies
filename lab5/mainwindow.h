#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "shapelist_window.h"
#include <QList>
#include <QMainWindow>
#include <QObject>

// ScribbleArea used to paint the image
class ScribbleArea;

class MainWindow : public QMainWindow
{
    // Declares our class as a QObject which is the base class
    // for all Qt objects
    // QObjects handle events
    Q_OBJECT

public:
    static MainWindow& getInstance(){
        static MainWindow instance;
        return instance;
    };

    // What we'll draw on
    ScribbleArea *scribbleArea;
    ShapeList_window *shape_list_window;
signals:
    void send_new_shape(QString shape_info);


protected:
    // Function used to close an event
    void closeEvent(QCloseEvent *event) override;

    // The events that can be triggered
private slots:
    void open();
    void save();
    void exportShapeCSV_slot();
    void penColor();
    void penWidth();
    void changeShape(int shape_id);
    void about();
    //void get_last_shape(QString data);

private:
    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator=(MainWindow&);

    QString get_last_shape(QString data);

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
    QAction *exportShapeCSV;
    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *printAct;

    //Actions tied to info menus
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *openList;

    //Actions tied to drawing

    QActionGroup *shape_group;
    QAction *sh_dot;
    QAction *sh_line;
    QAction *sh_rectangle;
    QAction *sh_elipse;
    QAction *sh_lineoo;
    QAction *sh_cube;

    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *clearScreenAct;
};

#endif
