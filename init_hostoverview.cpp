#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_HostOverview() {

    HOVChart = new QCustomPlot[2];

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

    HOVChart[0].addGraph();
    HOVChart[0].graph(0)->setPen(QPen(QColor(0, 0, 255)));
    HOVChart[0].xAxis->setLabelFont(QFont("Consolas", 14, 0,false));
    HOVChart[0].xAxis->setLabel("CPU Usage");
    HOVChart[0].xAxis->setLabelPadding(5);
    HOVChart[0].xAxis->setTicker(timeTicker);
    HOVChart[0].axisRect()->setupFullAxesBox();
    HOVChart[0].yAxis->setRange(0, 100);

    HOVChart[1].addGraph();
    HOVChart[1].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    HOVChart[1].xAxis->setLabelFont(QFont("Consolas", 14, 0,false));
    HOVChart[1].xAxis->setLabel("Memory Usage");
    HOVChart[1].xAxis->setLabelPadding(5);
    HOVChart[1].xAxis->setTicker(timeTicker);
    HOVChart[1].axisRect()->setupFullAxesBox();
    HOVChart[1].yAxis->setRange(0, 100);

    /*
    HOVChart[2].addGraph();
    HOVChart[2].graph(0)->setPen(QPen(QColor(0, 255, 0)));
    HOVChart[2].xAxis->setLabelFont(QFont("Consolas", 14, 0,false));
    HOVChart[2].xAxis->setLabel("CPU Usage");
    HOVChart[2].xAxis->setLabelPadding(5);
    HOVChart[2].xAxis->setTicker(timeTicker);
    HOVChart[2].axisRect()->setupFullAxesBox();
    HOVChart[2].yAxis->setRange(0, 100);
    */

    ui->gridLayout_2->addWidget(&HOVChart[0]);
    ui->gridLayout_2->addWidget(&HOVChart[1]);

    return 0;

}
