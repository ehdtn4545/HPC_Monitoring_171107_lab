#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_DevProcUsage() {

    int device = ui->PU_Device_comboBox->currentIndex();
    //int type = ui->PU_Type_comboBox->currentIndex();
    int smcount = gpu_info[device].SMCount;

    SMChart = new QCustomPlot[smcount];

    for (int i = 0; i < smcount; i++) {
        SMChart[i].addGraph();
        SMChart[i].graph(0)->setPen(QPen(QColor(255, 0, 0)));
        SMChart[i].xAxis->setLabelFont(QFont("Consolas", 12, 0,false));
        SMChart[i].xAxis->setLabel(QString("SM #%1").arg(i));
        SMChart[i].xAxis->setLabelPadding(2);
        SMChart[i].xAxis->setTicks(false);
        SMChart[i].axisRect()->setupFullAxesBox();
        SMChart[i].yAxis->setRange(0, 100);
        connect(SMChart[i].xAxis, SIGNAL(rangeChanged(QCPRange)), SMChart[i].xAxis2, SLOT(setRange(QCPRange)));
        connect(SMChart[i].yAxis, SIGNAL(rangeChanged(QCPRange)), SMChart[i].yAxis2, SLOT(setRange(QCPRange)));
        ui->gridLayout_6->addWidget(&SMChart[i], (int)(i/4), i%4);
    }

    //printf("devnum = %d\n", devnum);
    //printf("type = %d\n", type);

    return 0;

}
