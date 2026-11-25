#include "object3.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Object3& window = window.getInstance();
    window.show();

    return QApplication::exec();
}
