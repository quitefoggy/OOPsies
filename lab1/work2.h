#ifndef WORK2_H
#define WORK2_H

#include <QDialog>

namespace Ui {
class work2;
}

class work2 : public QDialog
{
    Q_OBJECT

public:
    explicit work2(QWidget *parent = nullptr, QString messagge = "default");
    ~work2();
    signals:
        void messageSent (const QString data);

private:
    Ui::work2 *ui;
};

#endif // WORK2_H
