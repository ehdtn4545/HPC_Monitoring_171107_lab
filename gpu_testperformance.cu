#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::GPU_TestPerformance(int device, int type) {

    int size = gpu_info[device].SMCount * gpu_info[device].MaxThreadsBlock;

    cudaSetDevice(device);

    if (type == 0) {

        host_arr_double = new double[size];

        for (int i = 0; i < size; i++) {
            srand(time(NULL));
            host_arr_double[i] = (double)(rand() % 100) / (double)1000;
        }

        double *device_arr_double;
        cudaMalloc((void **)&device_arr_double, sizeof(double) * size);
        cudaMemcpy(device_arr_double, host_arr_double, sizeof(double) * size, cudaMemcpyHostToDevice);

        float *device_double_time;
        cudaMalloc((void **)&device_double_time, sizeof(float) * size);

        TestDouble <<< gpu_info[device].SMCount, gpu_info[device].MaxThreadsBlock >>> (device_arr_double, device_double_time, size);

        cudaMemcpy(gpu_info[device].double_time, device_double_time, sizeof(float) * size, cudaMemcpyDeviceToHost);

        for (int i = 0; i < gpu_info[device].SMCount; i++) {
            gpu_info[device].double_time_total[i] = 0.0;
            for (int j = 0; j < gpu_info[device].MaxThreadsBlock; j++) {
                gpu_info[device].double_time_total[i] += (gpu_info[device].double_time[i * gpu_info[device].MaxThreadsBlock + j]) / gpu_info[device].ClockRate;
            }
        }

        delete[] host_arr_double;
        cudaFree(device_arr_double);
        cudaFree(device_double_time);

    } else if (type == 1) {

        host_arr_float = new float[size];

        for (int i = 0; i < size; i++) {
            srand(time(NULL));
            host_arr_float[i] = (float)(rand() % 100) / (float)1000;
        }

        float *device_arr_float;
        cudaMalloc((void **)&device_arr_float, sizeof(float) * size);
        cudaMemcpy(device_arr_float, host_arr_float, sizeof(float) * size, cudaMemcpyHostToDevice);

        float *device_float_time;
        cudaMalloc((void **)&device_float_time, sizeof(float) * size);

        TestSingle <<< gpu_info[device].SMCount, gpu_info[device].MaxThreadsBlock >>> (device_arr_float, device_float_time, size);

        cudaMemcpy(gpu_info[device].float_time, device_float_time, sizeof(float) * size, cudaMemcpyDeviceToHost);

        for (int i = 0; i < gpu_info[device].SMCount; i++) {
            gpu_info[device].float_time_total[i] = 0.0;
            for (int j = 0; j < gpu_info[device].MaxThreadsBlock; j++) {
                gpu_info[device].float_time_total[i] += (gpu_info[device].float_time[i * gpu_info[device].MaxThreadsBlock + j]) / gpu_info[device].ClockRate;
            }
        }

        delete[] host_arr_float;
        cudaFree(device_arr_float);
        cudaFree(device_float_time);

    } else if (type == 2) {

        host_arr_int = new int[size];

        for (int i = 0; i < size; i++) {
            srand(time(NULL));
            host_arr_int[i] = rand() % 100;
        }

        int *device_arr_int;
        cudaMalloc((void **)&device_arr_int, sizeof(int) * size);
        cudaMemcpy(device_arr_int, host_arr_int, sizeof(int) * size, cudaMemcpyHostToDevice);

        float *device_int_time;
        cudaMalloc((void **)&device_int_time, sizeof(float) * size);

        TestInt <<< gpu_info[device].SMCount, gpu_info[device].MaxThreadsBlock >>> (device_arr_int, device_int_time, size);

        cudaMemcpy(gpu_info[device].int_time, device_int_time, sizeof(float) * size, cudaMemcpyDeviceToHost);

        for (int i = 0; i < gpu_info[device].SMCount; i++) {
            gpu_info[device].int_time_total[i] = 0.0;
            for (int j = 0; j < gpu_info[device].MaxThreadsBlock; j++) {
                gpu_info[device].int_time_total[i] += (gpu_info[device].int_time[i * gpu_info[device].MaxThreadsBlock + j]) / gpu_info[device].ClockRate;
            }
        }

        delete[] host_arr_int;
        cudaFree(device_arr_int);
        cudaFree(device_int_time);

    } else if (type == 3) {

        host_arr_long = new long long[size];

        for (int i = 0; i < size; i++) {
            srand(time(NULL));
            host_arr_long[i] = rand() % 100;
        }

        long long *device_arr_long;
        cudaMalloc((void **)&device_arr_long, sizeof(long long) * size);
        cudaMemcpy(device_arr_long, host_arr_long, sizeof(long long) * size, cudaMemcpyHostToDevice);

        float *device_long_time;
        cudaMalloc((void **)&device_long_time, sizeof(float) * size);

        TestLong <<< gpu_info[device].SMCount, gpu_info[device].MaxThreadsBlock >>> (device_arr_long, device_long_time, size);

        cudaMemcpy(gpu_info[device].long_time, device_long_time, sizeof(float) * size, cudaMemcpyDeviceToHost);

        for (int i = 0; i < gpu_info[device].SMCount; i++) {
            gpu_info[device].long_time_total[i] = 0.0;
            for (int j = 0; j < gpu_info[device].MaxThreadsBlock; j++) {
                gpu_info[device].long_time_total[i] += (gpu_info[device].long_time[i * gpu_info[device].MaxThreadsBlock + j]) / gpu_info[device].ClockRate;
            }
        }

        delete[] host_arr_long;
        cudaFree(device_arr_long);
        cudaFree(device_long_time);

    }

    return 0;

}
