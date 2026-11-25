#include "object2.h"
#include <string>
#include <QApplication>

// for debugging in console
//#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (argc<4){
        return 1;
    }
    Object2 w;

    w.clipboard = QApplication::clipboard();

    //qInfo() << argv[1];
    int N = std::stoi(argv[1]);
    int Min = std::stoi(argv[2]);
    int Max = std::stoi(argv[3]);
    w.show();
    w.logic(N,Min,Max);
    return QApplication::exec();
}
