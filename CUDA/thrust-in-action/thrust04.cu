#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/copy.h>
#include <thrust/fill.h>

#include <iostream>

int main () {
    /**
     * Thrust support "raw" pointer used as an argument to a Thrust function.
     * But if the pointer in question is in fact a pointer to device memory,
     * it will need to be wraped with `thrust::device_ptr` before calling the function
     */

    size_t N = 10;

    // raw pointer to device memory
    int* raw_ptr;
    cudaMalloc( (void**) &raw_ptr, N * sizeof(int) );

    // wrap raw pointer with a device_ptr
    thrust::device_ptr<int> dev_ptr(raw_ptr);

    // use device_ptr in thrust algorithm
    thrust::fill(dev_ptr, dev_ptr + N, (int) 1);

    for (int i = 0; i < N; ++ i) {
        std::cout << "dev_ptr[" << i << "] = " << dev_ptr[i] << std::endl;
    }
    return 0;
}