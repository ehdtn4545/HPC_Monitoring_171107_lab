#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Reset_DevProperties() {

    Del_DevProperties();
    Init_DevProperties();

    return 0;

}
