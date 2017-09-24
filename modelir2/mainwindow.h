#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QVector>
#include <math.h>
#include <statoperations.h>

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_generateButton_clicked();

private:
    Ui::MainWindow *ui;
    int R0 = 1;
    int Rprev = 1;
    int RprevY = 1;
    int a = 171;
    int m = 53125;
    int c = 11213;
    int a2 = 777;
    int m2 = 50000;
    int c2 = 4857;
    double getRand();
    double getRandY();
    double sumOfRand(int);
    double mulOfRand(int n);

};

#endif // MAINWINDOW_H
