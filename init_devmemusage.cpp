#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_DevMemUsage() {

    //int device = ui->MU_Device_comboBox->currentIndex();
    MemChart = new QCustomPlot[8];

    MemChart[0].addGraph(0);
    MemChart[0].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    MemChart[0].xAxis->setTicks(false);
    MemChart[0].yAxis->setTicks(false);
    MemChart[0].axisRect()->setupFullAxesBox();

    MemChart[1].addGraph(0);
    MemChart[1].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    MemChart[1].xAxis->setTicks(false);
    MemChart[1].yAxis->setTicks(false);
    MemChart[1].axisRect()->setupFullAxesBox();

    MemChart[2].addGraph(0);
    MemChart[2].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    MemChart[2].xAxis->setTicks(false);
    MemChart[2].yAxis->setTicks(false);
    MemChart[2].axisRect()->setupFullAxesBox();

    MemChart[3].addGraph(0);
    MemChart[3].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    MemChart[3].xAxis->setTicks(false);
    MemChart[3].yAxis->setTicks(false);
    MemChart[3].axisRect()->setupFullAxesBox();

    MemChart[4].addGraph(0);
    MemChart[4].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    MemChart[4].xAxis->setTicks(false);
    MemChart[4].yAxis->setTicks(false);
    MemChart[4].axisRect()->setupFullAxesBox();

    MemChart[5].addGraph(0);
    MemChart[5].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    MemChart[5].xAxis->setTicks(false);
    MemChart[5].yAxis->setTicks(false);
    MemChart[5].axisRect()->setupFullAxesBox();

    MemChart[6].addGraph(0);
    MemChart[6].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    MemChart[6].xAxis->setTicks(false);
    MemChart[6].yAxis->setTicks(false);
    MemChart[6].axisRect()->setupFullAxesBox();

    MemChart[7].addGraph(0);
    MemChart[7].graph(0)->setPen(QPen(QColor(255, 0, 0)));
    MemChart[7].xAxis->setTicks(false);
    MemChart[7].yAxis->setTicks(false);
    MemChart[7].axisRect()->setupFullAxesBox();

    ui->gridLayout_15->addWidget(&MemChart[0]);
    ui->gridLayout_16->addWidget(&MemChart[1]);
    ui->gridLayout_17->addWidget(&MemChart[2]);
    ui->gridLayout_18->addWidget(&MemChart[3]);
    ui->gridLayout_19->addWidget(&MemChart[4]);
    ui->gridLayout_20->addWidget(&MemChart[5]);
    ui->gridLayout_21->addWidget(&MemChart[6]);
    ui->gridLayout_22->addWidget(&MemChart[7]);

    return 0;

}
