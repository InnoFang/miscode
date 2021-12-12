/*
 * @FileName   : single_stream.cu 
 * @CreateAt   : 2021/12/12
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: Use single stream to calculate (A + B)/2
 */
#include <cstdio>

#define N (1024 * 1024) //每个流执行数据大小
#define FULL (N * 20)   // 全部数据大小

__global__
void kernel(int *a, int *b, int *c) {
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    if ( idx < N ) {
        c[idx] = (a[idx] + b[idx]) >> 1;
    }
}

int main() {
    // 查询设备属性
    cudaDeviceProp prop;
    int whichDevice;
    cudaGetDevice(&whichDevice);
    cudaGetDeviceProperties(&prop, whichDevice);
    if (!prop.deviceOverlap) {
        printf("Device will not support overlap\n");
        exit(1);
    }

    // 初始化计时器事件
    cudaEvent_t start, stop;
    float elapsedTime;
    cudaStream_t stream;
    int *host_a, *host_b, *host_c;
    int *dev_a, *dev_b, *dev_c;

    // 创建计时器
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    //初始化流
    cudaStreamCreate(&stream);

    // 在 GPU 端申请存储空间
    cudaMalloc( (void**)&dev_a, N * sizeof(int) );
    cudaMalloc( (void**)&dev_b, N * sizeof(int) );
    cudaMalloc( (void**)&dev_c, N * sizeof(int) );

    // 在 CPU 端申请存储空间，使用锁页内存
    cudaHostAlloc( (void**)&host_a, FULL * sizeof(int), cudaHostAllocDefault);
    cudaHostAlloc( (void**)&host_b, FULL * sizeof(int), cudaHostAllocDefault);
    cudaHostAlloc( (void**)&host_c, FULL * sizeof(int), cudaHostAllocDefault);

    // 初始化 A，B 向量
    for (int i = 0; i < FULL; ++ i) {
        host_a[i] = rand();
        host_b[i] = rand();
    }

    // 开始计算
    cudaEventRecord(start, 0);
    for (int i = 0; i < FULL; i += N) {
        // 将数据从 CPU 锁页内存中传输给 GPU 显存
        cudaMemcpyAsync(dev_a, host_a + i, N * sizeof(int), cudaMemcpyHostToDevice, stream);
        cudaMemcpyAsync(dev_b, host_b + i, N * sizeof(int), cudaMemcpyHostToDevice, stream);
        kernel<<< N + 256 - 1 / 256, 256, 0, stream>>>(dev_a, dev_b, dev_c);

        // 将计算结果从 GPU 显存中传输给 CPU 内存
        cudaMemcpyAsync(host_c + i, dev_c, N * sizeof(int), cudaMemcpyDeviceToHost, stream);
    }
    cudaStreamSynchronize(stream);
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&elapsedTime, start, stop);

    printf("Time: %3.1f ms\n", elapsedTime);

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
    cudaFreeHost(host_a);
    cudaFreeHost(host_b);
    cudaFreeHost(host_c);
    cudaStreamDestroy(stream);
    return 0;
}
