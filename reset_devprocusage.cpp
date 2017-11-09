#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Reset_DevProcUsage() {

    Del_DevProcUsage();
    Init_DevProcUsage();

    return 0;

}
