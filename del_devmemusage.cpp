#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Del_DevMemUsage() {

    delete[] MemChart;

    return 0;

}
