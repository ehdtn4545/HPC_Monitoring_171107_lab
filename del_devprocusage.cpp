#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Del_DevProcUsage() {

    delete[] SMChart;

    return 0;

}
