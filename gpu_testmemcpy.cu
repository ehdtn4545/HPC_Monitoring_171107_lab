#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

int MainWindow::GPU_TestMemcpy(int device) {

    int size = gpu_info[device].SMCount * gpu_info[device].MaxThreadsBlock;

    cudaSetDevice(device);

    cudaEvent_t event_start;
    cudaEvent_t event_end;

    host_arr_double = new double[size];
    host_arr_float = new float[size];
    host_arr_int = new int[size];
    host_arr_long = new long long[size];

    //cudaEvent_t event_start;
    //cudaEvent_t event_end;

    for (int i = 0; i < size; i++) {

        srand(time(NULL));
        host_arr_double[i] = (double)(rand() % 100) / (double)1000;

        srand(time(NULL));
        host_arr_float[i] = (float)(rand() % 100) / (float)1000;

        srand(time(NULL));
        host_arr_int[i] = rand() % 100;

        srand(time(NULL));
        host_arr_long[i] = rand() % 100;

    }

    double *device_arr_double;
    float *device_arr_float;
    int *device_arr_int;
    long long *device_arr_long;

    // Memcpy HostToDevice
    cudaMalloc((void **)&device_arr_double, sizeof(double) * size);
    cudaMalloc((void **)&device_arr_float, sizeof(float) * size);
    cudaMalloc((void **)&device_arr_int, sizeof(int) * size);
    cudaMalloc((void **)&device_arr_long, sizeof(long long) * size);

    cudaEventCreate(&event_start);
    cudaEventCreate(&event_end);
    cudaEventRecord(event_start, 0);

    for (int i = 0; i < 16; i++) {
        cudaMemcpy(device_arr_double, host_arr_double, sizeof(double) * size, cudaMemcpyHostToDevice);
        cudaMemcpy(device_arr_float, host_arr_float, sizeof(float) * size, cudaMemcpyHostToDevice);
        cudaMemcpy(device_arr_int, host_arr_int, sizeof(int) * size, cudaMemcpyHostToDevice);
        cudaMemcpy(device_arr_long, host_arr_long, sizeof(long long) * size, cudaMemcpyHostToDevice);
    }

    cudaEventRecord(event_end, 0);
    cudaEventSynchronize(event_end);
    cudaEventElapsedTime(&gpu_info[device].h2d_copy_time, event_start, event_end);
    cudaEventDestroy(event_start);
    cudaEventDestroy(event_end);


    // Memcpy DeviceToHost
    cudaEventCreate(&event_start);
    cudaEventCreate(&event_end);
    cudaEventRecord(event_start, 0);

    for (int i = 0; i < 16; i++) {
        cudaMemcpy(host_arr_double, device_arr_double, sizeof(double) * size, cudaMemcpyDeviceToHost);
        cudaMemcpy(host_arr_float, device_arr_float, sizeof(float) * size, cudaMemcpyDeviceToHost);
        cudaMemcpy(host_arr_int, device_arr_int, sizeof(int) * size, cudaMemcpyDeviceToHost);
        cudaMemcpy(host_arr_long, device_arr_long, sizeof(long long) * size, cudaMemcpyDeviceToHost);
    }

    cudaEventRecord(event_end, 0);
    cudaEventSynchronize(event_end);
    cudaEventElapsedTime(&gpu_info[device].d2h_copy_time, event_start, event_end);
    cudaEventDestroy(event_start);
    cudaEventDestroy(event_end);

    //cudaEventCreate(&event_start);
    //cudaEventCreate(&event_end);
    //cudaEventRecord(event_start, 0);

    float *host_g2s = new float[size];
    float *host_s2g = new float[size];
    float *host_s2r = new float[size];
    float *host_r2s = new float[size];
    float *host_g2r = new float[size];
    float *host_r2g = new float[size];
    for (int i = 0; i < size; i++) {
        host_g2s[i] = 0.0;
        host_s2g[i] = 0.0;
        host_s2r[i] = 0.0;
        host_r2s[i] = 0.0;
        host_g2r[i] = 0.0;
        host_r2g[i] = 0.0;
    }

    float *device_g2s;
    float *device_s2g;
    float *device_s2r;
    float *device_r2s;
    float *device_g2r;
    float *device_r2g;
    cudaMalloc((void **)&device_g2s, sizeof(float) * size);
    cudaMalloc((void **)&device_s2g, sizeof(float) * size);
    cudaMalloc((void **)&device_s2r, sizeof(float) * size);
    cudaMalloc((void **)&device_r2s, sizeof(float) * size);
    cudaMalloc((void **)&device_g2r, sizeof(float) * size);
    cudaMalloc((void **)&device_r2g, sizeof(float) * size);
    cudaMemcpy(device_g2s, host_g2s, sizeof(float) * size, cudaMemcpyHostToDevice);
    cudaMemcpy(device_s2g, host_s2g, sizeof(float) * size, cudaMemcpyHostToDevice);
    cudaMemcpy(device_s2r, host_s2r, sizeof(float) * size, cudaMemcpyHostToDevice);
    cudaMemcpy(device_r2s, host_r2s, sizeof(float) * size, cudaMemcpyHostToDevice);
    cudaMemcpy(device_g2r, host_g2r, sizeof(float) * size, cudaMemcpyHostToDevice);
    cudaMemcpy(device_r2g, host_r2g, sizeof(float) * size, cudaMemcpyHostToDevice);

    TestDeviceMemcpy <<< gpu_info[device].SMCount, gpu_info[device].MaxThreadsBlock >>> (device_arr_double, device_arr_float, device_arr_int, device_arr_long,
                                                                                         device_g2s, device_s2g, device_s2r, device_r2s, device_g2r, device_r2g, size);

    cudaMemcpy(host_g2s, device_g2s, sizeof(float) * size, cudaMemcpyDeviceToHost);
    cudaMemcpy(host_s2g, device_s2g, sizeof(float) * size, cudaMemcpyDeviceToHost);
    cudaMemcpy(host_s2r, device_s2r, sizeof(float) * size, cudaMemcpyDeviceToHost);
    cudaMemcpy(host_r2s, device_r2s, sizeof(float) * size, cudaMemcpyDeviceToHost);
    cudaMemcpy(host_g2r, device_g2r, sizeof(float) * size, cudaMemcpyDeviceToHost);
    cudaMemcpy(host_r2g, device_r2g, sizeof(float) * size, cudaMemcpyDeviceToHost);
    gpu_info[device].g2s_copy_time = 0.0;
    gpu_info[device].s2g_copy_time = 0.0;
    gpu_info[device].s2r_copy_time = 0.0;
    gpu_info[device].r2s_copy_time = 0.0;
    gpu_info[device].g2r_copy_time = 0.0;
    gpu_info[device].r2g_copy_time = 0.0;
    for (int i = 0; i < size; i++) {
        gpu_info[device].g2s_copy_time += host_g2s[i] / gpu_info[device].ClockRate;
        gpu_info[device].s2g_copy_time += host_s2g[i] / gpu_info[device].ClockRate;
        gpu_info[device].s2r_copy_time += host_s2r[i] / gpu_info[device].ClockRate;
        gpu_info[device].r2s_copy_time += host_r2s[i] / gpu_info[device].ClockRate;
        gpu_info[device].g2r_copy_time += host_g2r[i] / gpu_info[device].ClockRate;
        gpu_info[device].r2g_copy_time += host_r2g[i] / gpu_info[device].ClockRate;
    }
    //cudaEventRecord(event_end, 0);
    //cudaEventSynchronize(event_end);
    //cudaEventElapsedTime(&gpu_info[device].d2h_copy_time, event_start, event_end);
    //cudaEventDestroy(event_start);
    //cudaEventDestroy(event_end);

    delete[] host_arr_double;
    delete[] host_arr_float;
    delete[] host_arr_int;
    delete[] host_arr_long;
    delete[] host_g2s;
    delete[] host_s2g;
    delete[] host_s2r;
    delete[] host_r2s;
    delete[] host_g2r;
    delete[] host_r2g;
    cudaFree(device_arr_double);
    cudaFree(device_arr_float);
    cudaFree(device_arr_int);
    cudaFree(device_arr_long);
    cudaFree(device_g2s);
    cudaFree(device_s2g);
    cudaFree(device_s2r);
    cudaFree(device_r2s);
    cudaFree(device_g2r);
    cudaFree(device_r2g);

    return 0;

}
