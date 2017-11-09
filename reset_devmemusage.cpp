#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Reset_DevMemUsage() {

    Del_DevMemUsage();
    Init_DevMemUsage();

    return 0;

}
