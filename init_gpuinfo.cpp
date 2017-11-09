#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::Init_GPUInfo() {

    cudaDeviceProp cudaprop;
    cudaGetDeviceCount(&devicecount);

    nvmlReturn_t result;
    result = nvmlInit();

    gpu_info = new gpufactors[devicecount];

    for (int i = 0; i < devicecount; i++) {

        cudaSetDevice(i);
        cudaGetDeviceProperties(&cudaprop, i);

        gpu_info[i].DeviceName = new char[strlen(cudaprop.name) + 1];
        strcpy(gpu_info[i].DeviceName, cudaprop.name);

        gpu_info[i].ComputeCapabilityMajor = cudaprop.major;
        gpu_info[i].ComputeCapabilityMinor = cudaprop.minor;

        gpu_info[i].ClockRate = cudaprop.clockRate;

        gpu_info[i].SMCount = cudaprop.multiProcessorCount;

        gpu_info[i].WarpSize = cudaprop.warpSize;

        gpu_info[i].MaxThreadsSM = cudaprop.maxThreadsPerMultiProcessor;

        gpu_info[i].MaxThreadsBlock = cudaprop.maxThreadsPerBlock;

        gpu_info[i].MaxThreadsDimX = cudaprop.maxThreadsDim[0];
        gpu_info[i].MaxThreadsDimY = cudaprop.maxThreadsDim[1];
        gpu_info[i].MaxThreadsDimZ = cudaprop.maxThreadsDim[2];

        gpu_info[i].MaxGridSizeX = cudaprop.maxGridSize[0];
        gpu_info[i].MaxGridSizeY = cudaprop.maxGridSize[1];
        gpu_info[i].MaxGridSizeZ = cudaprop.maxGridSize[2];

        gpu_info[i].MaxRegSM = cudaprop.regsPerMultiprocessor;

        gpu_info[i].MaxRegBlock = cudaprop.regsPerBlock;

        gpu_info[i].MaxSharedMemSM = cudaprop.sharedMemPerMultiprocessor;

        gpu_info[i].MaxSharedMemBlock = cudaprop.sharedMemPerBlock;

        gpu_info[i].ConcurrentKernels = cudaprop.concurrentKernels;

        result = nvmlDeviceGetHandleByIndex(i, &gpu_info[i].device);

        gpu_info[i].h2d_copy_time = 0.0;
        gpu_info[i].d2h_copy_time = 0.0;

        gpu_info[i].double_time = new float[gpu_info[i].SMCount * gpu_info[i].MaxThreadsBlock];
        gpu_info[i].double_time_total = new float[gpu_info[i].SMCount];

        gpu_info[i].float_time = new float[gpu_info[i].SMCount * gpu_info[i].MaxThreadsBlock];
        gpu_info[i].float_time_total = new float[gpu_info[i].SMCount];

        gpu_info[i].int_time = new float[gpu_info[i].SMCount * gpu_info[i].MaxThreadsBlock];
        gpu_info[i].int_time_total = new float[gpu_info[i].SMCount];

        gpu_info[i].long_time = new float[gpu_info[i].SMCount * gpu_info[i].MaxThreadsBlock];
        gpu_info[i].long_time_total = new float[gpu_info[i].SMCount];

    }

    return 0;

}
