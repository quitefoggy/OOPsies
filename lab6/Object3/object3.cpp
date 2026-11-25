#include <QtWidgets>
//#include <QFileDialog>
#include "object3.h"
#include "scribblearea.h"


Object3::Object3()
{
    setWindowTitle(tr("Object3"));
    resize(500, 500);

    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);
    scribbleArea->drawAxis();

    parseClipboard();
}

void Object3::parseClipboard(){
    QClipboard *clipboard = QApplication::clipboard();
    //clipboard->setText("4.9 8.2 19.8");
    qInfo() << clipboard->text();
    const QMimeData *mimeData = clipboard->mimeData();

    //setWindowTitle(clipboard->text());
    if (mimeData->hasText()) {
        //qInfo() << "hmm...";
        QString clipboard_info = clipboard->text(QClipboard::Clipboard); //QClipboard::Selection or Clipboard
        QStringList point_info = clipboard_info.split(" ");
        //qInfo() << point_info;
        std::vector<int> point_list;
        for (int i = 0; i<point_info.length()-1;i++){
            point_list.push_back(static_cast<int>(std::round(point_info[i].toDouble())));
        }
        qInfo() << point_list;
        scribbleArea->drawGraph(point_list);

    } else {
        //setText(tr("Cannot display data"));
    }
}