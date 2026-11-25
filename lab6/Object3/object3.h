#ifndef OBJECT3_H
#define OBJECT3_H

#include <QList>
#include <QMainWindow>
#include <QObject>

// ScribbleArea used to paint the image
class ScribbleArea;

class Object3: public QMainWindow
{
    Q_OBJECT

public:
    static Object3& getInstance(){
        static Object3 instance;
        return instance;
    };

    // What we'll draw on
    ScribbleArea *scribbleArea;

private:
    Object3();
    Object3(const Object3&);
    Object3& operator=(Object3&);

    void parseClipboard();
};

#endif
