/*
 * @FileName   : basis.cu 
 * @CreateAt   : 2021/12/6
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: 
 */
#include <iostream>

#include <cuda.h>
#include <cuda_runtime.h>

#define N (1024 * 1024)
#define FULL (N * 20)

/* (A + B) / 2 = C */
__global__
void kernel(int *a, int *b, int *c) {
   int index = threadIdx.x + blockDim.x * blockIdx.x;
   if (index < N) {
       c[index] = (a[index] + b[index]) >> 1;
   }
}

int main() {
    cudaDeviceProp prop;
    int whichDevice;

    // 获取设备编号
    cudaGetDevice(&whichDevice);
    // 获取设备属性
    cudaGetDeviceProperties(&prop, whichDevice);

    if (!prop.deviceOverlap) { // 判断GPU是否支持多流计算
        std::cout << "Device will not support overlap" << std::endl;
    }

    // 初始化计时器事件
    cudaEvent_t start, stop;
    float elapsedTime;

    // 声明流和GPU Buffer的指针
    cudaStream_t stream0, stream1;
    int *host_a, *host_b, *host_c;
    int *dev_a0, *dev_b0, *dev_c0,
    int *dev_a1, *dev_b1, *dev_c1;

    // 创建计时器
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // 初始化流
    cudaStreamCreate(&stream0);
    cudaStreamCreate(&stream1);

    // 在GPU端申请存储空间
    cudaMalloc( (void**)&dev_a0, N * sizeof(int) );
    cudaMalloc( (void**)&dev_b0, N * sizeof(int) );
    cudaMalloc( (void**)&dev_c0, N * sizeof(int) );
    cudaMalloc( (void**)&dev_a1, N * sizeof(int) );
    cudaMalloc( (void**)&dev_b1, N * sizeof(int) );
    cudaMalloc( (void**)&dev_c1, N * sizeof(int) );

    // 在CPU端申请内存空间，要用到锁页内存(page-locked memory)
    cudaHostAlloc( (void**)&host_a, FULL * sizeof(int), cudaHostAllocDefault);
    cudaHostAlloc( (void**)&host_b, FULL * sizeof(int), cudaHostAllocDefault);
    cudaHostAlloc( (void**)&host_c, FULL * sizeof(int), cudaHostAllocDefault);

    // 初始化A、B向量
    for (size_t i = 0; i < FULL; ++i) {
        host_a[i] = rand();
        host_b[i] = rand();
    }

    // 开始计算
    cudaEventRecord(start, 0);
    for (size_t i= 0; i < FULL; i += 2 * N) {
        // 将数据从CPU内存中传输到GPU显存中
        cudaMemcpyAsync(dev_a0, host_a + i, N * sizeof(int), cudaMemcpyHostToDevice, stream0);
        cudaMemcpyAsync(dev_b0, host_b + i, N * sizeof(int), cudaMemcpyHostToDevice, stream0);
        cudaMemcpyAsync(dev_a1, host_a + i + N, N * sizeof(int), cudaMemcpyHostToDevice, stream1);
        cudaMemcpyAsync(dev_b1, host_b + i + N, N * sizeof(int), cudaMemcpyHostToDevice, stream1);

        kernel<<<N / 256, 256, 0, stream0>>>(dev_a0, dev_b0, dev_c0);
        kernel<<<N / 256, 256, 0, stream1>>>(dev_a1, dev_b1, dev_c1);

        cudaMemcpyAsync(host_c + i, dev_c0, N * sizeof(int), cudaMemcpyDeviceToHost, stream0);
        cudaMemcpyAsync(host_c + i + N, dev_c1, N * sizeof(int), cudaMemcpyDeviceToHost, stream1);
    }

    cudaStreamSynchronize(stream0);
    cudaStreamSynchronize(stream1);

    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&elapsedTime, start, stop);
    printf("Time: %3.1f ms\n", elapsedTime);

    cudaFree(dev_a0);
    cudaFree(dev_b0);
    cudaFree(dev_c0);
    cudaFree(dev_a1);
    cudaFree(dev_b1);
    cudaFree(dev_c1);

    cudaFreeHost(host_a);
    cudaFreeHost(host_b);
    cudaFreeHost(host_c);

    cudaStreamDestroy(stream0);
    cudaStreamDestroy(stream1);

    return 0;
}

