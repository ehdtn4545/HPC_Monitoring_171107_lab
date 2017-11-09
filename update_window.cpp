#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Update_Window() {

    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;
    static double lastPointKey = 0;

    if (key-lastPointKey > 1.000) { // at most add point every 2 ms

        Update_HostOverview(key);
        Update_DeviceOverview(key);
        Update_DevProcUsage(key);
        Update_DevMemUsage(key);

        lastPointKey = key;

    }

    return 0;

}
