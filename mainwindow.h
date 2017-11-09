#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cuda.h>
#include <nvml.h>
#include <Pdh.h>
#include <Windows.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "qcustomplot.h"

struct gpufactors {

    // CUDA Properties
    char *DeviceName;
    int ComputeCapabilityMajor;
    int ComputeCapabilityMinor;
    int ClockRate;
    int SMCount;
    int WarpSize;
    int MaxThreadsSM;
    int MaxThreadsBlock;
    int MaxThreadsDimX;
    int MaxThreadsDimY;
    int MaxThreadsDimZ;
    int MaxGridSizeX;
    int MaxGridSizeY;
    int MaxGridSizeZ;
    int MaxRegSM;
    int MaxRegBlock;
    int MaxSharedMemSM;
    int MaxSharedMemBlock;
    bool ConcurrentKernels;

    // NVML Handle
    nvmlDevice_t device;

    // NVML Status
    nvmlUtilization_t util;
    nvmlMemory_t memory;
    unsigned int power;
    unsigned int temperature;
    unsigned int fanspeed;

    // Performance
    float h2d_copy_time;
    float d2h_copy_time;

    float g2s_copy_time;
    float s2g_copy_time;

    float s2r_copy_time;
    float r2s_copy_time;

    float g2r_copy_time;
    float r2g_copy_time;

    float *double_time;
    float *double_time_total;
    float *float_time;
    float *float_time_total;
    float *int_time;
    float *int_time_total;
    float *long_time;
    float *long_time_total;

};

struct chkpt_process {

    int pid;
    char *name;

    int latest_YY;
    int latest_MM;
    int latest_DD;
    int latest_h;
    int latest_m;
    int latest_s;

};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int Init_GPUInfo();
    int Init_ComboBox();
    int Init_HostOverview();
    int Init_DeviceOverview();
    int Init_DevProcUsage();
    int Init_DevMemUsage();
    int Init_DevProperties();

    int Update_HostOverview(int key);
    int Update_DeviceOverview(int key);
    int Update_DevProcUsage(int key);
    int Update_DevMemUsage(int key);

    int Del_DevProcUsage();
    int Del_DevMemUsage();
    int Del_DevProperties();

    int GPU_TestPerformance(int device, int type);
    int GPU_TestMemcpy(int device);


private:
    Ui::MainWindow *ui;

    int devicecount;
    gpufactors *gpu_info;

    QCustomPlot *HOVChart;

    QGroupBox *DOVDevice;
    QGridLayout *DOVGrid;
    QCustomPlot *DOVChart;

    QCustomPlot *SMChart;

    QCustomPlot *MemChart;

    double *host_arr_double;
    float *host_arr_float;
    int *host_arr_int;
    long long *host_arr_long;

    chkpt_process *proc_list;

private slots:
    int Update_Window();

    int Reset_DevProcUsage();
    int Reset_DevMemUsage();
    int Reset_DevProperties();

    int Reset_LtChkptDsp();

    //int GPU_TestPerformance(int device, int type);
    //int GPU_TestMemcpy(int device);

};

__global__ void TestDouble(double *arr, float *device_double_time, int size);
__global__ void TestSingle(float *arr, float *device_single_time, int size);
__global__ void TestInt(int *arr, float *device_int_time, int size);
__global__ void TestLong(long long *arr, float *device_long_time, int size);

__global__ void TestDeviceMemcpy(double *d_arr_double, float *d_arr_float, int *d_arr_int, long long *d_arr_long,
                                 float *time_g2s, float *time_s2g, float *time_s2r, float *time_r2s, float *time_g2r, float *time_r2g,
                                 int size);

#endif // MAINWINDOW_H
