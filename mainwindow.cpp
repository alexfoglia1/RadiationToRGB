#include "mainwindow.h"
#include "ui_mainwindow.h"

const auto planck = 6.62607004e-34;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcdNumber_8->display(1e-19);

    mActualFrequency = (kMinFrequency + kMaxFrequency) / 2.0;
    ui->lcdNumber_4->display(mActualFrequency);
    ui->horizontalSlider->setMinimum(kMinFrequency * 10.0);
    ui->horizontalSlider->setMaximum(kMaxFrequency * 10.0);
    ui->horizontalSlider->setSliderPosition((int)(mActualFrequency * 10.0));

    updateColor(mActualFrequency * 10.0);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateColor(int)));
}

void MainWindow::updateColor(int value)
{
    mActualFrequency = value / 10.0;

    double mActualFrequency_hz = mActualFrequency * 1e12;
    Color rgb = c.convert(mActualFrequency_hz);

    QString styleSheet = QString("background-color: rgb(%1, %2, %3)")
            .arg(rgb.red)
            .arg(rgb.green)
            .arg(rgb.blue);

    ui->colorTarget->setStyleSheet(styleSheet);
    ui->lcdNumber_4->display(mActualFrequency);

    double actualWavelength_nm = (lightspeed_m_s / mActualFrequency_hz) * 1e9;
    ui->lcdNumber_5->display(actualWavelength_nm);

    double photonEnergy_j = planck * mActualFrequency_hz;
    ui->lcdNumber_6->display(photonEnergy_j * 1e19);

    double photonEnergy_ev = photonEnergy_j * 6.242e18;
    ui->lcdNumber_7->display(photonEnergy_ev);

    ui->lcdNumber->display(rgb.red);
    ui->lcdNumber_2->display(rgb.green);
    ui->lcdNumber_3->display(rgb.blue);
}

MainWindow::~MainWindow()
{
    delete ui;
}
