#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Reset_LtChkptDsp() {

    int pnum = ui->listWidget->currentRow();

    ui->label_49->setText(QString("Latest Checkpoint : %1.%2.%3 %4:%5:%6")
                          .arg(proc_list[pnum].latest_YY)
                          .arg(proc_list[pnum].latest_MM)
                          .arg(proc_list[pnum].latest_DD)
                          .arg(proc_list[pnum].latest_h)
                          .arg(proc_list[pnum].latest_m)
                          .arg(proc_list[pnum].latest_s));

    return 0;

}
