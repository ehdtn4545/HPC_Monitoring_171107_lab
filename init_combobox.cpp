#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_ComboBox() {

    for (int i = 0; i < devicecount; i++) {
        ui->PU_Device_comboBox->addItem(gpu_info[i].DeviceName);
        ui->MU_Device_comboBox->addItem(gpu_info[i].DeviceName);
        ui->Prop_Device_comboBox->addItem(gpu_info[i].DeviceName);
    }

    return 0;

}
