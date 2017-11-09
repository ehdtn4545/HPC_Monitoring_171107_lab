#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Update_DevProcUsage(int key) {

    int device = ui->PU_Device_comboBox->currentIndex();
    int type = ui->PU_Type_comboBox->currentIndex();

    GPU_TestPerformance(device, type);

    if (type == 0) {
        for (int i = 0; i < gpu_info[device].SMCount; i++) {
            SMChart[i].graph(0)->addData(key, (double)gpu_info[device].double_time_total[i]);
            SMChart[i].graph(0)->rescaleValueAxis(false, true);
            SMChart[i].xAxis->setRange(key, 8, Qt::AlignRight);
            SMChart[i].replot();
        }
    } else if (type == 1) {
        for (int i = 0; i < gpu_info[device].SMCount; i++) {
            SMChart[i].graph(0)->addData(key, (double)gpu_info[device].float_time_total[i]);
            SMChart[i].graph(0)->rescaleValueAxis(false, true);
            SMChart[i].xAxis->setRange(key, 8, Qt::AlignRight);
            SMChart[i].replot();
        }
    } else if (type == 2) {
        for (int i = 0; i < gpu_info[device].SMCount; i++) {
            SMChart[i].graph(0)->addData(key, (double)gpu_info[device].int_time_total[i]);
            SMChart[i].graph(0)->rescaleValueAxis(false, true);
            SMChart[i].xAxis->setRange(key, 8, Qt::AlignRight);
            SMChart[i].replot();
        }
    } else if (type == 3) {
        for (int i = 0; i < gpu_info[device].SMCount; i++) {
            SMChart[i].graph(0)->addData(key, (double)gpu_info[device].long_time_total[i]);
            SMChart[i].graph(0)->rescaleValueAxis(false, true);
            SMChart[i].xAxis->setRange(key, 8, Qt::AlignRight);
            SMChart[i].replot();
        }
    }

    return 0;

}
