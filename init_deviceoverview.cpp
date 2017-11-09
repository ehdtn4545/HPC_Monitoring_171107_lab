#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_DeviceOverview() {

    DOVDevice = new QGroupBox[devicecount];
    DOVGrid = new QGridLayout[devicecount];
    DOVChart = new QCustomPlot[devicecount * 4];

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

    for (int i = 0; i < devicecount; i++) {

        DOVChart[i * 4 + 0].addGraph();
        DOVChart[i * 4 + 0].graph(0)->setPen(QPen(QColor(0, 0, 255))); // Blue line
        DOVChart[i * 4 + 0].xAxis->setLabelFont(QFont("Consolas", 14, 0,false));
        DOVChart[i * 4 + 0].xAxis->setLabel("GPU Usage");
        DOVChart[i * 4 + 0].xAxis->setLabelPadding(5);
        DOVChart[i * 4 + 0].xAxis->setTicker(timeTicker);
        DOVChart[i * 4 + 0].axisRect()->setupFullAxesBox();
        DOVChart[i * 4 + 0].yAxis->setRange(0, 100);

        DOVChart[i * 4 + 1].addGraph();
        DOVChart[i * 4 + 1].graph(0)->setPen(QPen(QColor(255, 0, 0))); // Red line
        DOVChart[i * 4 + 1].xAxis->setLabelFont(QFont("Consolas", 14, 0,false));
        DOVChart[i * 4 + 1].xAxis->setLabel("Global Memory Usage");
        DOVChart[i * 4 + 1].xAxis->setLabelPadding(5);
        DOVChart[i * 4 + 1].xAxis->setTicker(timeTicker);
        DOVChart[i * 4 + 1].axisRect()->setupFullAxesBox();
        DOVChart[i * 4 + 1].yAxis->setRange(0, 100);

        DOVChart[i * 4 + 2].addGraph();
        DOVChart[i * 4 + 2].graph(0)->setPen(QPen(QColor(0, 255, 0))); // Green line
        DOVChart[i * 4 + 2].xAxis->setLabelFont(QFont("Consolas", 14, 0,false));
        DOVChart[i * 4 + 2].xAxis->setLabel("Power Usage");
        DOVChart[i * 4 + 2].xAxis->setLabelPadding(5);
        DOVChart[i * 4 + 2].xAxis->setTicker(timeTicker);
        DOVChart[i * 4 + 2].axisRect()->setupFullAxesBox();
        DOVChart[i * 4 + 2].yAxis->setRange(0, 300);

        DOVChart[i * 4 + 3].addGraph();
        DOVChart[i * 4 + 3].graph(0)->setPen(QPen(QColor(204, 0, 204))); // Purple line
        DOVChart[i * 4 + 3].xAxis->setLabelFont(QFont("Consolas", 14, 0,false));
        DOVChart[i * 4 + 3].xAxis->setLabel("Temperature");
        DOVChart[i * 4 + 3].xAxis->setLabelPadding(5);
        DOVChart[i * 4 + 3].xAxis->setTicker(timeTicker);
        DOVChart[i * 4 + 3].axisRect()->setupFullAxesBox();
        DOVChart[i * 4 + 3].yAxis->setRange(0, 100);

        DOVGrid[i].addWidget(&DOVChart[i * 4 + 0], 1, 1);
        DOVGrid[i].addWidget(&DOVChart[i * 4 + 1], 1, 2);
        DOVGrid[i].addWidget(&DOVChart[i * 4 + 2], 2, 1);
        DOVGrid[i].addWidget(&DOVChart[i * 4 + 3], 2, 2);

        DOVDevice[i].setLayout(&DOVGrid[i]);
        DOVDevice[i].setTitle(QString(gpu_info[i].DeviceName));
        ui->gridLayout_4->addWidget(&DOVDevice[i], (int)(i / 4), i % 4);

        connect(DOVChart[i * 4 + 0].xAxis, SIGNAL(rangeChanged(QCPRange)), DOVChart[i * 4 + 0].xAxis2, SLOT(setRange(QCPRange)));
        connect(DOVChart[i * 4 + 0].yAxis, SIGNAL(rangeChanged(QCPRange)), DOVChart[i * 4 + 0].yAxis2, SLOT(setRange(QCPRange)));

        connect(DOVChart[i * 4 + 1].xAxis, SIGNAL(rangeChanged(QCPRange)), DOVChart[i * 4 + 1].xAxis2, SLOT(setRange(QCPRange)));
        connect(DOVChart[i * 4 + 1].yAxis, SIGNAL(rangeChanged(QCPRange)), DOVChart[i * 4 + 1].yAxis2, SLOT(setRange(QCPRange)));

        connect(DOVChart[i * 4 + 2].xAxis, SIGNAL(rangeChanged(QCPRange)), DOVChart[i * 4 + 2].xAxis2, SLOT(setRange(QCPRange)));
        connect(DOVChart[i * 4 + 2].yAxis, SIGNAL(rangeChanged(QCPRange)), DOVChart[i * 4 + 2].yAxis2, SLOT(setRange(QCPRange)));

        connect(DOVChart[i * 4 + 3].xAxis, SIGNAL(rangeChanged(QCPRange)), DOVChart[i * 4 + 3].xAxis2, SLOT(setRange(QCPRange)));
        connect(DOVChart[i * 4 + 3].yAxis, SIGNAL(rangeChanged(QCPRange)), DOVChart[i * 4 + 3].yAxis2, SLOT(setRange(QCPRange)));

    }

    return 0;

}
