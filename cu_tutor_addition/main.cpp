#include <iostream>
#include <math.h>
#include "gpu_add.h"

// function to multiply elements of two arrays
// void mul(int n, float *x, float *y){
//     for (int i=0; i<n; i++)
//         y[i] = x[i] + y[i];
// }

int main(void){
    // // 1M elements
    // int N = 1<<20;

    // float *x = new float[N];
    // float *y = new float[N];

    // // init x and y arrays
    // for (int i=0; i<N; i++){
    //     x[i] = 1.0f;
    //     y[i] = 2.0f;
    // }

    // // run
    // mul(N, x, y);

    // // check for error
    // float maxErr = 0.0f;
    // for (int i=0; i<N; i++)
    //     maxErr = fmax(maxErr, fabs(y[i]-3.0f));

    // std::cout << "Max error: " << maxErr << std::endl;

    // // free memory
    // delete [] x;
    // delete [] y;

    std::cout << "Entering GPU computation: " << std::endl;
    add_wrapper();

    // // return and exit
    return 0;
}