#ifndef OBJECT2_H
#define OBJECT2_H

#include <QMainWindow>
#include <qapplication.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Object2;
}
QT_END_NAMESPACE

class Object2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Object2(QWidget *parent = nullptr);
    ~Object2() override;
    void logic(int N, int Min, int Max);

    QClipboard *clipboard;

private:
    Ui::Object2 *ui;
};
#endif // OBJECT2_H
