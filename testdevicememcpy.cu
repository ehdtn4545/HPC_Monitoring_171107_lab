#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

__global__ void TestDeviceMemcpy(double *d_arr_double, float *d_arr_float, int *d_arr_int, long long *d_arr_long,
                                 float *time_g2s, float *time_s2g, float *time_s2r, float *time_r2s, float *time_g2r, float *time_r2g,
                                 int size) {

    int xid = blockIdx.x * blockDim.x + threadIdx.x;

    __shared__ double s_arr_double[1024];
    __shared__ float s_arr_float[1024];
    __shared__ int s_arr_int[1024];
    __shared__ long long s_arr_long[1024];

    double r_arr_double;
    float r_arr_float;
    int r_arr_int;
    long long r_arr_long;

    if (xid < size) {

        // g2s
        clock_t start = clock();
        for (int i = 0; i < 256; i++) {
            s_arr_double[threadIdx.x] = d_arr_double[xid];
            s_arr_float[threadIdx.x] = d_arr_float[xid];
            s_arr_int[threadIdx.x] = d_arr_int[xid];
            s_arr_long[threadIdx.x] = d_arr_long[xid];
        }
        clock_t end = clock();
        time_g2s[xid] = (float)(end - start);

        // s2g
        start = clock();
        for (int i = 0; i < 256; i++) {
            d_arr_double[xid] = s_arr_double[threadIdx.x];
            d_arr_float[xid] = s_arr_float[threadIdx.x];
            d_arr_int[xid] = s_arr_int[threadIdx.x];
            d_arr_long[xid] = s_arr_long[threadIdx.x];
        }
        end = clock();
        time_s2g[xid] = (float)(end - start);

        // s2r
        start = clock();
        for (int i = 0; i < 256; i++) {
            r_arr_double = s_arr_double[threadIdx.x];
            r_arr_float = s_arr_float[threadIdx.x];
            r_arr_int = s_arr_int[threadIdx.x];
            r_arr_long = s_arr_long[threadIdx.x];
        }
        end = clock();
        time_s2r[xid] = (float)(end - start);

        // r2s
        start = clock();
        for (int i = 0; i < 256; i++) {
            s_arr_double[threadIdx.x] = r_arr_double;
            s_arr_float[threadIdx.x] = r_arr_float;
            s_arr_int[threadIdx.x] = r_arr_int;
            s_arr_long[threadIdx.x] = r_arr_long;
        }
        end = clock();
        time_r2s[xid] = (float)(end - start);

        // g2r
        start = clock();
        for (int i = 0; i < 256; i++) {
            r_arr_double = d_arr_double[xid];
            r_arr_float = d_arr_float[xid];
            r_arr_int = d_arr_int[xid];
            r_arr_long = d_arr_long[xid];
        }
        end = clock();
        time_g2r[xid] = (float)(end - start);

        // r2g
        start = clock();
        for (int i = 0; i < 256; i++) {
            d_arr_double[xid] = r_arr_double;
            d_arr_float[xid] = r_arr_float;
            d_arr_int[xid] = r_arr_int;
            d_arr_long[xid] = r_arr_long;
        }
        end = clock();
        time_r2g[xid] = (float)(end - start);

    }

}
