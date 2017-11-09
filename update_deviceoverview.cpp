#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Update_DeviceOverview(int key) {

    nvmlReturn_t result;

    for (int i = 0; i < devicecount; i++) {

        result = nvmlDeviceGetUtilizationRates(gpu_info[i].device, &gpu_info[i].util);
        result = nvmlDeviceGetMemoryInfo(gpu_info[i].device, &gpu_info[i].memory);
        result = nvmlDeviceGetPowerUsage(gpu_info[i].device, &gpu_info[i].power);
        result = nvmlDeviceGetTemperature(gpu_info[i].device, NVML_TEMPERATURE_GPU, &gpu_info[i].temperature);

        DOVChart[i * 4 + 0].graph(0)->addData(key, (double)gpu_info[i].util.gpu);
        DOVChart[i * 4 + 1].graph(0)->addData(key, (double)gpu_info[i].util.memory);
        DOVChart[i * 4 + 2].graph(0)->addData(key, (double)gpu_info[i].power / 1000.0);
        DOVChart[i * 4 + 3].graph(0)->addData(key, (double)gpu_info[i].temperature);

        DOVChart[i * 4 + 0].xAxis->setRange(key, 8, Qt::AlignRight);
        DOVChart[i * 4 + 1].xAxis->setRange(key, 8, Qt::AlignRight);
        DOVChart[i * 4 + 2].xAxis->setRange(key, 8, Qt::AlignRight);
        DOVChart[i * 4 + 3].xAxis->setRange(key, 8, Qt::AlignRight);

        DOVChart[i * 4 + 0].replot();
        DOVChart[i * 4 + 1].replot();
        DOVChart[i * 4 + 2].replot();
        DOVChart[i * 4 + 3].replot();

    }

    return 0;

}
