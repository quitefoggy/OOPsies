#ifndef WORK1_H
#define WORK1_H

#include <QDialog>
#include <qlistwidget.h>

namespace Ui {
class work1;
}

class work1 : public QDialog
{
    Q_OBJECT

public:
    explicit work1(QWidget *parent = nullptr, QString message = "default");
    ~work1();
    signals:
        void selection_return(QString selection = "empty");

    private:
    Ui::work1 *ui;
};

#endif // WORK1_H
