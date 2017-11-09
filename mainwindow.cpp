#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    printf("Start\n");

    Init_GPUInfo();
    printf("Init_GPUInfo_done\n");

    Init_ComboBox();
    printf("Init_ComboBox_done\n");

    Init_HostOverview();
    printf("Init_HostOverview_done\n");

    Init_DeviceOverview();
    printf("Init_DeviceOverview_done\n");

    Init_DevProcUsage();
    printf("Init_DevProcUsage_done\n");

    Init_DevMemUsage();
    printf("Init_DevMemUsage_done\n");

    Init_DevProperties();
    printf("Init_DevProperties_done\n");

    connect(ui->PU_Device_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(Reset_DevProcUsage()));
    connect(ui->PU_Type_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(Reset_DevProcUsage()));

    connect(ui->MU_Device_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(Reset_DevMemUsage()));

    connect(ui->Prop_Device_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(Reset_DevProperties()));

    /**/
    proc_list = new chkpt_process[10];
    for (int i = 0; i < 10; i++) {
        proc_list[i].latest_YY = 2017;
        proc_list[i].latest_MM = 11;
        proc_list[i].latest_DD = 7;
        proc_list[i].latest_h = 0;
        proc_list[i].latest_m = 0;
        proc_list[i].latest_s = i;
    }
    /**/

    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(Reset_LtChkptDsp()));

    QTimer *dataTimer = new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(Update_Window()));
    dataTimer->start(100);

}

MainWindow::~MainWindow()
{
    nvmlShutdown();

    delete[] HOVChart;

    delete[] DOVChart;
    delete[] DOVGrid;
    delete[] DOVDevice;

    delete[] SMChart;

    delete[] MemChart;

    delete ui;
}
