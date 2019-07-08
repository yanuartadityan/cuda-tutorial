#include <iostream>
#include <math.h>
#include "gpu_add.h"


__global__
void add(int n, float *x, float *y){
    for (int i=0; i<n; i++)
    y[i] = x[i] + y[i];
}

int add_wrapper(){
    // 1M elements
    int N = 1<<20;
    float *x, *y;

    cudaMallocManaged(&x, N*sizeof(float));
    cudaMallocManaged(&y, N*sizeof(float));

    // init x and y arrays
    for (int i=0; i<N; i++){
        x[i] = 1.0f;
        y[i] = 2.0f;
    }

    // run
    add<<<1, 1>>>(N, x, y);

    cudaDeviceSynchronize();

    // check for error
    float maxErr = 0.0f;
    for (int i=0; i<N; i++)
        maxErr = fmax(maxErr, fabs(y[i]-3.0f));

    std::cout << "Max error from GPU: " << maxErr << std::endl;

    cudaFree(x);
    cudaFree(y);

    // return and exit
    return 0;
}