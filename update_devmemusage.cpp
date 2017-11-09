#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Update_DevMemUsage(int key) {

    int device = ui->MU_Device_comboBox->currentIndex();

    GPU_TestMemcpy(device);

    MemChart[0].graph(0)->addData(key, (double)gpu_info[device].h2d_copy_time);
    MemChart[0].graph(0)->rescaleValueAxis(false, true);
    MemChart[0].xAxis->setRange(key, 8, Qt::AlignRight);
    MemChart[0].replot();
    ui->label_41->setText(QString("%1").arg(gpu_info[device].h2d_copy_time));

    MemChart[1].graph(0)->addData(key, (double)gpu_info[device].d2h_copy_time);
    MemChart[1].xAxis->setRange(key, 8, Qt::AlignRight);
    MemChart[1].graph(0)->rescaleValueAxis(false, true);
    MemChart[1].replot();
    ui->label_42->setText(QString("%1").arg(gpu_info[device].d2h_copy_time));

    MemChart[2].graph(0)->addData(key, (double)gpu_info[device].g2s_copy_time);
    MemChart[2].xAxis->setRange(key, 8, Qt::AlignRight);
    MemChart[2].graph(0)->rescaleValueAxis(false, true);
    MemChart[2].replot();
    ui->label_43->setText(QString("%1").arg(gpu_info[device].g2s_copy_time));

    MemChart[3].graph(0)->addData(key, (double)gpu_info[device].s2g_copy_time);
    MemChart[3].xAxis->setRange(key, 8, Qt::AlignRight);
    MemChart[3].graph(0)->rescaleValueAxis(false, true);
    MemChart[3].replot();
    ui->label_44->setText(QString("%1").arg(gpu_info[device].s2g_copy_time));

    MemChart[4].graph(0)->addData(key, (double)gpu_info[device].s2r_copy_time);
    MemChart[4].xAxis->setRange(key, 8, Qt::AlignRight);
    MemChart[4].graph(0)->rescaleValueAxis(false, true);
    MemChart[4].replot();
    ui->label_45->setText(QString("%1").arg(gpu_info[device].s2r_copy_time));

    MemChart[5].graph(0)->addData(key, (double)gpu_info[device].r2s_copy_time);
    MemChart[5].xAxis->setRange(key, 8, Qt::AlignRight);
    MemChart[5].graph(0)->rescaleValueAxis(false, true);
    MemChart[5].replot();
    ui->label_46->setText(QString("%1").arg(gpu_info[device].s2r_copy_time));

    MemChart[6].graph(0)->addData(key, (double)gpu_info[device].g2r_copy_time);
    MemChart[6].xAxis->setRange(key, 8, Qt::AlignRight);
    MemChart[6].graph(0)->rescaleValueAxis(false, true);
    MemChart[6].replot();
    ui->label_47->setText(QString("%1").arg(gpu_info[device].g2r_copy_time));

    MemChart[7].graph(0)->addData(key, (double)gpu_info[device].r2g_copy_time);
    MemChart[7].xAxis->setRange(key, 8, Qt::AlignRight);
    MemChart[7].graph(0)->rescaleValueAxis(false, true);
    MemChart[7].replot();
    ui->label_48->setText(QString("%1").arg(gpu_info[device].r2g_copy_time));

    return 0;

}
