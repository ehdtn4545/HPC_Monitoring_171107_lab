#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_DevProperties() {

    int device = ui->Prop_Device_comboBox->currentIndex();

    ui->label_17->setText(gpu_info[device].DeviceName);
    ui->label_18->setText(QString("%1.%2").arg(gpu_info[device].ComputeCapabilityMajor).arg(gpu_info[device].ComputeCapabilityMinor));
    ui->label_19->setText(QString("%1 KHz").arg(gpu_info[device].ClockRate));
    ui->label_20->setText(QString("%1 SM(s)").arg(gpu_info[device].SMCount));
    ui->label_21->setText(QString("%1 Threads/Warp").arg(gpu_info[device].WarpSize));
    ui->label_22->setText(QString("%1 Threads/SM").arg(gpu_info[device].MaxThreadsSM));
    ui->label_23->setText(QString("%1 Threads/Block").arg(gpu_info[device].MaxThreadsBlock));
    ui->label_24->setText(QString("(Max. %1, Max. %2, Max. %3)").arg(gpu_info[device].MaxThreadsDimX).arg(gpu_info[device].MaxThreadsDimY).arg(gpu_info[device].MaxThreadsDimZ));
    ui->label_25->setText(QString("(Max. %1, Max. %2, Max. %3)").arg(gpu_info[device].MaxGridSizeX).arg(gpu_info[device].MaxGridSizeY).arg(gpu_info[device].MaxGridSizeZ));
    ui->label_26->setText(QString("%1 Registers/SM").arg(gpu_info[device].MaxRegSM));
    ui->label_27->setText(QString("%1 Registers/Block").arg(gpu_info[device].MaxRegBlock));
    ui->label_28->setText(QString("%1 Bytes/SM").arg(gpu_info[device].MaxSharedMemSM));
    ui->label_29->setText(QString("%1 Bytes/Block").arg(gpu_info[device].MaxSharedMemBlock));
    ui->label_30->setText(gpu_info[device].ConcurrentKernels ? "True":"False");

    return 0;

}
