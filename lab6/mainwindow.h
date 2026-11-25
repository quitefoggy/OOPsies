#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qprocess.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow& getInstance(){
        static MainWindow instance;
        return instance;
    };

    //explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushStart_clicked();

private:
    Ui::MainWindow *ui;

    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator=(MainWindow&);


    QString program2 = "./Object2/Object2";
    QStringList arguments2;

    QString program3 = "./Object3/Object3";
    QStringList arguments3;

    QProcess object2_proc = QProcess(this);
    QProcess object3_proc = QProcess(this);
};

#endif // MAINWINDOW_H
