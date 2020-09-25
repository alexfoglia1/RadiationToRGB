#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "converter.h"
#include "rgbhashtable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    const double kMinFrequency = 400.0;
    const double kMaxFrequency = 780.0;
    double mActualFrequency;
    Converter c;
    RGBHashTable* rgb_ht;

public slots:
    void updateColor(int value);

};

#endif // MAINWINDOW_H
